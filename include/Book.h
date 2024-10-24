#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string bookID;
    std::string title;
    std::string author;
    bool available;

public:
    Book(const std::string& id, const std::string& title, const std::string& author);
    
    std::string getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool isAvailable() const;
    void setAvailability(bool status);
};

#endif // BOOK_H
