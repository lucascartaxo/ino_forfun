#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte newChar[8] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B01010,
  B11011,
  B00000
};

void setup() {
  lcd.createChar(0, newChar);
  lcd.begin(16, 2);
  lcd.write(0);
}

void loop() {}
