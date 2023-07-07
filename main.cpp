#include "book.h"
#include "library.h"
#include <iostream>

int main() {
    Library library;
    library.libraryDescription();
    std::string title, author, genre;
    int year, numberOfBooks, readerId;

    library.menu();


    return 0;
}
