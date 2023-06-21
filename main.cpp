#include "book.h"
#include "library.h"
#include <iostream>

int main() {
    Library library;

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);
    Book book3("1984", "George Orwell", 1949);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    library.removeBook("To Kill a Mockingbird");

    std::cout << "After removing a book:" << std::endl;
    library.displayBooks();

    return 0;
}
