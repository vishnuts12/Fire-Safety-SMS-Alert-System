/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : lcd_manager.cpp
 *
 ******************************************************************************/

#include "lcd_manager.h"

#include <LiquidCrystal.h>

#include "pins.h"
#include "version.h"
#include "config.h"

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
    lcd.print("Ver ");
    lcd.print(FW_MAJOR);
    lcd.print('.');
    lcd.print(FW_MINOR);
    lcd.print('.');
    lcd.print(FW_PATCH);
}