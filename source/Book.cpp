#include "../header/Book.h"
#include "../header/Member.h"
#include "../header/Date.h"
/*
Book.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

Book::Book(int bookID, std::string bookName, std::string authorFirstName, std::string authorLastName)
{
    this->bookID = bookID;
    this->bookName = bookName;
    this->authorFirstName = authorFirstName;
    this->authorLastName = authorLastName;
}

std::string Book::getbookID()
{
    return std::to_string(bookID);
}

std::string Book::getbookName()
{
    return this->bookName;
}

std::string Book::getauthorFirstName()
{
    return this->authorFirstName;
}

std::string Book::getauthorLastName()
{
    return this->authorLastName;
}

Date Book::getDueDate()
{
    return this->dueDate;
}

void Book::setDueDate(Date dueDate)
{
    this->dueDate = dueDate;
}

void Book::returnBook()
{
    this->borrower = Member();
}

void Book::borrowBook(Member borrower, Date dueDate)
{
    this->borrower = borrower;
    setDueDate(dueDate);
}