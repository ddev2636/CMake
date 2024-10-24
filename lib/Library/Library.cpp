#include "Library.h"
#include <algorithm>
#include <iostream>

// Add a book to the library
void Library::addBook(const Book& book) {
    books.push_back(book);
}

// Remove a book from the library by ID
void Library::removeBook(const std::string& bookID) {
    auto it = std::remove_if(books.begin(), books.end(), [&bookID](const Book& book) {
        return book.getBookID() == bookID;
    });
    books.erase(it, books.end());
}

// Find a book by ID and return a pointer to it
Book* Library::findBook(const std::string& bookID) {
    for (auto& book : books) {
        if (book.getBookID() == bookID) {
            return &book; // Return a pointer to the found book
        }
    }
    throw std::runtime_error("Book not found: " + bookID); // Return nullptr if not found
}

// Register a new user in the library
void Library::registerUser(const User& user) {
    users.push_back(user);
}

// Remove a user from the library by ID
void Library::removeUser(const std::string& userID) {
    auto it = std::remove_if(users.begin(), users.end(), [&userID](const User& user) {
        return user.getUserID() == userID;
    });
    users.erase(it, users.end());
}

// Borrow a book from the library by user ID
void Library::borrowBook(const std::string& bookID, const std::string& userID) {
    Book* book = findBook(bookID);
    if (!book) {
        std::cout << "Book not found.\n";
        return;
    }
    
    for (auto& user : users) {
        if (user.getUserID() == userID) {
            if (book->isAvailable()) {
                user.borrowBook(bookID);
                book->setAvailability(false);
                std::cout << user.getUserName() << " borrowed " << book->getTitle() << ".\n";
            } else {
                std::cout << "Book is not available for borrowing.\n";
            }
            return;
        }
    }
    std::cout << "User not found.\n";
}

// Return a book to the library by user ID
void Library::returnBook(const std::string& bookID, const std::string& userID) {
    for (auto& user : users) {
        if (user.getUserID() == userID) {
            user.returnBook(bookID);
            Book* book = findBook(bookID);
            if (book) {
                book->setAvailability(true);
                std::cout << user.getUserName() << " returned " << book->getTitle() << ".\n";
            }
            return;
        }
    }
    std::cout << "User not found.\n";
}

// List all books available in the library
void Library::listBooks() const {
    std::cout << "Available Books:\n";
    for (const auto& book : books) {
        std::cout << book.getTitle() << " (ID: " << book.getBookID() << ")\n";
    }
}

// List all registered users in the library
void Library::listUsers() const {
    std::cout << "Registered Users:\n";
    for (const auto& user : users) {
        std::cout << user.getUserName() << " (ID: " << user.getUserID() << ")\n";
    }
}
