#include "fileread.h"

std::vector<Book> readBooks(std::string libraryBooks) {
    std::vector<Book> books; 
    std::ifstream file(libraryBooks);
    std::string line;

    
    getline(file, line);

    while (getline(file, line)) {
        std::vector<std::string> tokens;
        std::string token;
        bool inQuotes = false;

        for (char ch : line) {
            if (ch == '"') {
                inQuotes = !inQuotes; 
            } else if (ch == ',' && !inQuotes) {
                
                tokens.push_back(token);
                token.clear();
            } else {
                
                token += ch;
            }
        }
        
        tokens.push_back(token);

        
        if (tokens.size() >= 5) {
            int bookID = std::stoi(tokens[0]);
            std::string bookName = tokens[1];

            std::string authorFirstName = tokens[3];
            std::string authorLastName = tokens[4];

            books.emplace_back(bookID, bookName, authorFirstName, authorLastName);
        }
    }

    return books;
}
