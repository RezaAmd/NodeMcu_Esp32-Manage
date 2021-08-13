#ifndef _MYHEADER_H_
#include <Arduino.h>
#include <HTTPClient.h>
#include <list>
#include <Device.h>
#include <ArduinoJson.h>

HTTPClient client;

class Arzcharge
{
private:
    const String baseUrl = "https://core.arzcharge.com/api/";
    String apiKey = "12083210709";

public:
    std::list<Device> GetAllDevices()
    {
        Serial.println("Request to get all devices...");
        client.begin(baseUrl + "device/getAll?token=" + apiKey);
        int httpCode = client.GET();

        std::list<Device> result;
        if (httpCode == 200)
        {
            // Deserialize response.
            StaticJsonDocument<512> doc;
            String response = client.getString();
            deserializeJson(doc, response);
            // push data to list of Device.
            for (JsonObject data_item : doc["data"].as<JsonArray>())
            {
                Device device;
                device.SetDevice(data_item["id"], data_item["pin"], data_item["isActive"]);
                result.push_back(device);
            }
        }
        return result;
    }

    void SetHeartbeatReport(String data)
    {
        Serial.println(baseUrl + "report/setHeartBeat/" + data);
        client.begin(baseUrl + "report/setHeartBeat/" + data);
        client.addHeader("Content/Type", "text/plain");
        DynamicJsonDocument doc(1024);

        String payload = String(serializeJson(doc, Serial));

        int responseCore = client.POST(payload);
        int httpCode = client.GET();
        Serial.println(httpCode);
    }
};
#define _MYHEADER_H_
#endif