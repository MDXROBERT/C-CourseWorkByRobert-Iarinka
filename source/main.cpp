/*
main.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

#include <string>
#include <vector>
#include "../header/Book.h"
#include "../header/Member.h"
#include "../header/Librarian.h"
#include <iostream>
#include "../header/glob.h"
#include "../header/fileread.h"
#include "../header/InputHandle.h"


int main()
{
    // Create a librarian
    Librarian librarian(1, 5000, "Librarian Name", "Librarian Address", "librarian@email.com");

     std::string filename;
    std::cout << "Welcome, Librarian!" << std::endl;
    // Prompt the user to enter the filename for the library book
    std::cout << "Please enter the filename for the library books: ";
    std::getline(std::cin, filename);

    // Prepend "../" to the filename
    std::string filepath = "../" + filename;
    libraryBooks = readBooks(filepath);

    int memberID;
    int bookID;

    while (true)
    //Menu for librarian
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
        //Switch case for the menu

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
