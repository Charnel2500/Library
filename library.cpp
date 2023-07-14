#include "library.h"
#include <iostream>
#include <algorithm>

void Library::libraryDescription() {
    #include <iostream>
    // Library description
    std::string infoLibrary = "Discover the Power of Knowledge at Our Library!\n"
                                     "\n"
                                     "Welcome to our exceptional library, where the world of books comes alive. "
                                     "Step into a realm of imagination, information, and inspiration, where stories unfold "
                                     "and knowledge flourishes. We invite you to embark on a captivating journey through "
                                     "the vast collection of books, ready to ignite your mind and broaden your horizons.\n"
                                     "\n"
                                     "At our library, we believe that books hold the key to endless possibilities. "
                                     "Whether you seek an escape into distant lands, a dive into historical events, "
                                     "or a plunge into the depths of science, our shelves are lined with treasures "
                                     "waiting to be explored. From gripping novels to enlightening non-fiction, "
                                     "we have something for everyone.\n"
                                     "\n"
                                     "Immerse yourself in the soothing ambiance of our reading corners, where "
                                     "you can lose yourself in a captivating story or delve into thought-provoking "
                                     "ideas. Our library offers a serene haven, where you can find solace amidst "
                                     "the pages of a book, a sanctuary away from the hustle and bustle of daily life.\n"
                                     "\n"
                                     "But our library is more than just a home for books. It's a vibrant community "
                                     "of like-minded individuals who share a passion for learning and discovery. "
                                     "Engage in lively discussions, attend stimulating workshops, or participate "
                                     "in exciting events that bring literature to life. Connect with fellow book "
                                     "enthusiasts and forge lifelong friendships as you embark on this literary journey "
                                     "together.\n"
                                     "\n"
                                     "Our dedicated librarians are here to guide you, curating personalized recommendations "
                                     "and assisting you in finding that perfect book that speaks to your soul. They are "
                                     "the keepers of knowledge, ready to unlock the doors to new worlds and guide you "
                                     "through the vast expanse of literature.\n"
                                     "\n"
                                     "Join us in celebrating the joy of reading, the thrill of exploration, and the "
                                     "power of ideas. Come and experience the magic of our library, where stories come "
                                     "to life and dreams take flight. Open your mind, open a book, and let your "
                                     "imagination soar.\n"
                                     "\n"
                                     "Visit our library today and let the adventure begin!\n\n\n";

    std::cout << infoLibrary << std::endl;
}

void Library::addBook() {
    std::string title;
    std::string author;
    std::string genre;
    int year;

    // Pytanie użytkownika o dane książki
    std::cout << "Enter book's title: ";
    std::getline(std::cin >> std::ws, title);
    std::cout << "Enter book's author: ";
    std::getline(std::cin >> std::ws, author);
    std::cout << "Enter book's genre: ";
    std::getline(std::cin >> std::ws, genre);
    std::cout << "Enter book's year of publication: ";
    std::cin >> year;

    // Tworzenie obiektu książki i dodawanie do listy książek w bibliotece
    Book book(title, author, genre, year, 0);
    books.push_back(book);
}

void Library::addReader() {
    int id;
    std::string firstName;
    std::string surname;
    char gender;
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;

    // Asking about data
    std::cout << "Enter reader's ID: ";
    std::cin >> id;
    std::cout << "Enter reader's first name: ";
    std::cin >> firstName;
    std::cout << "Enter reader's surname: ";
    std::cin >> surname;
    std::cout << "Enter reader's gender (M/F): ";
    std::cin >> gender;
    std::cout << "Enter reader's day of birth: ";
    std::cin >> dayOfBirth;
    std::cout << "Enter reader's month of birth: ";
    std::cin >> monthOfBirth;
    std::cout << "Enter reader's year of birth: ";
    std::cin >> yearOfBirth;

    // Create reader object and add to list of readers in library
    Reader reader(id, firstName, surname, gender, dayOfBirth, monthOfBirth, yearOfBirth);
    readers.push_back(reader);
}

void Library::menu() {
    int choice = 1;
    do {
        std::cout << "Choose your action. 1. Add reader; 2. Add book; 3. Show list of readers. 4. Show list of books. 5. Exit." << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "You chose 1. Add reader." << std::endl;
                addReader();
                break;

            case 2:
                std::cout << "You chose 2. Add book" << std::endl;
                addBook();
                break;

            case 3:
                std::cout << "You chose 3. Show list of readers." << std::endl;
                displayReaders();
                break;

            case 4:
                std::cout << "You chose 4. Show list of books." << std::endl;
                displayBooks();
                break;
                
            case 5:
                std::cout << "You chose 5. Exit." << std::endl;
                displayBooks();
                break;
                
            default:
                std::cout << "Wrong number." << std::endl;
                break;
        }
    } while (choice != 5);
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
void Library::displayReaders() const {
    for (const Reader& reader : readers) {
        std::cout << "ID: " << reader.getId() << std::endl;
        std::cout << "First name: " << reader.getFirstName() << std::endl;
        std::cout << "Surname: " << reader.getSurname() << std::endl;
        std::cout << "Gender: " << reader.getGender() << std::endl;
        std::cout << "Day of birth: " << reader.getDayOfBirth() << std::endl;
        std::cout << "Month of birth: " << reader.getMonthOfBirth() << std::endl;
        std::cout << "Year of birth: " << reader.getYearOfBirth() << std::endl;        
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
