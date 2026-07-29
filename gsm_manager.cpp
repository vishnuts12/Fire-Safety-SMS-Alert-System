#include "gsm_manager.h"

#include <SoftwareSerial.h>

#include "pins.h"

SoftwareSerial gsm(PIN_GSM_RX,
                   PIN_GSM_TX);
				   
bool initializeGSM()
{
    gsm.begin(9600);

    delay(1000);

    return true;
}				   
