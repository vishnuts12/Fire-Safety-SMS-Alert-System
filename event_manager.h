/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : event_manager.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Processes pump events and coordinates
 * LCD and GSM notifications.
 *
 ******************************************************************************/

#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <Arduino.h>

//--------------------------------------------------
// Initialization
//--------------------------------------------------

void initializeEventManager();

//--------------------------------------------------
// Event Processing
//--------------------------------------------------

void processPumpEvents();

#endif // EVENT_MANAGER_H