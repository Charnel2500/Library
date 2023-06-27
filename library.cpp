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

void Library::findBookByTitle(const std::string& title) {
    std::vector<Book> foundBooks;

    for (const Book& book : books) {
        if (book.getTitle() == title) {
            foundBooks.push_back(book);
        }
    }

    if (foundBooks.empty()) {
        std::cout << "No books with the given title found in the library." << std::endl;
    } else {
        std::cout << "Books found in the library:" << std::endl;
        for (const Book& book : foundBooks) {
            std::cout << "Title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Year: " << book.getYear() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

void Library::findBookByAuthor(const std::string& author) {
    std::vector<Book> foundBooks;

    for (const Book& book : books) {
        if (book.getAuthor() == author) {
            foundBooks.push_back(book);
        }
    }

    if (foundBooks.empty()) {
        std::cout << "No books with the given author found in the library." << std::endl;
    } else {
        std::cout << "Books found in the library:" << std::endl;
        for (const Book& book : foundBooks) {
            std::cout << "Title: " << book.getTitle() << std::endl;
            std::cout << "Author: " << book.getAuthor() << std::endl;
            std::cout << "Genre: " << book.getGenre() << std::endl;
            std::cout << "Year: " << book.getYear() << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }
}

void Library::borrowBook(const std::string& title, Reader& reader) {
    auto it = std::find_if(books.begin(), books.end(),
        [&](const Book& book) { return book.getTitle() == title && book.getReaderId() == 0; });

    if (it != books.end()) {
        it->setReaderId(reader.getId());
        reader.borrowBook(*it);

        std::cout << "Book \"" << it->getTitle() << "\" borrowed successfully by reader with ID: " << reader.getId() << std::endl;
    } else {
        std::cout << "Book \"" << title << "\" is not available for borrowing." << std::endl;
    }
}

void Library::returnBook(const std::string& title, Reader& reader) {
    auto it = std::find_if(books.begin(), books.end(),
        [&](const Book& book) { return book.getTitle() == title && book.getReaderId() == reader.getId(); });

    if (it != books.end()) {
        it->setReaderId(0);
        reader.returnBook(*it);

        std::cout << "Book \"" << it->getTitle() << "\" returned successfully by reader with ID: " << reader.getId() << std::endl;
    } else {
        std::cout << "Book \"" << title << "\" was not borrowed by reader with ID: " << reader.getId() << std::endl;
    }
}
