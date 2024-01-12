#ifndef PERSON_H
#define PERSON_H
/*
Person.h
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/
#include <string>

class Person
{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    void setName(std::string name);
    void setAddress(std::string address);
    void setEmail(std::string email);

    std::string getName();
    std::string getAddress();
    std::string getEmail();
};

#endif
