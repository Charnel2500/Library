#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "reader.h"
#include <vector>
#include <set>

class Library {
private:
    std::vector<Book> books;
    std::vector<Reader> readers;
    std::set<std::string> validGenres = {
    "Fiction", "Mystery", "Romance", "Fantasy", "Science Fiction",
    "Thriller", "Horror", "Adventure", "Historical Fiction",
    "Biography", "Self-Help", "Poetry", "Memoir", "Young Adult",
    "Dystopian", "Crime", "Humor", "Non-Fiction", "Paranormal",
    "Graphic Novel"
	};


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
    void saveReadersToFile(const std::string& filename) const;
    void loadReadersFromFile(const std::string& filename);
    void saveBooksToFile(const std::string& filename) const;
    void loadBooksFromFile(const std::string& filename);
};

#endif
