#include "srv_stdio_lcd.h"
#include <Wire.h> // Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h>
#include <stdio.h> // Include the standard I/O library for printf

#define CLEAR_KEY 0x1b // Define the clear key value

// Define the LCD address and dimensions
int lcdColumns = 16;
int lcdRows = 2;

// Create an LCD object with address 0x27 (common for many I2C LCDs)
LiquidCrystal_I2C lcd(0x27);

int srv_stdio_lcd_putc(char c, FILE *stream) {
    // Print the character to the LCD
    if (c == CLEAR_KEY) {
        lcd.clear();
        lcd.setCursor(0, 0);
    } else {
        lcd.print(c);
    }
}

void srv_stdio_lcd_setup() {
    // Initialize the LCD
    lcd.begin(lcdColumns, lcdRows);

    // Turn on the backlight
    lcd.backlight();

    // Print a message to the LCD
    lcd.setCursor(0, 0);

    FILE *srv_stdio_lcd_stream = fdevopen(srv_stdio_lcd_putc, NULL);

    stdout = srv_stdio_lcd_stream;


}



