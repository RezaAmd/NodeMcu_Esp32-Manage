#include <Arduino.h>
#include <Arzcharge.h>

class Heartbeat
{
private:
    int Signal;

public:
    list<int> begin(int analogPin, int pin, int second = 60)
    {
        list<int> Pulses;
        delay(1000);
        Serial.println(3);
        delay(1000);
        Serial.println(2);
        delay(1000);
        Serial.println(1);
        digitalWrite(pin, HIGH);
        delay(2000);
        Serial.println("The heart rate sensor is reading information...");
        while (second > 0)
        {
            Signal = analogRead(analogPin);
            if (Signal > 550 && Signal < 3500)
            {
                Pulses.push_back(Signal);
            }

            if (second % 15 == 0)
                Serial.println("");
            Serial.print(".");
            second--;
            delay(500);
        }
        digitalWrite(pin, LOW);
        Serial.println("The heart sensor was deactivated.");
        return Pulses;
    }
};