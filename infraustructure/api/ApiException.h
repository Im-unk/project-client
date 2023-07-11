#ifndef API_EXCEPTION_H
#define API_EXCEPTION_H

#include <stdexcept>
#include <string>

class ApiException : public std::runtime_error {
public:
    ApiException(const std::string& message, int statusCode)
        : std::runtime_error(message), m_statusCode(statusCode) {}

    int getStatusCode() const {
        return m_statusCode;
    }

private:
    int m_statusCode;
};

#endif /* API_EXCEPTION_H */
