/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : constants.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Defines project-wide constants.
 *
 ******************************************************************************/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>

/**************************************************************************
 * System Timing (milliseconds)
 **************************************************************************/

constexpr unsigned long HEARTBEAT_INTERVAL_MS = 1000UL;
constexpr unsigned long LCD_REFRESH_INTERVAL_MS = 1000UL;
constexpr unsigned long INPUT_SCAN_INTERVAL_MS = 100UL;
constexpr unsigned long GSM_STARTUP_DELAY_MS = 5000UL;
constexpr unsigned long SMS_SEND_TIMEOUT_MS = 30000UL;
constexpr unsigned long DEBOUNCE_TIME_MS = 50UL;

/**************************************************************************
 * Event Logger
 **************************************************************************/

constexpr uint16_t MAX_EVENT_LOGS = 100;

/**************************************************************************
 * GSM Settings
 **************************************************************************/

constexpr uint8_t GSM_MAX_RETRY = 3;

/**************************************************************************
 * Pump Configuration
 **************************************************************************/

constexpr uint8_t NUMBER_OF_PUMPS = 5;

/**************************************************************************
 * LCD Configuration
 **************************************************************************/

constexpr uint8_t LCD_COLUMNS = 16;
constexpr uint8_t LCD_ROWS = 4;

#endif // CONSTANTS_H
