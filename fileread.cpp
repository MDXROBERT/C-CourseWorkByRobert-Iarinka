#include "fileread.h"

std::vector<Book> readBooks(std::string libraryBooks) {
    std::vector<Book> book; 
    std::ifstream file(libraryBooks);
    std::string line;
    getline(file, line); 

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        int bookID = std::stoi(tokens[0]);
        std::string bookName = tokens[1];
        
        std::string authorFirstName = tokens[3];
        std::string authorLastName = tokens[4];
        

        book.emplace_back(bookID, bookName, authorFirstName, authorLastName);
    }

    return book;
}
