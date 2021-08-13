#ifndef _MYHEADER_H_
class Device
{
public:
    String Id;
    int Pin;
    bool IsActive = false;

    void SetDevice(String id, int pin, bool isActive){
        Id = id;
        Pin = pin;
        IsActive = isActive;
    }
};
#define _MYHEADER_H_
#endif