/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : event_manager.cpp
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * Processes pump state changes.
 *
 ******************************************************************************/

#include "event_manager.h"

#include "pump_manager.h"
#include "lcd_manager.h"
#include "gsm_manager.h"
#include "config.h"
#include "messages.h"

//--------------------------------------------------
// Private Helper Functions
//--------------------------------------------------

static void handlePumpStarted(PumpID pump);

static void handlePumpStopped(PumpID pump);

static void showPumpEvent(
    PumpID pump,
    const char* status);

static void restoreMonitoringScreen();

static bool sendPumpStatusSMS(
    PumpID pump,
    const char* status);

void initializeEventManager()
{
    // Reserved for future initialization.
}

void processPumpEvents()
{
    for (uint8_t i = 0; i < NUMBER_OF_PUMPS; i++)
    {
        PumpID pump = static_cast<PumpID>(i);

        if (pumpStarted(pump))
        {
            handlePumpStarted(pump);
        }
        else if (pumpStopped(pump))
        {
            handlePumpStopped(pump);
        }
    }
}

static void handlePumpStarted(PumpID pump)
{
    showPumpEvent(
        pump,
        MSG_PUMP_STARTED
    );

    if (sendPumpStatusSMS(
        pump,
        MSG_PUMP_STARTED))
{
    displayMessage(
        getPumpName(pump),
        MSG_PUMP_STARTED,
        "",
        MSG_SMS_SENT
    );
}
else
{
    displayMessage(
        getPumpName(pump),
        MSG_PUMP_STARTED,
        "",
        MSG_SMS_FAILED
    );
}

    restoreMonitoringScreen();

}

static void handlePumpStopped(PumpID pump)
{
    showPumpEvent(
        pump,
        MSG_PUMP_STOPPED
    );

    if (sendPumpStatusSMS(
        pump,
        MSG_PUMP_STOPPED))
{
    displayMessage(
        getPumpName(pump),
        MSG_PUMP_STOPPED,
        "",
        MSG_SMS_SENT
    );
}
else
{
    displayMessage(
        getPumpName(pump),
        MSG_PUMP_STOPPED,
        "",
        MSG_SMS_FAILED
    );
}

    restoreMonitoringScreen();
}

static bool sendPumpStatusSMS(
    PumpID pump,
    const char* status)
{
    char message[160];

    snprintf(
        message,
        sizeof(message),
        "FIRE SAFETY ALERT\n\n"
        "Location : %s\n"
        "Pump : %s\n"
        "Status : %s",
        INSTALLATION_NAME,
        getPumpName(pump),
        status
    );

    bool success = true;

    for (uint8_t i = 0; i < NUMBER_OF_SMS_RECIPIENTS; i++)
    {
        if (!sendSMS(SMS_RECIPIENTS[i], message))
        {
            success = false;
        }
    }

    return success;
}

static void showPumpEvent(
    PumpID pump,
    const char* status)
{
    displayMessage(
        getPumpName(pump),
        status,
        "",
        MSG_SENDING_SMS
    );
}

static void restoreMonitoringScreen()
{
    delay(2000);

    displayMonitoringScreen();
}