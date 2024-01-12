/*
InputHandle.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

#include "../header/InputHandle.h"
#include <string>
#include <iostream>
#include <limits>
#include <regex>

//Function to get a correct string input from the user.
std::string getStringInput(std::string prompt) {
    std::string input;
    //Specifc choosen regex for emaila address to be real
    std::regex emailRegex(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)");
    //Specific choosen regex for names to be real. Names must contain only letters and single spaces between words.
    std::regex nameRegex(R"((^[A-Za-z]+)( [A-Za-z]+)*$)"); 

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        //Validates
        if (!std::cin.fail()) {
            if (prompt.find("email") != std::string::npos && !std::regex_match(input, emailRegex)) {
                std::cout << "Invalid email format. Please try again.\n";
                continue;
            } else if (prompt.find("name") != std::string::npos && !std::regex_match(input, nameRegex)) {
                std::cout << "Invalid name. Names must contain only letters and single spaces between words. Please try again.\n";
                continue;
            }
            return input;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again.\n";
    }
}

//Function to get a correct integer input from the user.
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


