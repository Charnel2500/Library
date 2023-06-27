#include "book.h"
#include "library.h"
#include <iostream>

int main() {
    Library library;
    
    std::string title, author, genre;
    int year, numberOfBooks, readerId;

    std::cout << "How many books do you want to add?" << std::endl;
    std::cin >> numberOfBooks;
    std::cin.ignore(); 
    
    while (numberOfBooks) {
        std::cout << "Enter book details (title, author, genre, year):" << std::endl;
        std::cout << "Title: ";
        std::getline(std::cin, title);

        if (title.empty())
            break;

        std::cout << "Author: ";
        std::getline(std::cin, author);
        
        std::cout << "Genre (Novel, Fiction, Mystery, Fantasy, Sci-fi, Romance, Horror, Biography, Autobiography, Travel, Poetry, Drama): ";
        std::getline(std::cin, genre);

        std::cout << "Year: ";
        std::cin >> year;
        std::cin.ignore(); // Ignorowanie znaku nowej linii w buforze wejściowym

        Book book(title, author, genre, year, readerId);
        library.addBook(book);
        numberOfBooks--;
    }

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925, 0);
    Book book2("To Kill a Mockingbird", "Harper Lee", "Fantasy", 1960, 0);
    Book book3("1984", "George Orwell", "Drama", 1949, 0);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.displayBooks();

    library.removeBook("To Kill a Mockingbird");

    std::cout << "After removing a book:" << std::endl;
    library.displayBooks();

    return 0;
}
