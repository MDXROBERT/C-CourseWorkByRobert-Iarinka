/*
fileread.cpp
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/

#include "../header/fileread.h"
#include "../header/Book.h"

std::vector<Book> readBooks(std::string libraryBooks)
{
    std::vector<Book> books;
    //Opens the file
    std::ifstream file(libraryBooks);
    std::string line;

    getline(file, line);

//Reads the file line by line
    while (getline(file, line))
    {
        std::vector<std::string> tokens;
        std::string token;
        bool inQuotes = false;
        //Goes through each character in a line 
        for (char ch : line)
        {
            if (ch == '"')
            {
                inQuotes = !inQuotes;
            }
            else if (ch == ',' && !inQuotes)
            {

                tokens.push_back(token);
                token.clear();
            }
            else
            {

                token += ch;
            }
        }

        tokens.push_back(token);
        //Cheks if there are enough tokens 
        if (tokens.size() >= 5)
        {
            int bookID = std::stoi(tokens[0]);
            std::string bookName = tokens[1];

            std::string authorFirstName = tokens[3];
            std::string authorLastName = tokens[4];

            books.emplace_back(bookID, bookName, authorFirstName, authorLastName);
        }
    }

    return books;
}
