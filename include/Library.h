#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include "Book.h"

class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const Book& book);
    void removeBook(const std::string& bookID);
    Book* findBook(const std::string& bookID);
    void registerUser(const User& user);
    void removeUser(const std::string& userID);
    void borrowBook(const std::string& bookID, const std::string& userID);
    void returnBook(const std::string& bookID, const std::string& userID);
    void listBooks() const;
    void listUsers() const;
};

#endif // LIBRARY_H
