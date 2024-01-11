#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <vector>

class Book;

class Member : public Person
{
private:
    int memberID;
    std::vector<Book> booksLoaned;

public:
    Member();
    Member(int memberID, std::string name, std::string address, std::string email);
    std::string getMemberID();
    std::vector<Book> &getBooksBorrowed();
    void setBooksBorrowed(Book book);
};

#endif