#ifndef FILEREAD_H
#define FILEREAD_H
/*
fileread.h
Author M00862854
Created on 9 Jan 2024
Updated on 12 Jan 2024

*/
#include <fstream>
#include <sstream>
#include "vector"

class Book;

std::vector<Book> readBooks(std::string libraryBooks);

#endif // FILEREAD_H
