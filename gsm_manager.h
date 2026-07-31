/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : gsm_manager.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * GSM Manager Layer
 *
 ******************************************************************************/

#ifndef GSM_MANAGER_H
#define GSM_MANAGER_H

#include <Arduino.h>

bool initializeGSM();

bool isNetworkReady();

bool sendATCommand(const char* command,
                   const char* expectedResponse,
                   unsigned long timeout);

bool sendSMS(const char* phoneNumber,
             const char* message);

#endif // GSM_MANAGER_H
