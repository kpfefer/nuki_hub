#pragma once

#define mqtt_topic_battery_level "/battery/level"
#define mqtt_topic_battery_critical "/battery/critical"
#define mqtt_topic_battery_charging "/battery/charging"
#define mqtt_topic_battery_voltage "/battery/voltage"
#define mqtt_topic_battery_drain "/battery/drain"
#define mqtt_topic_battery_max_turn_current "/battery/maxTurnCurrent"
#define mqtt_topic_battery_lock_distance "/battery/lockDistance"

#define mqtt_topic_lock_state "/lock/state"
#define mqtt_topic_lock_binary_state "/lock/binaryState"
#define mqtt_topic_lock_trigger "/lock/trigger"
#define mqtt_topic_lock_log "/lock/log"
#define mqtt_topic_lock_auth_id "/lock/authorizationId"
#define mqtt_topic_lock_auth_name "/lock/authorizationName"
#define mqtt_topic_lock_completionStatus "/lock/completionStatus"
#define mqtt_topic_lock_action_command_result "/lock/commandResult"
#define mqtt_topic_lock_door_sensor_state "/lock/doorSensorState"
#define mqtt_topic_lock_action "/lock/action"
#define mqtt_topic_lock_rssi "/lock/rssi"

#define mqtt_topic_config_button_enabled "/configuration/buttonEnabled"
#define mqtt_topic_config_led_enabled "/configuration/ledEnabled"
#define mqtt_topic_config_led_brightness "/configuration/ledBrightness"
#define mqtt_topic_config_auto_unlock "/configuration/autoUnlock"
#define mqtt_topic_config_auto_lock "/configuration/autoLock"
#define mqtt_topic_config_single_lock "/configuration/singleLock"
#define mqtt_topic_config_sound_level "/configuration/soundLevel"

#define mqtt_topic_keypad "/keypad"
#define mqtt_topic_keypad_command_action "/keypad/command/action"
#define mqtt_topic_keypad_command_id "/keypad/command/id"
#define mqtt_topic_keypad_command_name "/keypad/command/name"
#define mqtt_topic_keypad_command_code "/keypad/command/code"
#define mqtt_topic_keypad_command_enabled "/keypad/command/enabled"
#define mqtt_topic_keypad_command_result "/keypad/command/commandResult"

#define mqtt_topic_presence "/presence/devices"

#define mqtt_topic_reset "/maintenance/reset"
#define mqtt_topic_uptime "/maintenance/uptime"
#define mqtt_topic_wifi_rssi "/maintenance/wifiRssi"
#define mqtt_topic_freeheap "/maintenance/freeHeap"