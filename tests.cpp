#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Librarian.h"
#include "Book.h"
#include "Member.h"
#include "glob.h"


std::vector<Member> memberList;
std::vector<Book> libraryBooks;

// Mocks
std::string getStringInput(const std::string& prompt) {
    if (prompt.find("name") != std::string::npos) {
        return "John Doe";
    } else if (prompt.find("address") != std::string::npos) {
        return "123 Main St";
    } else if (prompt.find("email") != std::string::npos) {
        return "john.doe@example.com";
    }
    return "";
}

int getIntInput(const std::string& prompt) {
    return 1;
}

TEST_CASE("Full Program Flow", "[full_flow]") {
    // Create a librarian
    Librarian librarian(1, 5000, "Test Librarian", "123 Library Lane", "librarian@test.com");

    // Add a member
    librarian.addMember();
    REQUIRE(memberList.size() == 1);
    REQUIRE(memberList.at(0).getName() == "test");

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

    // Reset global state after the test case
    memberList.clear();
    libraryBooks.clear();
}

