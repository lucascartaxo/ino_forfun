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


// setting animation speed (delay between frames)
int x = 500;

void setup() {
	// set up the LCD's number of columns and rows:
	lcd.begin(16,2);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
        lcd.setBacklight(HIGH);
	// clear the LCD screen:
	lcd.clear();
}


void loop() {
	// start the Thumbs Down part:
	penesdownA();
        delay(x);
        lcd.clear();
//        penesdownB();
//        delay(x);
//        lcd.clear();
}     

void penesdownA() {
  byte penes1[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes2[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes3[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes4[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes5[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes6[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes7[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
  byte penes8[8] = {B00000,B00000,B11111,B00000,B00000,B00000,B00000,B00000};
//  byte penes9[8] = {B00000,B00000,B11000,B00110,B00001,B00000,B00000,B00000}; // glande
//  byte penes10[8] = {B00000,B00000,B00000,B00000,B00000,B10000,B01000,B01000};
//  byte penes11[8] = {B01000,B01000,B10000,B00000,B00000,B00000,B00000,B00000};//fim da glande
//  byte penes12[8] = {B00000,B00000,B00000,B00001,B00110,B11000,B00000,B00000};
//  byte penes13[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes14[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes15[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes16[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes17[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes18[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes19[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
//  byte penes20[8] = {B00000,B00000,B00000,B00000,B00000,B11111,B00000,B00000};
  
  
  
  lcd.createChar(0, penes1);
  lcd.createChar(1, penes2);
  lcd.createChar(2, penes3);
  lcd.createChar(3, penes4);
  lcd.createChar(4, penes5);
  lcd.createChar(5, penes6);
  lcd.createChar(6, penes7);
  lcd.createChar(7, penes8);
//  lcd.createChar(8, penes9);
//  lcd.createChar(9, penes10);
//  lcd.createChar(10, penes11);
//  lcd.createChar(11, penes12);
//  lcd.createChar(12, penes13);
//  lcd.createChar(13, penes14);
//  lcd.createChar(14, penes15);
//  lcd.createChar(15, penes16);
//  lcd.createChar(16, penes17);
//  lcd.createChar(17, penes18);
//  lcd.createChar(18, penes19);
//  lcd.createChar(19, penes20);

  lcd.setCursor(4,0);
  lcd.write((byte)0);
  lcd.setCursor(4,0);
  lcd.write(1);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(6,0);
  lcd.write(3);
  lcd.setCursor(7,0);
  lcd.write(4);
  lcd.setCursor(8,0);
  lcd.write(5);
  lcd.setCursor(9,0);
  lcd.write(6);
  lcd.setCursor(10,0);
  lcd.write(7);
  lcd.setCursor(11,0);
  lcd.write(8);
  lcd.setCursor(12,0);
  lcd.write(9);
  lcd.setCursor(12,1);
  lcd.write(10);
  lcd.setCursor(11,1);
  lcd.write(11);
  lcd.setCursor(10,1);
  lcd.write(12);
  lcd.setCursor(9,1);
  lcd.write(13);
  lcd.setCursor(8,1);
  lcd.write(14);
  lcd.setCursor(7,1);
  lcd.write(15);
}

void penesdownB() {
  byte penes1[8] = {B00000,B00001,B00010,B00011,B00100,B00011,B00100,B00011};
  byte penes2[8] = {B00100,B00011,B00000,B00000,B00000,B00000,B00000,B00000};
  byte penes3[8] = {B00000,B11110,B00001,B00000,B00000,B00000,B00000,B00000};
  byte penes4[8] = {B00000,B00000,B11110,B01000,B10001,B10010,B10010,B01100};
  byte penes5[8] = {B00000,B00000,B10000,B01110,B00010,B00010,B00010,B00010};
  byte penes6[8] = {B00010,B00110,B01000,B10000,B00000,B00000,B00000,B00000};
  lcd.createChar(0, penes1);
  lcd.createChar(1, penes2);
  lcd.createChar(2, penes3);
  lcd.createChar(3, penes4);
  lcd.createChar(4, penes5);
  lcd.createChar(5, penes6);
  lcd.setCursor(4,0);
  lcd.write((byte)0);
  lcd.setCursor(4,1);
  lcd.write(1);
  lcd.setCursor(5,0);
  lcd.write(2);
  lcd.setCursor(5,1);
  lcd.write(3);
  lcd.setCursor(6,0);
  lcd.write(4);
  lcd.setCursor(6,1);
  lcd.write(5);
}

