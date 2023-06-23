#include "book.h"


Book::Book(const std::string& title, const std::string& author, std::string genre, int year)
    : title(title), author(author), genre(genre), year(year) {}

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
