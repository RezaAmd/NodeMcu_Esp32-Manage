#include <Arduino.h>

class Configure
{
public:
    void Startup()
    {
        pinMode(13, OUTPUT);
    }
};