#include <WiFi.h>

class WifiService
{
public:
    void Connect(const char *ssid, const char *password)
    {
        WiFi.begin(ssid, password);
        Serial.print("Connecting to " + String(ssid));
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.print(".");
            delay(1300);
        }
        Serial.println("\nConnected to the '" + String(ssid) + "'.\nIp Address: " + String(WiFi.localIP()));
    }
};