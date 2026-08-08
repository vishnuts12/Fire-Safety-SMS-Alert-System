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

constexpr const char* SMS_RECIPIENTS[] =
{
    "+918848488050",   // Fire Safety Chief
    "+919037009939"    // Duty Staff
};

constexpr uint8_t NUMBER_OF_SMS_RECIPIENTS =
    sizeof(SMS_RECIPIENTS) / sizeof(SMS_RECIPIENTS[0]);

/**************************************************************************
 * Pump Contact Configuration
 **************************************************************************/

constexpr ContactType PUMP_CONTACT_TYPE[NUMBER_OF_PUMPS] =
{
    ContactType::NO,   // Hydrant Jockey

    ContactType::NO,   // Sprinkler Jockey

    ContactType::NO,   // Hydrant Main

    ContactType::NO,   // Sprinkler Main

    ContactType::NO    // Diesel Pump
};

/**************************************************************************
 * Feature Configuration
 **************************************************************************/

constexpr bool ENABLE_STARTUP_SMS = true;

constexpr bool ENABLE_EVENT_LOG = true;

constexpr bool ENABLE_HEARTBEAT_LED = true;

constexpr bool ENABLE_SELF_TEST = true;

#endif // CONFIG_H