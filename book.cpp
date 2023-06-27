#include "book.h"


Book::Book(const std::string& title, const std::string& author, std::string genre, int year, int readerId)
    : title(title), author(author), genre(genre), year(year), readerId(readerId) {}

const std::string& Book::getTitle() const {
    return title;
}

const std::string& Book::getAuthor() const {
    return author;
}

std::string Book::getGenre() const {
    return genre;
}

int Book::getYear() const {
    return year;
}

int Book::getReaderId() const {
    return readerId;
}

void Book::setReaderId(int id) {
    readerId = id;
}

