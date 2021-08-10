#include <WiFi.h>

class WifiService
{
public:
    void Connect(const char *ssid, const char *password)
    {
        String ssidString = String(ssid);

        WiFi.begin(ssid, password);
        Serial.print("Connecting to " + ssidString);
        while (WiFi.status() != WL_CONNECTED)
        {
            Serial.print(".");
            delay(1300);
        }
        Serial.println("\nConnected to the '" + ssidString + "'.\nIp Address: " + WiFi.localIP());
    }
};