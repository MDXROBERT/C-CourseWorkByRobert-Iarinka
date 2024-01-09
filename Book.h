#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "Member.h" 
#include "Date.h"



class Book{
private:
int bookID;
std::string bookName;
std::string aurthorFirstName;
std::string aurthorLastName;
std::string bookType;
Date dueDate;
Member borrower;

public:
Book(int bookID, std::string bookName, std::string aurthorFirstName, std::string aurthorLastName);
std::string getbookID();
std::string getbookName();
std::string getaurthorFirstName();
std::string getaurthorLastName();
Date getDueDate();
void setDueDate(Date dueDate);
void returnBook();
void borrowBook(Member borrower, Date dueDate);

};





#endif 