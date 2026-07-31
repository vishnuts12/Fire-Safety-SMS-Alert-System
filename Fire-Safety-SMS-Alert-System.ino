#include "version.h"
#include "types.h"
#include "pins.h"
#include "constants.h"
#include "config.h"

#include "hardware.h"
#include "lcd_manager.h"

#include "gsm_manager.h"

void setup() {

    Serial.begin(115200);

    initializeHardware();

    initializeLCD();

    displayStartupScreen();

    delay(2000);

    displayMessage(
    "Initializing",
    "GSM Module...",
    "",
    ""
);

delay(1000);

    initializeGSM();

    if (sendATCommand("AT", "OK", 2000))
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

delay(1000);
    
sendATCommand("ATE0", "OK", 2000);

sendATCommand("AT+CSQ", "OK", 3000);

displayMessage(
    "Checking",
    "Network..."
);

delay(1000);

if (sendATCommand("AT+CREG?", "OK", 3000))
{
    displayMessage("System",
                   "Ready");
}
else
{
    displayMessage("Network",
                   "Error");
}

sendATCommand("AT+CMGF=1", "OK", 3000);

}

void loop() {
  // put your main code here, to run repeatedly:

}
