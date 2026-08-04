/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : messages.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Contains all user-visible text messages used by the firmware.
 *
 ******************************************************************************/

#ifndef MESSAGES_H
#define MESSAGES_H

#include <Arduino.h>

/**************************************************************************
 * Startup Messages
 **************************************************************************/

constexpr char MSG_INITIALIZING[]  = "Initializing";
constexpr char MSG_SYSTEM_READY[]  = "System Ready";

/**************************************************************************
 * GSM Messages
 **************************************************************************/

constexpr char MSG_GSM_INIT[]      = "Initializing";
constexpr char MSG_GSM_MODULE[]    = "GSM Module";
constexpr char MSG_GSM_READY[]     = "GSM Ready";
constexpr char MSG_CHECK_SIGNAL[]  = "Checking Signal";
constexpr char MSG_CHECK_NETWORK[] = "Checking Network";
constexpr char MSG_NETWORK_OK[]    = "Network OK";
constexpr char MSG_SENDING_SMS[]   = "Sending SMS";
constexpr char MSG_SMS_SENT[]      = "SMS Sent";
constexpr char MSG_SMS_FAILED[]    = "SMS Failed";

/**************************************************************************
 * Pump Names
 **************************************************************************/

constexpr const char* PUMP_NAMES[NUMBER_OF_PUMPS] =
{
    "Hydrant Jockey",
    "Sprinkler Jockey",
    "Hydrant Main",
    "Sprinkler Main",
    "Diesel Pump"
};

/**************************************************************************
 * Pump Messages
 **************************************************************************/

constexpr char MSG_PUMP_STARTED[]  = "Pump Started";
constexpr char MSG_PUMP_STOPPED[]  = "Pump Stopped";
constexpr char MSG_MONITORING[]    = "Monitoring";

/**************************************************************************
 * Fault Messages
 **************************************************************************/

constexpr char MSG_FAULT[]         = "FAULT";
constexpr char MSG_GSM_FAILURE[]   = "GSM Failure";
constexpr char MSG_LCD_FAILURE[]   = "LCD Failure";
constexpr char MSG_INPUT_FAILURE[] = "Input Failure";
constexpr char MSG_UNKNOWN_PUMP[]  = "Unknown Pump";

#endif // MESSAGES_H
