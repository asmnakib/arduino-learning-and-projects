int ledPin = 2;  

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  analogWrite(ledPin, 200 );
  delay(1000);
  analogWrite(ledPin, 150 );
  delay(1000);  
  analogWrite(ledPin, 80 );
  delay(1000);  
  analogWrite(ledPin, 255 );
  delay(1000);
  analogWrite(ledPin, 150 );
  delay(1000);  
  analogWrite(ledPin, 80 );
  delay(1000);    
}