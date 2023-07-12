#pragma once

#include <iostream>
#include <string>

class PromptUtils {
public:
    static void displayPrompt(const std::string& prompt) {
        std::cout << prompt;
    }

    static void displayError(const std::string& error) {
        std::cerr << "Error: " << error << std::endl;
    }
};
