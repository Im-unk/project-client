#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <string>
#include <curl/curl.h>

class ApiClient {
public:
    ApiClient();
    ~ApiClient();

    // Perform a GET request
    std::string get(const std::string& url);

    // Perform a POST request
    std::string post(const std::string& url, const std::string& data);

    // Perform a PUT request
    std::string put(const std::string& url, const std::string& data);

    // Perform a PATCH request
    std::string patch(const std::string& url, const std::string& data);

    // Perform a DELETE request
    std::string del(const std::string& url);

private:
    CURL* m_curl;

    // Helper function for performing a request
    std::string performRequest(const std::string& url, const std::string& data, const std::string& method);
};

#endif /* API_CLIENT_H */
