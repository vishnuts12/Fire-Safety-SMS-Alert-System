/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : pump_manager.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Handles monitoring of all fire pump inputs.
 *
 ******************************************************************************/

#ifndef PUMP_MANAGER_H
#define PUMP_MANAGER_H

#include <Arduino.h>
#include "types.h"

//--------------------------------------------------
// Initialization
//--------------------------------------------------

void initializePumpManager();

//--------------------------------------------------
// Pump Monitoring
//--------------------------------------------------

void updatePumpStates();

//--------------------------------------------------
// Access Functions
//--------------------------------------------------

PumpState getPumpState(PumpID pump);

bool hasPumpStateChanged(PumpID pump);

bool pumpStarted(PumpID pump);

bool pumpStopped(PumpID pump);

const char* getPumpName(PumpID pump);

#endif // PUMP_MANAGER_H
