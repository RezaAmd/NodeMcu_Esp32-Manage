#ifndef _MYHEADER_H_
#include <Arduino.h>
#include <Device.h>
#include <ArduinoJson.h>
#include <RestClient.h>

RestClient restClient;

class Arzcharge
{
private:
    const String baseUrl = "https://core.arzcharge.com/api/";
    String apiKey = "12083210709";

public:
    std::list<Device> GetAllDevices()
    {
        std::list<Device> result;
        HttpResponse response;
        response = restClient.Request(baseUrl + "device/getAll?token=" + apiKey);

        if (response.HttpCode == 200)
        {
            StaticJsonDocument<512> doc;
            deserializeJson(doc, response.Content);
            //push data to list of Device.
            for (JsonObject data_item : doc["data"].as<JsonArray>())
            {
                Device device;
                device.SetDevice(data_item["id"], data_item["pin"], data_item["isActive"]);
                result.push_back(device);
            }
        }
        return result;
    }

    void SetHeartbeatReport(list<int> pulseList)
    {
        DynamicJsonDocument doc(1024);
        String data = "{\"data\":";
        for (int pulse : pulseList)
        {
            data = data + String(pulse) + ",";
        }
        data = data + "}";
        
        HttpResponse response = restClient.Request(baseUrl + "report/setHeartBeat",
                                                   HTTPMethod::POST,
                                                   data);

        if (response.HttpCode == 200)
        {
            Serial.println("Information submitted successfully.");
        }
        else
        {
            Serial.println(String(response.HttpCode) + " - " + response.Content);
        }
    }
};
#define _MYHEADER_H_
#endif