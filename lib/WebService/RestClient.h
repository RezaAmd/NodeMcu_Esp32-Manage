#ifndef BINTREE_H_
#define BINTREE_H_

#include <HTTPClient.h>
#include <list>
#include <string.h>
#include <iostream>
using namespace std;

#define NO_OF_TEST 1

HTTPClient client;

struct HttpResponse
{
public:
    int HttpCode;
    String Content;
};

enum HTTPMethod
{
    GET,
    POST,
    PUT,
    PATCH
};

class RestClient
{
    public:
    HttpResponse Request(String url, HTTPMethod method = HTTPMethod::GET, String body = "")
{
    HttpResponse response;
    client.begin(url);
    if (method == HTTPMethod::POST)
    {
        client.addHeader("Content/Type", "text/plain");
        response.HttpCode = client.POST(body);
    }
    else if (method == HTTPMethod::PUT)
    {
        response.HttpCode = client.PUT(body);
    }
    else if (method == HTTPMethod::PATCH)
    {
        response.HttpCode = client.PATCH(body);
    }
    else
    {
        response.HttpCode = client.GET();
    }
    response.Content = client.getString();
    return response;
}
};


#endif