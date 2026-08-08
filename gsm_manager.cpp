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

#include "lcd_manager.h"

#include "hardware.h"

#include "messages.h"

SoftwareSerial gsm(PIN_GSM_RX,PIN_GSM_TX);

bool initializeGSM()
{

    displayMessage(
        PROJECT_NAME,
        INSTALLATION_NAME,
        "",
        MSG_INITIALIZING
    );

    gsm.begin(9600);

    delay(GSM_BOOT_TIME);

    blinkGSMLed(2);

    if (!sendATCommand("AT", "OK", 5000))
    {
        displayGSMFailure();
        return false;
    }

    displayMessage(
        PROJECT_NAME,
        INSTALLATION_NAME,
        "",
        MSG_CHECK_SIGNAL
    );

    delay(1500);

    blinkGSMLed(2);

    if (!sendATCommand("ATE0", "OK", 5000))
    {
    displayGSMFailure();
    return false;
    }

    if (!sendATCommand("AT+CSQ", "OK", 5000))
    {
        displayGSMFailure();
        return false;
    }

    delay(2000);

    blinkGSMLed(2);

    displayMessage(
        PROJECT_NAME,
        INSTALLATION_NAME,
        "",
        MSG_CHECK_NETWORK
    );

    delay(1500);

    blinkGSMLed(2);

    if (!sendATCommand("AT+CREG?", "OK", 5000))
    {
        displayGSMFailure();
        return false;
    }

    if (!sendATCommand("AT+CMGF=1", "OK", 5000))
    {
        displayGSMFailure();
        return false;
    }

    delay(1500);

    blinkGSMLed(2);

    displayMessage(
        PROJECT_NAME,
        INSTALLATION_NAME,
        "",
        MSG_GSM_READY
    );

    delay(2000);

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

bool sendSMS(const char* phoneNumber, const char* message)
{
    // Set SMS text mode
    if (!sendATCommand("AT+CMGF=1", "OK", 3000))
    {
        return false;
    }

    // Start SMS command
    gsm.print("AT+CMGS=\"");
    gsm.print(phoneNumber);
    gsm.println("\"");

    // Wait for the '>' prompt
    unsigned long startTime = millis();
    while (millis() - startTime < 5000)
    {
        if (gsm.available())
        {
            char c = gsm.read();

            if (c == '>')
            {
                break;
            }
        }
    }

    // Send the message
    gsm.print(message);

    // Send Ctrl+Z (ASCII 26)
    gsm.write(26);

    // Wait for confirmation
    String response = "";

    startTime = millis();

    while (millis() - startTime < 15000)
    {
        while (gsm.available())
        {
            char c = gsm.read();
            response += c;

            if (response.indexOf("OK") != -1)
            {
                return true;
            }
        }
    }

    return false;
}