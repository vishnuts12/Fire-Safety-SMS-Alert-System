#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h> //Standard Arduino Libraries

//Project Information
constexpr char PROJECT_NAME[] = "Fire Safety SMS Alert";
constexpr char HOSPITAL_NAME[] = "H-BLOCK";

//defining Version 1.0.0
#include "version.h"

//Pump Inputs
constexpr uint8_t PIN_HJ = 2;
constexpr uint8_t PIN_SJ = 3;
constexpr uint8_t PIN_HM = 4;
constexpr uint8_t PIN_SM = 5;
constexpr uint8_t PIN_DP = 6;

//Test Button
constexpr uint8_t PIN_TEST = 7;

// SIM800L
constexpr uint8_t PIN_SIM_TX = 8;
constexpr uint8_t PIN_SIM_RX = 9;

// LEDs
constexpr uint8_t PIN_LED_POWER = 10;
constexpr uint8_t PIN_LED_GSM = 11;
constexpr uint8_t PIN_LED_FAULT = A4;

// LCD
constexpr uint8_t PIN_LCD_RS = 12;
constexpr uint8_t PIN_LCD_EN = 13;
constexpr uint8_t PIN_LCD_D4 = A0;
constexpr uint8_t PIN_LCD_D5 = A1;
constexpr uint8_t PIN_LCD_D6 = A2;
constexpr uint8_t PIN_LCD_D7 = A3;

//Enumerations
enum class PumpState
{
    OFF,
    ON
};

enum class ContactType
{
    NO,
    NC
};

enum class FaultCode
{
    None,
    LCD,
    GSM,
    SIM,
    Network,
    SMS,
    EEPROM,
    Unknown
};

//Timing constants
constexpr unsigned long HEARTBEAT_INTERVAL_MS = 5000;
constexpr unsigned long LCD_PAGE_INTERVAL_MS = 5000;
constexpr unsigned long BUTTON_HOLD_TIME_MS = 3000;
constexpr unsigned long GSM_STARTUP_TIMEOUT_MS = 30000;

//Feature Flags
constexpr bool ENABLE_GSM = true;
constexpr bool ENABLE_EVENT_LOG = true;
constexpr bool ENABLE_MAINTENANCE = true;
constexpr bool ENABLE_HEARTBEAT = true;
constexpr bool ENABLE_STARTUP_SMS = true;

#endif