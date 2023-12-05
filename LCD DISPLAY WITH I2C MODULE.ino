#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup()
{
  lcd.begin();                     
  lcd.backlight();
  }
void loop()
{
  lcd.setCursor(1,0);
  lcd.print("ASM NAKIB UDDIN");
  lcd.setCursor(2,1);
  lcd.print("01854800999");
  delay(2000);

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("IPE ENGINEER");
  lcd.setCursor(4,1);
  lcd.print("CGPA 3.60");
  delay(2000);
  lcd.clear();
  
  }
