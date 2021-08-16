#include <Arduino.h>
#include <list>
#include <Config.h>
#include <GassSensor.h>

Config config;
GassSensor gassSensor;

const int led = 18;
const int gassAnalogPin = 33;
const int distanceAnalogPin = 32;

const int trigPin = 25; //D4
const int echoPin = 26; //D3

bool isEmergencySituation = false;

long duration;
int distancee;

void setup()
{
  Serial.begin(115200);

  config.Startup({trigPin}, {echoPin});
}

void loop()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distancee = duration * 0.034;

  // Prints the distance on the Serial Monitor
  Serial.println("Distance: " + String(distancee));

  delay(2000);
}