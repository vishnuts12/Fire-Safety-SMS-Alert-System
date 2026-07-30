/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : hardware.cpp
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Hardware abstraction layer implementation.
 *
 ******************************************************************************/

#include "hardware.h"

#include "pins.h"

/**************************************************************************
 * Hardware Initialization
 **************************************************************************/

void initializeHardware()
{
    /***********************
     * Pump Inputs
     ***********************/

    pinMode(PIN_HYDRANT_JOCKEY, INPUT_PULLUP);
    pinMode(PIN_SPRINKLER_JOCKEY, INPUT_PULLUP);
    pinMode(PIN_HYDRANT_MAIN, INPUT_PULLUP);
    pinMode(PIN_SPRINKLER_MAIN, INPUT_PULLUP);
    pinMode(PIN_DIESEL_PUMP, INPUT_PULLUP);

    /***********************
     * LEDs
     ***********************/

    pinMode(PIN_POWER_LED, OUTPUT);
    pinMode(PIN_GSM_LED, OUTPUT);
    pinMode(PIN_FAULT_LED, OUTPUT);

    digitalWrite(PIN_POWER_LED, HIGH);
    digitalWrite(PIN_GSM_LED, LOW);
    digitalWrite(PIN_FAULT_LED, LOW);

    /***********************
     * Test Button
     ***********************/

    pinMode(PIN_TEST_BUTTON, INPUT_PULLUP);
}

/**************************************************************************
 * LED Control
 **************************************************************************/

void setPowerLED(bool state)
{
    digitalWrite(PIN_POWER_LED, state);
}

void setGSMLed(bool state)
{
    digitalWrite(PIN_GSM_LED, state);
}

void setFaultLED(bool state)
{
    digitalWrite(PIN_FAULT_LED, state);
}

void blinkLED(uint8_t pin,
              uint8_t times,
              uint16_t delayTime)
{
    for (uint8_t i = 0; i < times; i++)
    {
        digitalWrite(pin, HIGH);
        delay(delayTime);

        digitalWrite(pin, LOW);
        delay(delayTime);
    }
}