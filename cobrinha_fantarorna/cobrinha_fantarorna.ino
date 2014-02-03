/*
 * Sample code for SainSmart IIC/I2C/TWI Serial 2004 20x4 LCD Module.
 * License: GPL
 */
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <stdlib.h>

 
#define I2C_ADDR	0x3F
#define En_pin		2
#define Rw_pin		1
#define Rs_pin		0
#define D4_pin		4
#define D5_pin		5
#define D6_pin		6
#define D7_pin		7
#define BACKLIGHT_PIN   3

#define DIRECTION_RIGHT       0  
#define DIRECTION_BOTTOM      1
#define DIRECTION_LEFT        2
#define DIRECTION_TOP         3

int analogX = 0;
int analogY = 1;

int valX = 0;
int valY = 0;

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

byte byte_horizontal[8] = {B00000,B00000,B00000,B00000,B11111,B00000,B00000,B00000};
byte byte_vertical[8] = {B00100,B00100,B00100,B00100,B00100,B00100,B00100,B00100};

// setting animation speed (delay between frames)
int frame_rate = 500;

//byte fruit[8] = {B00000,B00000,B00000,B01110,B01110,B00000,B00000,B00000};

int snake_x[32];
int snake_y[32];
//int positions[32];
//int next_positions[32];
int direct;


void setup() {
        Serial.begin(9600);
      
	// set up the LCD's number of columns and rows:
	lcd.begin(16,2);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
        lcd.setBacklight(HIGH);
        
        // clear the LCD screen:
	lcd.clear();

        snake_x[0] = 20;
        snake_x[1] = 21;
        snake_x[2] = 22;
        
        snake_y[0] = 0;
        snake_y[1] = 0;        
        snake_y[2] = 0;
        
//        positions[0] = 0;
//        positions[1] = 1;
//        positions[2] = 2;
//        
        direct = DIRECTION_RIGHT;
}


void loop() {
    valX = analogRead(analogX);
    valY = analogRead(analogY);

    if( valX < 500 && valY > 500 )
    {
      Serial.println("left");
      direct = DIRECTION_LEFT;
    }
    else if ( valY == 0 )
    {
      Serial.println("right");
      direct = DIRECTION_RIGHT;
    }
    else if ( valX == 0 )
    {
      Serial.println("up");
      direct = DIRECTION_TOP;
    }
    else if( valY < 500 && valX > 500 )
    {
      Serial.println("down");
      direct = DIRECTION_BOTTOM;
    } 
    else 
    {
      Serial.println("middle");
    }
    
    Serial.println(direct);
    
    for(int i = 0; i < sizeof(snake_x); i++){
          int col = snake_x[i];
          int row = snake_y[i];
          draw(col, row, byte_horizontal);      
    }
    
    update_snake();
    
    delay(frame_rate);
    lcd.clear();
}

void draw(int col, int row, byte *_byte){
    lcd.createChar(0, _byte);
    lcd.setCursor(col,row);
    lcd.write((byte)0);  
}

void update_snake(){
//  next_positions = positions;
//  strncpy(next_positions, positions, 32);
//  memcpy(next_positions, positions, 32);
  for(int i = 0; i < sizeof(snake_x); i++){
    if (snake_x[i] == NULL){
      Serial.println("===================================");
      Serial.println(snake_x[i]);
      break;
    }
    Serial.println("-------------------------------------");
    Serial.println(direct);
     if( direct == DIRECTION_LEFT )
    {
      //todo
    }
    if( direct == DIRECTION_RIGHT )
    {
      Serial.println("current position BEFORE:");
      Serial.println( snake_x[i]);
      snake_x[i] = snake_x[i]+1;
      Serial.println("current position AFTER:");
      Serial.println(snake_x[i]);
    }
    if( direct == DIRECTION_TOP )
    {
      // todo
    }
    if( direct == DIRECTION_BOTTOM )
    {
      //todo
    }
    
//  memcpy(positions, next_positions, 32);    
  }
  
}
  
