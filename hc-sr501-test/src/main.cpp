#include <Arduino.h>

const int led = 9;    // Led positive terminal to the digital pin 9.
const int sensor = 5; // signal pin of sensor to digital pin 5.

int prevState;
int currentState;
int sensorVal;

void setup()
{                         // Void setup is ran only once after each powerup or reset of the Arduino board.
  pinMode(led, OUTPUT);   // Led is determined as an output here.
  pinMode(sensor, INPUT); // PIR motion sensor is determined is an input here.
  Serial.begin(9600);
}

void loop()
{ // Void loop is ran over and over and consists of the main program.
  sensorVal = digitalRead(sensor);
  if (sensorVal == HIGH)
  {
    digitalWrite(led, sensorVal);
    delay(500); // Delay of led is 500
    if (currentState == LOW)
    {
      Serial.println("Motion detected");
      currentState = HIGH;
    }
  }
  else
  {
    digitalWrite(led, LOW);
    delay(500);
    if (currentState == HIGH)
    {
      Serial.println("The action/motion has stopped");
      currentState = LOW;
    }
  }
}
