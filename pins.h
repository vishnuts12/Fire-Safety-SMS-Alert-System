/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : pins.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Defines all Arduino UNO pin assignments.
 *
 ******************************************************************************/

#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

/**************************************************************************
 * LCD Pins
 **************************************************************************/

constexpr uint8_t PIN_LCD_RS = 7;
constexpr uint8_t PIN_LCD_EN = 8;
constexpr uint8_t PIN_LCD_D4 = 9;
constexpr uint8_t PIN_LCD_D5 = 10;
constexpr uint8_t PIN_LCD_D6 = 11;
constexpr uint8_t PIN_LCD_D7 = 12;

/**************************************************************************
 * SIM800L GSM Module
 **************************************************************************/

constexpr uint8_t PIN_GSM_RX = 2;   // Arduino receives from SIM800L TX
constexpr uint8_t PIN_GSM_TX = 3;   // Arduino transmits to SIM800L RX

/**************************************************************************
 * Status LEDs
 **************************************************************************/

constexpr uint8_t PIN_POWER_LED = 4;
constexpr uint8_t PIN_GSM_LED   = 5;
constexpr uint8_t PIN_FAULT_LED = 6;

/**************************************************************************
 * Pump Inputs
 **************************************************************************/

constexpr uint8_t PIN_HYDRANT_JOCKEY    = A0;
constexpr uint8_t PIN_SPRINKLER_JOCKEY  = A1;
constexpr uint8_t PIN_HYDRANT_MAIN      = A2;
constexpr uint8_t PIN_SPRINKLER_MAIN    = A3;
constexpr uint8_t PIN_DIESEL_PUMP       = A4;

/**************************************************************************
 * Test Button
 **************************************************************************/

constexpr uint8_t PIN_TEST_BUTTON = A5;

#endif // PINS_H
