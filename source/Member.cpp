/*
Member.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

#include "../header/Member.h"
#include "../header/Book.h"

//Constructor
Member::Member(int memberID, std::string name, std::string address, std::string email)
{
    setName(name);
    this->memberID = memberID;
    setAddress(address);
    setEmail(email);
}
Member::Member()
{
}
std::string Member::getMemberID()
{
    return std::to_string(memberID); 
}

std::vector<Book> &Member::getBooksBorrowed()
{
    return this->booksLoaned;
}

void Member::setBooksBorrowed(Book book)
{
    this->booksLoaned.push_back(book);
}
