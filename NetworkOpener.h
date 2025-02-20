#pragma once

#include <PubSubClient.h>
#include "networkDevices/NetworkDevice.h"
#include "networkDevices/WifiDevice.h"
#include "networkDevices/W5500Device.h"
#include <Preferences.h>
#include <vector>
#include "NukiConstants.h"
#include "NukiOpenerConstants.h"
#include "NetworkLock.h"

class NetworkOpener : public MqttReceiver
{
public:
    explicit NetworkOpener(Network* network, Preferences* preferences);
    virtual ~NetworkOpener() = default;

    void initialize();
    void update();

    void publishKeyTurnerState(const NukiOpener::OpenerState& keyTurnerState, const NukiOpener::OpenerState& lastKeyTurnerState);
    void publishRing();
    void publishBinaryState(NukiOpener::LockState lockState);
    void publishAuthorizationInfo(const std::list<NukiOpener::LogEntry>& logEntries);
    void clearAuthorizationInfo();
    void publishCommandResult(const char* resultStr);
    void publishBatteryReport(const NukiOpener::BatteryReport& batteryReport);
    void publishConfig(const NukiOpener::Config& config);
    void publishAdvancedConfig(const NukiOpener::AdvancedConfig& config);
    void publishRssi(const int& rssi);
    void publishHASSConfig(char* deviceType, const char* baseTopic, char* name, char* uidString, char* lockAction, char* unlockAction, char* openAction, char* lockedState, char* unlockedState);
    void removeHASSConfig(char* uidString);

    void setLockActionReceivedCallback(bool (*lockActionReceivedCallback)(const char* value));
    void setConfigUpdateReceivedCallback(void (*configUpdateReceivedCallback)(const char* path, const char* value));

    void onMqttDataReceived(char*& topic, byte*& payload, unsigned int& length) override;

private:
    bool comparePrefixedPath(const char* fullPath, const char* subPath);

    void publishFloat(const char* topic, const float value, const uint8_t precision = 2);
    void publishInt(const char* topic, const int value);
    void publishUInt(const char* topic, const unsigned int value);
    void publishBool(const char* topic, const bool value);
    void publishString(const char* topic, const char* value);

    void buildMqttPath(const char* path, char* outPath);
    void subscribe(const char* path);
    void logactionCompletionStatusToString(uint8_t value, char* out);

    Preferences* _preferences;

    Network* _network = nullptr;

    char _mqttPath[181] = {0};
    bool _isConnected = false;

    std::vector<char*> _configTopics;

    bool _firstTunerStatePublish = true;
    bool _haEnabled= false;
    unsigned long _resetLockStateTs = 0;

    bool (*_lockActionReceivedCallback)(const char* value) = nullptr;
    void (*_configUpdateReceivedCallback)(const char* path, const char* value) = nullptr;
};
