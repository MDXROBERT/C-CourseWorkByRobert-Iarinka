#ifndef BOOK_H
#define BOOK_H
/*
Book.h
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/
#include "Member.h"
#include "Date.h"

#include <string>
#include <vector>

class Book
{
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    Date dueDate;
    Member borrower;

public:
    Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName);
    std::string getbookID();
    std::string getbookName();
    std::string getauthorFirstName();
    std::string getauthorLastName();
    Date getDueDate();
    void setDueDate(Date dueDate);
    void returnBook();
    void borrowBook(Member borrower, Date dueDate);
};

#endif
