/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : gsm_manager.h
 *
 ******************************************************************************/

#ifndef GSM_MANAGER_H
#define GSM_MANAGER_H

#include <Arduino.h>

bool initializeGSM();

bool sendATCommand(const char* command,
                   const char* expectedResponse,
                   unsigned long timeout);

bool sendSMS(const char* phoneNumber,
             const char* message);

bool isNetworkReady();

#endif // GSM_MANAGER_H
