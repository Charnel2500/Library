#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    void displayBooks() const;
    void findBook(const std::string& title);
};

#endif
