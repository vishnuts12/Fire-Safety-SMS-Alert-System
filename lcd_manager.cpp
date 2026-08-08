/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : lcd_manager.cpp
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * LCD Display Implementation
 *
 ******************************************************************************/

#include "lcd_manager.h"

#include <LiquidCrystal.h>

#include "pins.h"
#include "version.h"
#include "config.h"
#include "messages.h"

LiquidCrystal lcd(
    PIN_LCD_RS,
    PIN_LCD_EN,
    PIN_LCD_D4,
    PIN_LCD_D5,
    PIN_LCD_D6,
    PIN_LCD_D7);
	
void initializeLCD()
{
    lcd.begin(LCD_COLUMNS, LCD_ROWS);

    lcd.clear();
}

void displayStartupScreen()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Fire Safety SMS");

    lcd.setCursor(0,1);
    lcd.print("Alert System");

    lcd.setCursor(0,2);
    lcd.print(INSTALLATION_NAME);

    lcd.setCursor(0,3);
    lcd.print("Version ");
    lcd.print(FW_MAJOR);
    lcd.print('.');
    lcd.print(FW_MINOR);
    lcd.print('.');
    lcd.print(FW_PATCH);
}

void displayMessage(const char* line1,
                    const char* line2,
                    const char* line3,
                    const char* line4)
{
    // Clear line 1
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(line1);

    // Clear line 2
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(line2);

    // Clear line 3
    lcd.setCursor(0, 2);
    lcd.print("                ");
    lcd.setCursor(0, 2);
    lcd.print(line3);

    // Clear line 4
    lcd.setCursor(0, 3);
    lcd.print("                ");
    lcd.setCursor(0, 3);
    lcd.print(line4);
}

void displayGSMInitializing()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("Initializing");

    lcd.setCursor(0,1);
    lcd.print("GSM Module...");
}

void displayGSMReady()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("GSM Module");

    lcd.setCursor(0,1);
    lcd.print("Ready");
}

void displayGSMFailure()
{
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print("GSM Module");

    lcd.setCursor(0,1);
    lcd.print("Not Found");
}

void displayMonitoringScreen()
{
    displayMessage(
        PROJECT_NAME,
        INSTALLATION_NAME,
        MSG_MONITORING,
        MSG_NETWORK_OK
    );
}