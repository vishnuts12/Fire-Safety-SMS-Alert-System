/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : hardware.cpp
 *
 ******************************************************************************/

#include "hardware.h"

#include "pins.h"

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
