#include "reader.h"

Reader::Reader(int id, const std::string& firstName, const std::string& surname, char gender, int dayOfBirth, int monthOfBirth, int yearOfBirth)
    : id(id), firstName(firstName), surname(surname), gender(gender), dayOfBirth(dayOfBirth), monthOfBirth(monthOfBirth), yearOfBirth(yearOfBirth) {}

int Reader::getId() const {
    return id;
}
    
const std::string& Reader::getFirstName() const {
    return firstName;
}

const std::string& Reader::getSurname() const {
    return surname;
}

char Reader::getGender() const {
    return gender;
}

int Reader::getDayOfBirth() const {
    return dayOfBirth;
}

int Reader::getMonthOfBirth() const {
    return monthOfBirth;
}

int Reader::getYearOfBirth() const {
    return yearOfBirth;
}

void Reader::borrowBook(const Book& book) {
    borrowedBooks.push_back(book);
}

void Reader::returnBook(const Book& book) {
    borrowedBooks.erase(std::remove_if(borrowedBooks.begin(), borrowedBooks.end(),
        [&](const Book& b) { return b.getTitle() == book.getTitle(); }),
        borrowedBooks.end());
}
