/*
Librarian.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/


#include "../header/Librarian.h"
#include "../header/Date.h"
#include "../header/Member.h"
#include "../header/glob.h"
#include "../header/fileread.h"
#include "../header/Book.h"
#include "../header/InputHandle.h"

Librarian::Librarian(int staffID, int salary, std::string name, std::string address, std::string email)
{
    this->staffID = staffID;
    this->salary = salary;
    setName(name);
    setAddress(address);
    setEmail(email);
}

void Librarian::addMember()
{
    std::string name = getStringInput("Enter name: ");
    std::string address = getStringInput("Enter address: ");
    std::string email = getStringInput("Enter email: ");
    int memberID = memberList.size() + 1;

    Member newMember(memberID, name, address, email);
    memberList.push_back(newMember);
}

void Librarian::issueBook(int memberID, int bookID)
{
    // Find the member by ID
    auto member_it = std::find_if(memberList.begin(), memberList.end(), [memberID](Member member)
                                  {
                                      return member.getMemberID() == std::to_string(memberID); // returns string
                                  });

    // Find the book by ID
    auto book_it = std::find_if(libraryBooks.begin(), libraryBooks.end(), [bookID](Book book)
                                {
                                    return book.getbookID() == std::to_string(bookID); // getBookID returns a string
                                });

    if (member_it != memberList.end() && book_it != libraryBooks.end())
    {
        int dueDay, dueMonth, dueYear;
        std::cout << "Enter due date (dd mm yyyy): ";
        std::cin >> dueDay >> dueMonth >> dueYear;
        Date dueDate(dueDay, dueMonth, dueYear);

        book_it->setDueDate(dueDate);
        // Add the book to the member's loaned books
        member_it->setBooksBorrowed(*book_it);
        std::cout << "Book with ID " << bookID << " issued to member with ID " << memberID << "." << std::endl;
    }
    else
    {
        std::cout << "Member ID " << memberID << " or Book ID " << bookID << " not found." << std::endl;
    }
}

void Librarian::displayMembers()
{
    std::cout << "Members List:" << std::endl;
    for (auto &member : memberList)
    {
        std::cout << "Name: " << member.getName()
                  << " Address: " << member.getAddress()
                  << " Email: " << member.getEmail() << std::endl
                  << "Member ID: " << member.getMemberID() << std::endl;
    }
}

void Librarian::returnBook(int memberID, int bookID)
{
    // Find the member by ID
    for (auto &member : memberList)
    {
        if (std::stoi(member.getMemberID()) == memberID)
        {
            // Member found
            auto &booksLoaned = member.getBooksBorrowed(); 

            // Find the book by ID within the member's loaned books
            auto it = std::remove_if(booksLoaned.begin(), booksLoaned.end(), [bookID](Book &b)
                                     { return std::stoi(b.getbookID()) == bookID; });

            // If a book was found, remove it and calculate the fine
            if (it != booksLoaned.end())
            {
                Date currentDate = Date::getCurrentDate(); // Use the static method to get the current date
                Date dueDate = it->getDueDate();
                int daysLate = currentDate.differenceInDays(dueDate);

                if (daysLate > 0)
                {
                    int fine = daysLate * 1; // £1 fine for each day late
                    std::cout << "Book with ID " << bookID << " has been returned by member with ID " << memberID << "." << std::endl;
                    std::cout << "Fine for late return: £" << fine << std::endl;
                }
                else
                {
                    std::cout << "Book with ID " << bookID << " has been returned by member with ID " << memberID << "." << std::endl;
                }

                booksLoaned.erase(it, booksLoaned.end()); // Remove the book(s) from the vector
            }
            else
            {
                std::cout << "No book with ID " << bookID << " found in member's borrowed books." << std::endl;
            }
            return; // Exit the function because the member was found
        }
    }

    std::cout << "Member with ID " << memberID << " not found." << std::endl;
}

void Librarian::displayBorrowedBooks(int memberID)
{
    auto member_it = std::find_if(memberList.begin(), memberList.end(), [memberID](Member m)
                                  { return std::stoi(m.getMemberID()) == memberID; });

    if (member_it != memberList.end())
    {
        auto booksBorrowed = member_it->getBooksBorrowed();
        if (booksBorrowed.empty())
        {
            std::cout << "No books borrowed by member " << memberID << "." << std::endl;
        }
        else
        {
            std::cout << "Books borrowed by member " << memberID << ":" << std::endl;
            for (auto book : booksBorrowed)
            {
                std::cout << "Book ID: " << book.getbookID()
                          << ", Title: " << book.getbookName()
                          << ", Author: " << book.getauthorFirstName() << " " << book.getauthorLastName()
                          << std::endl;
            }
        }
    }
    else
    {
        std::cout << "No member found with ID " << memberID << std::endl;
    }
}

void Librarian::calcFine(int memberID)
{
    // Find the member by ID
    auto member_it = std::find_if(memberList.begin(), memberList.end(), [memberID](Member m)
                                  { return std::stoi(m.getMemberID()) == memberID; });

    if (member_it != memberList.end())
    {
        int totalFine = 0;
        Date currentDate = Date::getCurrentDate(); // Use the static method to get the current date

        for (auto book : member_it->getBooksBorrowed())
        {
            Date dueDate = book.getDueDate();
            int daysLate = currentDate.differenceInDays(dueDate);

            if (daysLate > 0)
            {
                int fine = daysLate * 1; // £1 fine for each day late
                totalFine += fine;
            }
        }

        std::cout << "Total fines for member " << memberID << ": £" << totalFine << std::endl;
    }
    else
    {
        std::cout << "No member found with ID " << memberID << std::endl;
    }
}
