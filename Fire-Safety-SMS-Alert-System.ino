#include "version.h"
#include "types.h"
#include "pins.h"
#include "constants.h"
#include "config.h"

#include "hardware.h"
#include "lcd_manager.h"
#include "gsm_manager.h"
#include "pump_manager.h"
#include "event_manager.h"

void setup() {

    Serial.begin(115200);

    initializeHardware();

    initializeLCD();

    initializePumpManager();

    initializeEventManager();

    displayStartupScreen();

    delay(2000);

        if (!initializeGSM())
    {
        while (true)
        {
            delay(1000);
        }
    }

displayMonitoringScreen();

}

void loop()
{
    updatePumpStates();

    processPumpEvents();

    delay(100);
}
