#include <Arduino.h>
#include <list>
#include <Config.h>

Config config;

int Signal;
int pulseSensor = 5;
int analogPin = 33;
int led = 18;
const int Threshold = 550;

void setup()
{
  Serial.begin(115200);

  config.Startup({pulseSensor, led});
  digitalWrite(pulseSensor, HIGH);
}

void loop()
{
  Signal = analogRead(analogPin);
  Serial.println(Signal);
  delay(20);
}