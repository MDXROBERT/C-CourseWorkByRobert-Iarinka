#ifndef PERSON_H 
#define PERSON_H 

#include <string>

class Person {
private:
    std::string name;
    std::string address;
    std::string email;

public:
    // Mutators
    void setName(std::string name);
    void setAddress(std::string address);
    void setEmail(std::string email);

    // Accessors
    std::string getName();
    std::string getAddress();
    std::string getEmail();
};

#endif 