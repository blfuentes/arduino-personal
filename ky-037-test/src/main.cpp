#include <Arduino.h>

// Declaration and initialization of input pins
const int analogInput = A0; // Analog output of the sensor
const int digitalInput = 3; // Digital output of the sensor

void setup()
{
  pinMode(analogInput, INPUT);
  pinMode(digitalInput, INPUT);

  Serial.begin(9600); //  Serial output with 9600 bps
}

//  The program reads the current values of the input pins
// and output it on the serial output
void loop()
{
  float Analog;
  int Digital;

  // Actual values are read out, converted to the voltage value...
  Analog = analogRead(analogInput) * (5.0 / 1023.0);
  Digital = digitalRead(digitalInput);

  //...  and issued at this point
  Serial.print("Analog voltage value:");
  Serial.print(Analog, 4);
  Serial.print("V, ");
  Serial.print("Limit :");

  if (Digital == 1)
  {
    Serial.println("reached");
  }
  else
  {
    Serial.println("not reached yet");
  }
  Serial.println(" ----------------------------------------------------------------");
}