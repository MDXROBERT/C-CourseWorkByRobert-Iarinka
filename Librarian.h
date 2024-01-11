#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "Person.h"
#include <vector>
#include "Book.h"
#include "Member.h"
#include "InputHandle.h"
#include "fileread.h"
#include "glob.h"
#include "Date.h"

extern std::vector<Book> libraryBooks;
class Librarian : public Person
{
private:
    int staffID;
    int salary;

public:
    Librarian(int staffID, int salary, std::string name, std::string address, std::string email);
    void addMember();
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calcFine(int memberID);
    int getStaffID();
    int setStaffID(int staffID);
    int getSalary();
    void setSalary(int salary);
    void displayMembers();
};
#endif
