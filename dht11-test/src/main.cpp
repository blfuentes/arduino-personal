#include <Arduino.h>
#include <dht11.h>

const int pinDHT11 = 4;

dht11 DHT11;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println();
  Serial.println("DHT11 readings");

  int chk = DHT11.read(pinDHT11);

  Serial.println("Temperature: " + String(DHT11.temperature) + " C");
  Serial.println("Humidity: " + String(DHT11.humidity) + " %");

  delay(2000);
}