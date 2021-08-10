#include <HTTPClient.h>

HTTPClient client;

class Arzcharge
{
private:
    const String baseUrl = "https://core.arzcharge.com/api/";
    String apiKey = "API_KEY";

public:
    String GetAllDevices()
    {
        client.begin(baseUrl + "device/getAll?token=" + apiKey);
        int httpCode = client.GET();
        if (httpCode == 200)
            return client.getString();
        return "";
    }
};