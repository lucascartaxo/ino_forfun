/*
 * Sample code for SainSmart IIC/I2C/TWI Serial 2004 20x4 LCD Module.
 * License: GPL
 */
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
#define I2C_ADDR	0x3F
#define En_pin		2
#define Rw_pin		1
#define Rs_pin		0
#define D4_pin		4
#define D5_pin		5
#define D6_pin		6
#define D7_pin		7
#define BACKLIGHT_PIN   3
 
LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
 
//void setup() {
//  // set up the LCD's number of columns and rows: 
//  lcd.begin(16, 2);
//  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
//  lcd.setBacklight(HIGH);
//  // Print a message to the LCD.
//  lcd.print("hello, world!");
//}
//
//void loop() {
//  // Turn off the blinking cursor:
//  lcd.noBlink();
//  delay(3000);
//   // Turn on the blinking cursor:
//  lcd.blink();
//  delay(3000);
//}



void setup() {
	// set up the LCD's number of columns and rows:
	lcd.begin(16,2);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
        lcd.setBacklight(HIGH);
	// clear the LCD screen:
	lcd.clear();
}


void loop() {
	// start the Thumbs Up part:
	thumbsup();
}     

void thumbsup() {
  byte thumb1[8] = {B00100,B00011,B00100,B00011,B00100,B00011,B00010,B00001};
  byte thumb2[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00011};
  byte thumb3[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00001,B11110};
  byte thumb4[8] = {B00000,B01100,B10010,B10010,B10001,B01000,B11110,B00000};
  byte thumb5[8] = {B00010,B00010,B00010,B00010,B00010,B01110,B10000,B00000};
  byte thumb6[8] = {B00000,B00000,B00000,B00000,B00000,B10000,B01000,B00110};
  lcd.createChar(0, thumb1);
  lcd.createChar(1, thumb2);
  lcd.createChar(2, thumb3);
  lcd.createChar(3, thumb4);
  lcd.createChar(4, thumb5);
  lcd.createChar(5, thumb6);
  lcd.setCursor(4,1);
  lcd.write((byte)0);
  lcd.setCursor(4,0);
  lcd.write(1);
  lcd.setCursor(5,1);
  lcd.write(2);
  lcd.setCursor(5,0);
  lcd.write(3);
  lcd.setCursor(6,1);
  lcd.write(4);
  lcd.setCursor(6,0);
  lcd.write(5);
}

