#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <iostream>
#include <string>
#include <limits>
#include "model/user.h" // Assuming you have a User data model

class ConsoleUI {
public:
    static void displayMenu();
    static int getUserChoice();
    static user getUserInput();
    static void displayUser(const user& user);
};

void ConsoleUI::displayMenu() {
    std::cout << "=== Menu ===" << std::endl;
    std::cout << "1. Add User" << std::endl;
    std::cout << "2. Display User" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "============" << std::endl;
}

int ConsoleUI::getUserChoice() {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    return choice;
}

user ConsoleUI::getUserInput() {
    user user;

    int userID;
    std::cout << "Enter user ID: ";
    std::cin >> userID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    user.setID(userID);

    std::cin.ignore(); // Ignore the newline character

    std::string fullName;
    std::cout << "Enter user full name: ";
    std::getline(std::cin, fullName);
    user.setFullName(fullName);

    std::string userName;
    std::cout << "Enter user username: ";
    std::getline(std::cin, userName);
    user.setUserName(userName);

    std::string email;
    std::cout << "Enter user email: ";
    std::getline(std::cin, email);
    user.setEmail(email);

    return user;
}
void ConsoleUI::displayUser(const user& user) {
    std::cout << "=== User Details ===" << std::endl;
    std::cout << "ID: " << user.getID() << std::endl;
    std::cout << "Full Name: " << user.getFullName() << std::endl;
    std::cout << "Username: " << user.getUserName() << std::endl;
    std::cout << "Email: " << user.getEmail() << std::endl;
    std::cout << "====================" << std::endl;
}

#endif /* CONSOLE_UI_H */
