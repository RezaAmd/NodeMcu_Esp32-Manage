#ifndef _MYHEADER_H_
#include <Arduino.h>
#include <list>
#include <../lib/Startup/Configure.h>
#include <../lib/Wifi/WifiService.h>
#include <../lib/WebService/Arzcharge.h>
#include <../lib/Sensors/Heartbeat.h>

WifiService wifiService;
Arzcharge webService;
Configure configure;
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
  configure.Startup();
  heartbeat.begin();
  String data;
  std::list<int> pulseList = heartbeat.Pulses;
  for (int pulse : pulseList)
  {
    data = data + String(pulse) + ",";
  }
  Serial.println(data);
  webService.SetHeartbeatReport(data);
}

void loop()
{
  // std::list<Device> devices;

  // devices = webService.GetAllDevices();
  // for (Device device : devices)
  // {
  //   if (device.IsActive == 1)
  //     digitalWrite(device.Pin, HIGH);
  //   else
  //     digitalWrite(device.Pin, LOW);
  // }

  // Signal = analogRead(PulseSensorPurplePin);
  // if (Signal > 550 && Signal < 3000)
  //   Serial.println(Signal);

  delay(1000);
}
#define _MYHEADER_H_
#endif