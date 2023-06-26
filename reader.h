#ifndef READER_H
#define READER_H

#include <string>

class Reader {
private:
    std::string firstName;
    std::string surname;
    char gender; // m or f
    int dayOfBirth;
    int monthOfBirth;
    int yearOfBirth;

public:
    Reader(const std::string& firstName, const std::string& surname, char gender, int dayOfBirth, int monthOfBirth, int yearOfBirth);
    const std::string& getFirstName() const;
    const std::string& getSurname() const;
    char getGender() const;
    int getDayOfBirth() const;
    int getMonthOfBirth() const;
    int getYearOfBirth() const;
};

#endif
