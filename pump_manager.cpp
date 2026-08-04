/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : pump_manager.cpp
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Implements pump monitoring functions.
 *
 ******************************************************************************/

#include "pump_manager.h"

#include "pins.h"
#include "config.h"
#include "hardware.h"
#include "messages.h"

static PumpState currentPumpState[5];
static PumpState previousPumpState[5];

static const uint8_t pumpPins[NUMBER_OF_PUMPS] =
{
    PIN_HYDRANT_JOCKEY,
    PIN_SPRINKLER_JOCKEY,
    PIN_HYDRANT_MAIN,
    PIN_SPRINKLER_MAIN,
    PIN_DIESEL_PUMP
};

static PumpState readPumpState(uint8_t pumpIndex)
{
    bool inputState = digitalRead(pumpPins[pumpIndex]);

    if (PUMP_CONTACT_TYPE[pumpIndex] == ContactType::NO)
    {
        return inputState ? PumpState::ON
                          : PumpState::OFF;
    }

    return inputState ? PumpState::OFF
                      : PumpState::ON;
}

void initializePumpManager()
{
    for (uint8_t i = 0; i < NUMBER_OF_PUMPS; i++)
    {
        PumpState state = readPumpState(i);

        currentPumpState[i] = state;
        previousPumpState[i] = state;
    }
}

void updatePumpStates()
{
    for (uint8_t i = 0; i < NUMBER_OF_PUMPS; i++)
    {
        previousPumpState[i] = currentPumpState[i];
        currentPumpState[i] = readPumpState(i);
    }
}

PumpState getPumpState(PumpID pump)
{
    return currentPumpState[(uint8_t)pump];
}

bool hasPumpStateChanged(PumpID pump)
{
    return currentPumpState[(uint8_t)pump] !=
           previousPumpState[(uint8_t)pump];
}

bool pumpStarted(PumpID pump)
{
    uint8_t index = static_cast<uint8_t>(pump);

    return (previousPumpState[index] == PumpState::OFF) &&
           (currentPumpState[index] == PumpState::ON);
}

bool pumpStopped(PumpID pump)
{
    uint8_t index = static_cast<uint8_t>(pump);

    return (previousPumpState[index] == PumpState::ON) &&
           (currentPumpState[index] == PumpState::OFF);
}

const char* getPumpName(PumpID pump)
{
    uint8_t index = static_cast<uint8_t>(pump);

    if (index < NUMBER_OF_PUMPS)
    {
        return PUMP_NAMES[index];
    }

    return MSG_UNKNOWN_PUMP;
}