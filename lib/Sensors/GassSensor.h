#include <Arduino.h>

class GassSensor
{
public:
    bool isEmergencySituation(int analogPin, float rate = 2)
    {
        float gassLevel = analogRead(analogPin) / 100.0;
        Serial.println("Gass level: " + String(gassLevel));
        if (gassLevel > rate)
            return true;
        return false;
    }
};