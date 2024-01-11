#include "Member.h"
#include "Book.h"

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
