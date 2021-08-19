#include <Arduino.h>

class GassSensor
{
public:
    bool isEmergencySituation(int analogPin, float rate = 2)
    {
        float gassLevel = getLevel(analogPin);
        Serial.println("Gass level: " + String(gassLevel));
        if (gassLevel > rate)
            return true;
        return false;
    }
    
    float getLevel(int analogPin)
    {
        return analogRead(analogPin) / 100.0;
    }
};
