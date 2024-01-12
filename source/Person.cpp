/*
Person.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

#include "../header/Person.h"

void Person::setName(std::string newName)
{
    this->name = newName;
}

void Person::setAddress(std::string newAddress)
{
    this->address = newAddress;
}

void Person::setEmail(std::string newEmail)
{
    this->email = newEmail;
}

std::string Person::getName()
{
    return this->name;
}

std::string Person::getAddress()
{
    return this->address;
}

std::string Person::getEmail()
{
    return this->email;
}
