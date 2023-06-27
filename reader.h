#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include <algorithm>
#include "book.h"

class Reader {
private:
    int id;
    std::string firstName;
    std::string surname;
    char gender; // m or f
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;
    std::vector<Book> borrowedBooks;

public:
    Reader(int id, const std::string& firstName, const std::string& surname, char gender, int dayOfBirth, int monthOfBirth, int yearOfBirth);
    int getId() const;
    const std::string& getFirstName() const;
    const std::string& getSurname() const;
    char getGender() const;
    int getDayOfBirth() const;
    int getMonthOfBirth() const;
    int getYearOfBirth() const;
    void borrowBook(const Book& book);
    void returnBook(const Book& book);
};

#endif
