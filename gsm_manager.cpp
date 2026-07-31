/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : gsm_manager.cpp
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * GSM Manager Implementation
 *
 ******************************************************************************/

#include "gsm_manager.h"

#include <SoftwareSerial.h>

#include "pins.h"

#include "config.h"

SoftwareSerial gsm(PIN_GSM_RX,PIN_GSM_TX);

bool initializeGSM()
{
    gsm.begin(9600);

    delay(3000);     // Allow SIM800L to boot

    gsm.println("AT");

    return true;
}

bool sendATCommand(const char* command,
                   const char* expectedResponse,
                   unsigned long timeout)
{
    gsm.println(command);

    String response = "";

    unsigned long startTime = millis();

    while (millis() - startTime < timeout)
    {
        while (gsm.available())
        {
            char c = gsm.read();
            response += c;
            Serial.print(c);

            if (response.indexOf(expectedResponse) != -1)
            {
                return true;
            }
        }
    }

    return false;
}
