#include <Arduino.h>
#include <../lib/Wifi/WifiService.h>
#include <../lib/WebService/Arzcharge.h>

WifiService wifiService;
Arzcharge webService;

// Wifi variables.
const char *ssid = "YOUR_SSID";
const char *password = "YOUR_PASSWORD";

void setup()
{
  Serial.begin(115200);
  // Connect to wifi.
  wifiService.Connect(ssid, password);
}

void loop()
{
  String response = webService.GetAllDevices();
  Serial.println(response);

  delay(3000);
}