/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : hardware.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Hardware abstraction layer.
 *
 ******************************************************************************/

#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>

/**************************************************************************
 * Hardware Initialization
 **************************************************************************/

void initializeHardware();

/**************************************************************************
 * LED Control
 **************************************************************************/

void setPowerLED(bool state);
void setGSMLed(bool state);
void setFaultLED(bool state);

void blinkLED(uint8_t pin,
              uint8_t times,
              uint16_t delayTime = 150);

#endif // HARDWARE_H