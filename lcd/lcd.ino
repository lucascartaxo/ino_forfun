#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define lcdAddr 0x3F // set the address of the I2C device the LCD is connected to

// create an lcd instance

LiquidCrystal_I2C lcd(0x3F, 6, 5, 4, 0, 1, 2, 3);
//LiquidCrystal_I2C lcd(lcdAdrr); // I2C addr

// Creat a set of new characters
const uint8_t charBitmap[][8] = {
   { 0xc, 0x12, 0x12, 0xc, 0, 0, 0, 0 },
   { 0x6, 0x9, 0x9, 0x6, 0, 0, 0, 0 },
   { 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0, 0x0 },
   { 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0, 0x0 },
   { 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0, 0x0 },
   { 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0, 0x0 },
   { 0x0, 0x0, 0x0, 0x6, 0x9, 0x9, 0x6, 0x0 },
   { 0x0, 0x0, 0x0, 0xc, 0x12, 0x12, 0xc, 0x0 }
   
};

void setup()
{
   int charBitmapSize = (sizeof(charBitmap ) / sizeof (charBitmap[0]));

  lcd.begin(20,4);  // initialize the lcd as 20x4 (16,2 for 16x2)
  
  lcd.setBacklight(1); // switch on the backlight

  for ( int i = 0; i < charBitmapSize; i++ )
   {
      lcd.createChar ( i, (uint8_t *)charBitmap[i] );
   }

  lcd.home ();  // go home to character 0 on line 0 (1st line)
  lcd.print("Hello, ARDUINO ");  
  lcd.setCursor(0,1);  // character 0 on line 1 (2nd line)
  lcd.print (" FORUM - fm   ");
  lcd.setCursor(0,2); // character 0 on line 2 (3rd line)
  lcd.print("This is line 3");
  lcd.setCursor(0,3); // character 0 on line 3 (4th line)
  lcd.print("This is line 3");
  delay(1000);
}

void loop()
{
   lcd.clear();
   lcd.home ();
   // Do a little animation by writing to the same location
   for ( int i = 0; i < 2; i++ )
   {
      for ( int j = 0; j < 16; j++ )
      {
         lcd.print (char(random(7)));
      }
      lcd.setCursor ( 0, 1 );
   }
   delay (200);
}
