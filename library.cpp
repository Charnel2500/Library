#include "library.h"
#include <iostream>
#include <algorithm>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& title) {
    books.erase(std::remove_if(books.begin(), books.end(),
        [&](const Book& book) { return book.getTitle() == title; }),
        books.end());
}

void Library::displayBooks() const {
    for (const Book& book : books) {
        std::cout << "Title: " << book.getTitle() << std::endl;
        std::cout << "Author: " << book.getAuthor() << std::endl;
        std::cout << "Genre: " << book.getGenre() << std::endl;
        std::cout << "Year: " << book.getYear() << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}
