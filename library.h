#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "reader.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;
    std::vector<Reader> readers;

public:
    void libraryDescription();
    void addBook();
    void addReader();
    void menu();
    void removeBook(const std::string& title);
    void displayBooks() const;
    void displayReaders() const;
    void findBookByTitle(const std::string& title);
    void findBookByAuthor(const std::string& author);
    void borrowBook(const std::string& title, Reader& reader);
    void returnBook(const std::string& title, Reader& reader);
};

#endif
