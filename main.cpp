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
    std::string file = "library_books.csv";
    libraryBooks = readBooks(file);

    int memberID;
    int bookID;

    std::cout << "Welcome, Librarian!" << std::endl;

    while (true)
    {

        std::cout << "What would you like to do next?" << std::endl;
        std::cout << "1. Add a Member" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "3. Display Members" << std::endl;
        std::cout << "4. Issue Book" << std::endl;
        std::cout << "5. Display Borrowed book" << std::endl;
        std::cout << "6. Return Book" << std::endl;
        std::cout << "Enter your choice: ";

        int choice = getIntInput("");

        if (choice == 1)
        {
            librarian.addMember();
        }
        else if (choice == 2)
        {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        else if (choice == 3)
        {
            librarian.displayMembers();
        }
        else if (choice == 4)
        {
            memberID = getIntInput("Enter member ID: ");
            bookID = getIntInput("Enter book ID: ");
            librarian.issueBook(memberID, bookID);
        }
        else if (choice == 5)
        {
            std::cout << "Enter member ID: ";
            std::cin >> memberID;
            librarian.displayBorrowedBooks(memberID);
        }
        else if (choice == 6)
        {
            std::cout << "Enter member ID for the book return: ";
            std::cin >> memberID;
            std::cout << "Enter book ID for the book return: ";
            std::cin >> bookID;
            librarian.returnBook(memberID, bookID);
        }
        else
        {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
