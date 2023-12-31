#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre; //Novel, Fiction, Mystery, Fantasy, Sci-fi, Romance, Horror, Biography, Autobiography, Travel, Poetry, Drama
    int year;
    int readerId;

public:
    Book(const std::string& title, const std::string& author, std::string genre, int year, int readerId);
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    std::string getGenre() const;
    int getYear() const;
    int getReaderId() const;
    void setReaderId(int id);
};

#endif

