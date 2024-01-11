#include <string>
#include <vector>
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include <iostream>
#include "glob.h"
#include "fileread.h"

std::vector<Member> memberList;
std::vector<Book> libraryBooks;

int main()
{
    Librarian librarian(1, 5000, "Librarian Name", "Librarian Address", "librarian@email.com");

    std::string file;
    std::cout << "Welcome, Librarian!" << std::endl;
    std::cout << "Please enter the filename for the library books: ";
    std::getline(std::cin, file);
    libraryBooks = readBooks(file);

    int memberID;
    int bookID;

    while (true)
    {
        std::cout << "\nWhat would you like to do next?" << std::endl;
        std::cout << "1. Add a Member" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "3. Display Members" << std::endl;
        std::cout << "4. Issue Book" << std::endl;
        std::cout << "5. Display Borrowed Books" << std::endl;
        std::cout << "6. Return Book" << std::endl;
        std::cout << "Enter your choice: ";

        int choice = getIntInput("");

        switch(choice)
        {
            case 1:
                librarian.addMember();
                break;
            case 2:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            case 3:
                librarian.displayMembers();
                break;
            case 4:
                memberID = getIntInput("Enter member ID: ");
                bookID = getIntInput("Enter book ID: ");
                librarian.issueBook(memberID, bookID);
                break;
            case 5:
                memberID = getIntInput("Enter member ID: ");
                librarian.displayBorrowedBooks(memberID);
                break;
            case 6:
                memberID = getIntInput("Enter member ID for the book return: ");
                bookID = getIntInput("Enter book ID for the book return: ");
                librarian.returnBook(memberID, bookID);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
