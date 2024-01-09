#include "Person.h"


void Person::setName(std::string newName) {
    this->name = newName;
}

void Person::setAddress(std::string newAddress) {
    this->address = newAddress;
}

void Person::setEmail(std::string newEmail) {
   this->email = newEmail;
}


std::string Person::getName() {
    return this->name;
}

std::string Person::getAddress() {
    return this->address;
}

std::string Person::getEmail() {
    return this->email;
}
