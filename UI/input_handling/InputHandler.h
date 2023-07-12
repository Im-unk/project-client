#pragma once

#include <iostream>
#include <limits>
#include <string>

class InputHandler {
public:
    static int getIntInput(const std::string& prompt) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value) {
                // Input is valid
                break;
            } else {
                // Clear the input stream and ignore any remaining characters
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            }
        }
        return value;
    }

    static std::string getStringInput(const std::string& prompt) {
        std::string value;
        std::cout << prompt;
        std::getline(std::cin >> std::ws, value);
        return value;
    }

    static bool getYesNoInput(const std::string& prompt) {
        std::string value;
        while (true) {
            std::cout << prompt << " (Y/N): ";
            std::getline(std::cin >> std::ws, value);
            if (value == "Y" || value == "y") {
                return true;
            } else if (value == "N" || value == "n") {
                return false;
            } else {
                std::cout << "Invalid input. Please enter Y or N." << std::endl;
            }
        }
    }
};
