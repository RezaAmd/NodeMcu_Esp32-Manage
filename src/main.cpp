#include <Arduino.h>
#include <list>
#include <Config.h>
#include <../lib/Wifi/WifiService.h>
#include <../lib/WebService/Arzcharge.h>
#include <../lib/Sensors/Heartbeat.h>

WifiService wifiService;
Arzcharge webService;
Config config;
Heartbeat heartbeat;

// Wifi variables.
const char *ssid = "Nokia";
const char *password = "reza1050";

int Signal;

void setup()
{
  Serial.begin(115200);
  // Connect to wifi.
  wifiService.Connect(ssid, password);

  config.Startup();

  // Active the pin (analog) and get data from sensor.
   std::list<int> pulseList = heartbeat.begin(A4, 5);

   for (int data : pulseList)
   {
     Serial.println(data);
   }
    Serial.println("END");
  //webService.SetHeartbeatReport(pulseList);
}

void loop()
{
  delay(1000);
}