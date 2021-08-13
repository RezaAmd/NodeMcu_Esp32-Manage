#include <Arduino.h>
#include <Arzcharge.h>

class Heartbeat
{
private:
    int PulseSensorPurplePin = A4;
    int Signal;

public:
    std::list<int> Pulses;
    void begin(int second = 60)
    {
        delay(1000);
        Serial.println(3);
        delay(1000);
        Serial.println(2);
        delay(1000);
        Serial.println(1);
        Serial.println("Started...");
        delay(2000);
        while (second > 0)
        {
            Signal = analogRead(PulseSensorPurplePin);
            if (Signal > 550 && Signal < 3500)
            {
                Pulses.push_back(Signal);
            }

            if (second % 10 == 0)
                Serial.println("");
            Serial.print(".");
            second--;
            delay(500);
        }
    }
};