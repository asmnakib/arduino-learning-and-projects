#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
int trigPin = 9;
int echoPin = 10;
int duration;
int distance;

void setup()
{
  lcd.begin();                     
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  }
void loop()
{

  digitalWrite(9,LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;
  lcd.setCursor(1,0);
  lcd.print("Distance Meter");
  lcd.setCursor(0,1);
  lcd.print("Dist : ");
  lcd.setCursor(5,1);
  lcd.print(distance);
  lcd.setCursor(8,1);
  lcd.print("cm");
  delay(2000);

  lcd.clear();

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  delay(500);


  
  }


