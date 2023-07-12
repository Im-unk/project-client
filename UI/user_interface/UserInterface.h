#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "user_interface/ConsoleUI.h" // Assuming you have implemented the ConsoleUI class
#include "user_interface/GUI.h" // Assuming you have implemented the GUI class
#include "infraustructure/api/ApiClient.h"

class UserInterface {
public:
    static void start();
};

void UserInterface::start() {
    // Create an instance of the desired UI class
    // For example, if you want to use the console-based UI:
    ConsoleUI consoleUI;

    // Alternatively, if you want to use the GUI-based UI:
    // GUI gui;

    bool exit = false; // Assign a default value
    user user; // Declare the User variable outside the switch statement

    do {
        // Display the menu
        consoleUI.displayMenu();

        // Get user choice
        int choice = consoleUI.getUserChoice();

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                // Add User
                {
                    // user user = consoleUI.getUserInput(); // Get user input from the UI
                    // std::string serializedUser = userSerializer.serialize(user); // Serialize user object to JSON

                    // Make API call to add user
                    // Example using cURL:
                    // apiClient.post("/users", serializedUser);
                    std::cout << "User added successfully." << std::endl;
                }
                break;
            case 2:
                // Display User
                {
                    // int userId = consoleUI.getUserIdInput(); // Get user ID from the UI

                    // Make API call to get user by ID
                    // Example using cURL:
                    // std::string response = apiClient.get("/users/" + std::to_string(userId));

                    // Deserialize JSON response to User object
                    // user user = userSerializer.deserialize(response);

                    // Display user details
                    consoleUI.displayUser(user);
                }
                break;
            case 3:
                // Exit
                exit = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (!exit);
}

#endif /* USERINTERFACE_H */
