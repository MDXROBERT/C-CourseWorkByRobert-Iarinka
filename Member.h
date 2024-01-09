#ifndef MEMBER_H
#define MEMBER_H
#include "Person.h"
#include "Book.h"
#include <string>
#include <vector>


class Member : public Person{
    private: int memberID;
    std::vector<Book> booksLoaned;
    public: Member(std::string name, std::string address, std::string email, int memberID); 
    std::string getMemberID();
    std::vector<Book> getBooksBorrowed();
    void setBooksBorrowed(Book book);
};

#endif 