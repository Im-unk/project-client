#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <string>

class MenuUtils {
public:
    static int displayMenu(const std::vector<std::string>& options) {
        int choice;
        int numOptions = options.size();

        std::cout << "Menu:" << std::endl;
        for (int i = 0; i < numOptions; i++) {
            std::cout << i + 1 << ". " << options[i] << std::endl;
        }

        while (true) {
            std::cout << "Enter your choice (1-" << numOptions << "): ";
            if (std::cin >> choice && choice >= 1 && choice <= numOptions) {
                break;
            } else {
                std::cout << "Invalid choice. Please enter a valid option number." << std::endl;
                clearInput();
            }
        }

        clearInput();
        return choice;
    }

private:
    static void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};
