#define CATCH_CONFIG_MAIN
#include "../header/catch.hpp"
#include "../header/Librarian.h"
#include "../header/Book.h"
#include "../header/Member.h"
#include "../header/glob.h"

/*
tests.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

// Function prototypes for the mocked functions
std::string getStringInput(const std::string &prompt);
int getIntInput(const std::string &prompt);

// The tests
TEST_CASE("Full Program Flow", "[full_flow]")
{


    // Create a librarian
    Librarian librarian(1, 5000, "Test Librarian", "123 Library Lane", "librarian@test.com");

    // Mocked input/output functions

    // Run the test cases
    REQUIRE(memberList.empty());
    REQUIRE(libraryBooks.empty());

    // Add a member
    librarian.addMember();
    REQUIRE(memberList.size() == 1);
    REQUIRE(memberList.at(0).getName() == "name");

    // Add a book
    Book testBook(1, "Test Book", "Author", "Last Name");
    libraryBooks.push_back(testBook);
    REQUIRE(libraryBooks.size() == 1);

    // Issue the book to the member
    librarian.issueBook(1, 1);
    REQUIRE(memberList.at(0).getBooksBorrowed().size() == 1);
    REQUIRE(memberList.at(0).getBooksBorrowed().at(0).getbookID() == "1");

    // Return the book
    librarian.returnBook(1, 1);
    REQUIRE(memberList.at(0).getBooksBorrowed().empty());

    // Display borrowed books
    librarian.displayBorrowedBooks(1);

    // Calculate fines
    librarian.calcFine(1);

    // Clear the vectors
    memberList.clear();
    libraryBooks.clear();
}


std::string getStringInput(const std::string &prompt)
{
    if (prompt.find("name") != std::string::npos)
    {
        return "name";
    }
    else if (prompt.find("address") != std::string::npos)
    {
        return "123 Main";
    }
    else if (prompt.find("email") != std::string::npos)
    {
        return "name@gmail.com";
    }
    return "";
}

int getIntInput(const std::string &prompt)
{
    return 1;
}
