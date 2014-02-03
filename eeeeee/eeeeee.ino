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

LiquidCrystal_I2C lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

struct node {
  int coord[1];
  int dir;
  struct Node *next;
  struct Node *prev;
} ;

//typedef struct snake {
//  int size;
//  struct node *head;
//} Snake;

byte byte_horizontal[8] = {B00000,B00000,B00000,B00000,B11111,B00000,B00000,B00000};
byte byte_vertical[8] = {B00100,B00100,B00100,B00100,B00100,B00100,B00100,B00100};

// setting animation speed (delay between frames)
int frame_rate = 300;

byte fruit[8] = {B00000,B00000,B00000,B01110,B01110,B00000,B00000,B00000};

byte snake_vertical[8] = {B00000,B00000,B00000,B00000,B11111,B00000,B00000,B00000};
byte snake_horizontal[8] = {B00100,B00100,B00100,B00100,B00100,B00100,B00100,B00100};

struct node *head

void setup() {
        head = (struct node *) malloc(sizeof(struct node));
        head->coord[0] = 0;
        head->coord[1] = 0;
        head->dir = DIRECTION_RIGHT;
      
	// set up the LCD's number of columns and rows:
	lcd.begin(16,2);
        lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
        lcd.setBacklight(HIGH);
        
        // clear the LCD screen:
	lcd.clear();
}


void loop() {
//	thumbdownA();
//        byte thumb1[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111};
//      
//        lcd.createChar(0, thumb1);
//        
//        lcd.setCursor(i,0);
//        lcd.write((byte)0);

//        int col = rand();
//        int row = rand();
        drawSnake();
//        moveSnake();
//        draw(col, row);
        penes();
        
        delay(frame_rate);
        lcd.clear();
//        lcd.clear();
//        i++;
//        
//        if(i>64){
//          i = 0;
//        }
}

void drawSnake(){
  Node *headcp = &head;
  while(head->next != NULL){
    draw(head->coords[0], head->coords[1], snake_horizontal);
    head = head->next;
  }
  *head = *headcp;
}

void draw(int col, int row, byte *_byte){
//    lcd.clear();
    lcd.createChar(0, _byte);
    lcd.setCursor(col,row);
    lcd.write((byte)0);  
}

void penes(){
//  int start = snake_start;
//  for(start;start <= snake_end; start++){
//    draw(start, 0, snake);
//  }
}
  
