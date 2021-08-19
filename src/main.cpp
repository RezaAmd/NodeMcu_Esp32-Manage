#include <Arduino.h>
#include <list>
#include <Config.h>
#include <GassSensor.h>

Config config;
GassSensor gassSensor;

const int led = 18;
const int gassAnalogPin = 33;

const int trigPin = 25; //D4
const int echoPin = 26; //D3

bool isEmergencySituation = false;

long duration;
int distancee;

void setup()
{
  Serial.begin(115200);

  config.Startup({led}, {echoPin});
}

void loop()
{
  float tempeture = analogRead(34) / 100.0;
  Serial.println("Tempeture: " + String(tempeture));
  if (tempeture > 2)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
  delay(100);
}