#include "version.h"
#include "types.h"
#include "pins.h"
#include "constants.h"
#include "config.h"

#include "hardware.h"
#include "lcd_manager.h"

#include "gsm_manager.h"

void setup() {

    initializeHardware();

    initializeLCD();

    displayStartupScreen();

    initializeGSM();

}

void loop() {
  // put your main code here, to run repeatedly:

}
