#pragma once

#include <regex>
#include <string>

class ValidationUtils {
public:
    static bool isValidEmail(const std::string& email) {
        // Regular expression pattern for email validation
        const std::regex pattern(R"([\w\.-]+@([\w-]+\.)+[\w-]+)");

        return std::regex_match(email, pattern);
    }
};
