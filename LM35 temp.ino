#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

int lm35=A3; 
int value =0;

void setup()
{
  lcd.begin();                     
  lcd.backlight();
  Serial.begin(9600);  
  }
void loop()
{
  value=analogRead(lm35);
  float milivolts=(value/1024.0)*5000;
  float cel=milivolts/10;

  lcd.setCursor(1,0);
  lcd.print("ROOM Temp : ");
  lcd.setCursor(1,1);
  lcd.print(cel);
  lcd.setCursor(8,1);
  lcd.print("*C");
  delay(1000);

  lcd.clear();
    
  Serial.print("Temperature: ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();  
  
  
  }