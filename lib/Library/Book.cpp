#include "Book.h"

Book::Book(const std::string& id, const std::string& title, const std::string& author)
    : bookID(id), title(title), author(author), available(true) {}

std::string Book::getBookID() const {
    return bookID;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

bool Book::isAvailable() const {
    return available;
}

void Book::setAvailability(bool status) {
    available = status;
}
