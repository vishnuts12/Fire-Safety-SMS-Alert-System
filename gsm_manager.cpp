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
