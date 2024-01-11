#include "InputHandle.h"



std::string getStringInput(std::string prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!std::cin.fail()) {
            return input;
        }
      std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid input. Please try again.\n";
    }
}

int getIntInput(std::string prompt) {
    int input;
    while (true) {
     std::cout << prompt;
        if (std::cin >> input) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            return input;
        } else {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        }
    }
}


