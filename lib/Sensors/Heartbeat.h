#include <Arduino.h>
#include <Arzcharge.h>

class Heartbeat
{
private:
    int Signal;
    int Threshold = 550;
    int Delay = 100;

public:
    list<int> begin(int analogPin, int pin, int second = 60, int led = 18)
    {
        second = (1000 / Delay) * second;
        list<int> Pulses;
        digitalWrite(pin, HIGH);
        delay(2000);
        Serial.println("The heart rate sensor is reading information...");
        while (second > 0)
        {
            Signal = analogRead(analogPin);
            if (Signal > 550 && Signal < 2200)
            {
                digitalWrite(led, HIGH);
                if (Signal >= 2000)
                    Pulses.push_back(Signal);
                Pulses.push_back(0);
            }
            else{
                digitalWrite(led, LOW);
            }

            if (second % 20 == 0)
                Serial.println("");
            Serial.print(".");
            second--;
            delay(Delay);
        }
        digitalWrite(pin, LOW);
        Serial.println("The heart sensor was deactivated.");
        return Pulses;
    }
};