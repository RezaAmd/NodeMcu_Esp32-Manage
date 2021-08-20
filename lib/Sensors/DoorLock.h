#include <Arduino.h>

class DoorLock
{
public:
    void Unlock(int pin, float second = 2.5)
    {
        digitalWrite(pin, HIGH);
        delay(second);
        digitalWrite(pin, LOW);
    }
};
