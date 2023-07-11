#ifndef API_CONFIG_H
#define API_CONFIG_H

#include <string>

class ApiConfig {
public:
    static const std::string BASE_URL; // The base URL of the API
    static const std::string API_KEY;  // The API key or token

    // Other configuration properties as needed
};

const std::string ApiConfig::BASE_URL = "https://api.example.com";
const std::string ApiConfig::API_KEY = "your-api-key";

#endif /* API_CONFIG_H */

