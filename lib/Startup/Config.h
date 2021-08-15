#include <list>
using namespace std;

class Config
{
public:
    void Startup(list<int> outputs)
    {
        for (int pin : outputs)
        {
            pinMode(pin, OUTPUT);
        }
    }
};