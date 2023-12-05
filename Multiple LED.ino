int ledPins[] = {2,3};

// ledPins[0] =2
// ledPins[1] =3

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<2;i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }


}

  /* (commented code will not run)
   * these are the lines replaced by the for loop above they do exactly the
   * same thing the one above just uses less typing
  pinMode(ledPins[0],OUTPUT);
  pinMode(ledPins[1],OUTPUT);
  (end of commented code)*/

 
 
/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called oneAfterAnother(). if you would like a different behaviour
 * uncomment (delete the two slashes) one of the other lines
 */
void loop()                     // run over and over again
{
  //oneAfterAnotherNoLoop();   //this will turn on each LED one by one then turn each off
  //oneAfterAnotherLoop();   //does the same as oneAfterAnotherNoLoop but with 
                             //much less typing
  oneOnAtATime();          //this will turn one LED on then turn the next one
                             //on turning the 
                             //former off (one LED will look like it is scrolling 
                             //along the line
  //inAndOut();              //lights the two middle LEDs then moves them out then back 
                             //in again
}
 
/*
 * oneAfterAnotherNoLoop() - Will light one LED then delay for delayTime then light
 * the next LED until all LEDs are on it will then turn them off one after another
 *
 * this does it without using a loop which makes for a lot of typing. 
 * oneOnAtATimeLoop() does exactly the same thing with less typing
 */
void oneAfterAnotherNoLoop(){
  int delayTime = 2000; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
  digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (connected to pin 2 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (connected to pin 3 )
  delay(delayTime);                //waits delayTime milliseconds
                //waits delayTime milliseconds  
 
//Turns Each LED Off

  digitalWrite(ledPins[1], LOW);  //Turns on LED #6 (connected to pin 8 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[0], LOW);  //Turns on LED #7 (connected to pin 9 )
  delay(delayTime);                //waits delayTime milliseconds  
}
 
/*
 * oneAfterAnotherLoop() - Will light one LED then delay for delayTime then light
 * the next LED until all LEDs are on it will then turn them off one after another
 *
 * this does it using a loop which makes for a lot less typing. 
 * than oneOnAtATimeNoLoop() does exactly the same thing with less typing
 */
void oneAfterAnotherLoop(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
 
//Turn Each LED on one after another
  for(int i = 0; i <= 1; i++){
    digitalWrite(ledPins[i], HIGH);  //Turns on LED #i each time this runs i
    delay(delayTime);                //gets one added to it so this will repeat 
  }                                  //8 times the first time i will = 0 the final
                                     //time i will equal 7;
 
//Turn Each LED off one after another
  for(int i = 1; i >= 0; i--){  //same as above but rather than starting at 0 and counting up
                                //we start at seven and count down
    digitalWrite(ledPins[i], LOW);  //Turns off LED #i each time this runs i
    delay(delayTime);                //gets one subtracted from it so this will repeat 
  }                                  //8 times the first time i will = 7 the final
                                     //time it will equal 0
                                     
                                     
}
 
/*
 * oneOnAtATime() - Will light one LED then the next turning off all the others
 */
void oneOnAtATime(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
  
  for(int i = 0; i <= 7; i++){
    int offLED = i - 1;  //Calculate which LED was turned on last time through
    if(i == 0) {         //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      offLED = 7;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
                         //instead we turn off LED 7, (looping around)
    digitalWrite(ledPins[i], HIGH);     //turn on LED #i
    digitalWrite(ledPins[offLED], LOW); //turn off the LED we turned on last time
    delay(delayTime);
  }
}
 
/*
 * inAndOut() - This will turn on the two middle LEDs then the next two out
 * making an in and out look
 */
void inAndOut(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
  
  //runs the LEDs out from the middle
  for(int i = 0; i <= 3; i++){
    int offLED = i - 1;  //Calculate which LED was turned on last time through
    if(i == 0) {         //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      offLED = 3;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
                         //instead we turn off LED 7, (looping around)
    int onLED1 = 3 - i;       //this is the first LED to go on ie. LED #3 when i = 0 and LED 
                             //#0 when i = 3 
    int onLED2 = 4 + i;       //this is the first LED to go on ie. LED #4 when i = 0 and LED 
                             //#7 when i = 3 
    int offLED1 = 3 - offLED; //turns off the LED we turned on last time
    int offLED2 = 4 + offLED; //turns off the LED we turned on last time
    
    digitalWrite(ledPins[onLED1], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);    
    digitalWrite(ledPins[offLED1], LOW);    
    digitalWrite(ledPins[offLED2], LOW);        
    delay(delayTime);
  }
 
  //runs the LEDs into the middle
  for(int i = 3; i >= 0; i--){
    int offLED = i + 1;  //Calculate which LED was turned on last time through
    if(i == 3) {         //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      offLED = 0;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
                         //instead we turn off LED 7, (looping around)
    int onLED1 = 3 - i;       //this is the first LED to go on ie. LED #3 when i = 0 and LED 
                             //#0 when i = 3 
    int onLED2 = 4 + i;       //this is the first LED to go on ie. LED #4 when i = 0 and LED 
                             //#7 when i = 3 
    int offLED1 = 3 - offLED; //turns off the LED we turned on last time
    int offLED2 = 4 + offLED; //turns off the LED we turned on last time
    
    digitalWrite(ledPins[onLED1], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);    
    digitalWrite(ledPins[offLED1], LOW);    
    digitalWrite(ledPins[offLED2], LOW);        
    delay(delayTime);
  }
}