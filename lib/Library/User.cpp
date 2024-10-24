#include "User.h"
#include <iostream>
#include <algorithm>

User::User(const std::string& id, const std::string& name) : userID(id), userName(name) {}

std::string User::getUserID() const {
    return userID;
}

std::string User::getUserName() const {
    return userName;
}

void User::borrowBook(const std::string& bookID) {
    borrowedBooks.push_back(bookID);
}

void User::returnBook(const std::string& bookID) {
    auto it = std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookID);
    borrowedBooks.erase(it, borrowedBooks.end());
}

void User::listBorrowedBooks() const {
    std::cout << "Borrowed Books by " << userName << ":\n";
    for (const auto& bookID : borrowedBooks) {
        std::cout << bookID << "\n";
    }
}
