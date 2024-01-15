#define CATCH_CONFIG_MAIN
#include "../header/catch.hpp"
#include "../header/Librarian.h"
#include "../header/Book.h"
#include "../header/Member.h"
#include "../header/glob.h"
#include "../header/Date.h"

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

TEST_CASE("Adding Multiple Members", "[member_management]")
{
    // Setup
    Librarian librarian(1, 5000, "Test Librarian", "123 Library Lane", "librarian@test.com");
    REQUIRE(memberList.empty());

    // Test adding multiple members
    librarian.addMember(); // Member with name "name"
    librarian.addMember(); // Member with name "another name"
    REQUIRE(memberList.size() == 2);
    REQUIRE(memberList.at(1).getName() == "another name"); 

    // Cleanup
    memberList.clear();
}

TEST_CASE("Issuing Book Not In Catalogue", "[issue_management]")
{
    // Setup
    Librarian librarian(1, 5000, "Test Librarian", "123 Library Lane", "librarian@test.com");
    librarian.addMember(); // Add a member for issuing
    REQUIRE(libraryBooks.empty());

    // Test issuing a book that does not exist
    librarian.issueBook(1, 999); // Non-existent bookID
    REQUIRE(memberList.at(0).getBooksBorrowed().empty()); // Member should not have any books issued

    // Cleanup
    memberList.clear();
}

TEST_CASE("Returning Book Not Borrowed", "[return_management]")
{
    // Setup
    Librarian librarian(1, 5000, "Test Librarian", "123 Library Lane", "librarian@test.com");
    librarian.addMember();
    REQUIRE(memberList.size() == 1);

    // Test returning a book that was never borrowed
    librarian.returnBook(1, 999); // Non-existent bookID
    REQUIRE(memberList.at(0).getBooksBorrowed().empty()); // Member should still have no books

    // Cleanup
    memberList.clear();
}

TEST_CASE("Calculating Fine for Late Returns", "[fine_calculation]")
{
    // Setup
    Librarian librarian(1, 5000, "Test Librarian", "123 Library Lane", "librarian@test.com");
    librarian.addMember();
    Book testBook(1, "Overdue Book", "Author", "Last Name");
    libraryBooks.push_back(testBook);

    // Mock current date to be after the due date
    Date::getCurrentDate(); 

    // Issue and return the book to generate a fine
    librarian.issueBook(1, 1); 
    librarian.returnBook(1, 1); 

    // Check that a fine was calculated
   

  
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

