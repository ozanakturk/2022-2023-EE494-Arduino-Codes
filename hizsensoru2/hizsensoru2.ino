#include "TimerOne.h"
unsigned int counter=0;

int b1a = 6;  // L9110 B-1A 
int b1b = 9;  // L9110 B-1B

float ref1 = 13.0;
float ref2 = 15.0;
float ref3 = 17.0;
float err = 0;
float kp = 5;

float rotation;

void docount()  // counts from the speed sensor
{
  counter++;  // increase +1 the counter value
} 

void timerIsr()
{
  Timer1.detachInterrupt();  //stop the timer
  Serial.print("Motor Speed: "); 
  rotation = (counter / 20);  // divide by number of holes in Disc
  Serial.print(rotation,DEC);  
  Serial.println(" Rotation per seconds"); 
  counter=0;  //  reset counter to zero

  err = ref2 - rotation;
  int motorspeed = constrain(int(round(kp*err)), 0, 255);
  analogWrite(b1a, motorspeed);  // set speed of motor (0-255)
  digitalWrite(b1b, 0);  // set rotation of motor to Clockwise
  
  Timer1.attachInterrupt( timerIsr );  //enable the timer
}

void setup() 
{
  Serial.begin(9600);
  
 pinMode(b1a, OUTPUT); 
 pinMode(b1b, OUTPUT); 
  
  Timer1.initialize(1000000); // set timer for 1sec
  attachInterrupt(0, docount, RISING);  // increase counter when speed sensor pin goes High
  Timer1.attachInterrupt( timerIsr ); // enable the timer
} 

void loop()
{
  
/*
  Serial.print(ref1,DEC);  
  Serial.println(" ref1"); 

  Serial.print(err,DEC);  
  Serial.println(" err"); 

  Serial.print(motorspeed,DEC);  
  Serial.println(" motorspeed"); */
}
