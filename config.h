/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : config.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Project-specific configuration.
 *
 ******************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include "version.h"
#include "types.h"
#include "constants.h"

/**************************************************************************
 * Project Information
 **************************************************************************/

constexpr char PROJECT_NAME[] = "Fire Safety SMS Alert System";

constexpr char INSTALLATION_NAME[] = "H-Block";

constexpr char ORGANIZATION_NAME[] = "Hospital";

/**************************************************************************
 * SMS Recipients
 **************************************************************************/

constexpr char FIRE_SAFETY_CHIEF[] = "+91XXXXXXXXXX";

constexpr char DUTY_STAFF[] = "+91XXXXXXXXXX";

/**************************************************************************
 * Pump Contact Configuration
 **************************************************************************/

constexpr ContactType PUMP_CONTACT_TYPE[NUMBER_OF_PUMPS] =
{
    ContactType::NO,   // Hydrant Jockey

    ContactType::NO,   // Sprinkler Jockey

    ContactType::NC,   // Hydrant Main

    ContactType::NO,   // Sprinkler Main

    ContactType::NC    // Diesel Pump
};

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
 * Feature Configuration
 **************************************************************************/

constexpr bool ENABLE_STARTUP_SMS = true;

constexpr bool ENABLE_EVENT_LOG = true;

constexpr bool ENABLE_HEARTBEAT_LED = true;

constexpr bool ENABLE_SELF_TEST = true;

#endif // CONFIG_H