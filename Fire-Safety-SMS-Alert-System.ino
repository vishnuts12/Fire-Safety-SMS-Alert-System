#include "version.h"
#include "types.h"
#include "pins.h"
#include "constants.h"
#include "config.h"

#include "hardware.h"
#include "lcd_manager.h"

#include "gsm_manager.h"

#include "pump_manager.h"

void setup() {

    Serial.begin(115200);

    initializeHardware();

    initializePumpManager();

    initializeLCD();

    displayStartupScreen();

    delay(2000);

    displayMessage(
    "Initializing",
    "GSM Module...",
    "",
    ""
);

    delay(5000);

    initializeGSM();

    delay(5000);

    if (sendATCommand("AT", "OK", 5000))
{

    displayMessage(
    "Checking",
    "Signal..."
);

    setGSMLed(true);
}
else
{
    displayMessage(
        "GSM Module",
        "Not Found",
        "",
        ""
    );

    setFaultLED(true);
}

delay(5000);
    
sendATCommand("ATE0", "OK", 5000);

sendATCommand("AT+CSQ", "OK", 5000);

displayMessage(
    "Checking",
    "Network..."
);

delay(5000);

if (sendATCommand("AT+CREG?", "OK", 5000))
{
    displayMessage("System",
                   "Ready");
}
else
{
    displayMessage("Network",
                   "Error");
}

    delay(5000);

sendATCommand("AT+CMGF=1", "OK", 5000);

displayMessage(
    "Sending",
    "Test SMS..."
);

if (sendSMS("+918848488050",
            "Fire Safety SMS Alert System Test"))
{
    displayMessage(
        "SMS",
        "Sent",
        "Successfully"
    );
}
else
{
    displayMessage(
        "SMS",
        "Send Failed"
    );
}

}

void loop() {

    updatePumpStates();
  // put your main code here, to run repeatedly:

}
