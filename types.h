/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : types.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Defines the data types used throughout the firmware.
 *
 ******************************************************************************/

#ifndef TYPES_H
#define TYPES_H

#include <Arduino.h>

//Enumerations

enum class PumpState
{
    OFF,
    ON,
    UNKNOWN
};

enum class ContactType
{
    NO,
    NC
};

enum class FaultCode
{
    NONE,
    GSM_FAILURE,
    LCD_FAILURE,
    EEPROM_FAILURE,
    INPUT_FAILURE
};

enum class PumpID
{
    HydrantJockey,
    SprinklerJockey,
    HydrantMain,
    SprinklerMain,
    DieselPump
};

enum class SystemMode
{
    Startup,
    Normal,
    Maintenance,
    Test,
    Fault
};

#endif // TYPES_H