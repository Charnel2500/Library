#include "reader.h"

Reader::Reader(const std::string& firstName, const std::string& surname, char gender, int dayOfBirth, int monthOfBirth, int yearOfBirth)
    : firstName(firstName), surname(surname), gender(gender), dayOfBirth(dayOfBirth), monthOfBirth(monthOfBirth), yearOfBirth(yearOfBirth) {}

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
