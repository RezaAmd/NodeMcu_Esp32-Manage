#include <list>
using namespace std;

class Config
{
public:
    void Startup(list<int> outputs, list<int> inputs)
    {
        for (int pin : outputs)
            pinMode(pin, OUTPUT);

        for (int pin : inputs)
            pinMode(pin, INPUT);
    }
};