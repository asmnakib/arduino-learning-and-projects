int pin = 13;
int trigPin = 9;
int echoPin = 10;
int duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  if (distance >= 3 && distance<=75)
  {
    digitalWrite(pin, LOW);
    Serial.print(" Light Turned On         :     ");
  
  }

  else
  {
    digitalWrite(pin, HIGH);
    Serial.print(" Light Turned Off         :     ");  
  }
  Serial.print("Your Distance from Sensor: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  delay(500);


}
