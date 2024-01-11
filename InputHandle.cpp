#include "InputHandle.h"
#include <string>
#include <iostream>
#include <limits>
#include <regex>

std::string getStringInput(std::string prompt) {
    std::string input;
    std::regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    std::regex nameRegex(R"([A-Za-z]+)"); 
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (!std::cin.fail()) {
            if (prompt.find("email") != std::string::npos && !std::regex_match(input, emailRegex)) {
                std::cout << "Invalid email format. Please try again.\n";
                continue;
            } else if (prompt.find("name") != std::string::npos && !std::regex_match(input, nameRegex)) {
                std::cout << "Invalid name. Names must contain only letters. Please try again.\n";
                continue;
            }
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


