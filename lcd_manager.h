/******************************************************************************
 *
 * Project : Fire Safety SMS Alert System
 * File    : lcd_manager.h
 * Author  : Vishnu T S
 * Version : 1.0.0
 *
 * Description:
 * LCD Display Layer
 *
 ******************************************************************************/

#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

#include <Arduino.h>

void initializeLCD();

void displayStartupScreen();

void displayMessage(const char* line1,
                    const char* line2,
                    const char* line3 = "",
                    const char* line4 = "");

void displayGSMInitializing();

void displayGSMReady();

void displayGSMFailure();

#endif
