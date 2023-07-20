#include "book.h"
#include "library.h"
#include <iostream>

int main() {
    Library library;
    library.loadReadersFromFile("readers.txt");
    library.loadBooksFromFile("books.txt");
    library.libraryDescription();
    std::string title, author, genre;
    int year, numberOfBooks, readerId;

    library.menu();
    library.saveReadersToFile("readers.txt");
    library.saveBooksToFile("books.txt");

    return 0;
}
