#include <gtest/gtest.h>
#include "Library.h"
#include "User.h"
#include "Book.h"

// Test fixture for the Library Management System
class LibraryTest : public ::testing::Test {
protected:
    Library library;  // Instance of the Library class
    User user{"U001", "John Doe"};  // Sample User with ID
    Book book{"12345", "The Great Gatsby", "F. Scott Fitzgerald"};  // Sample Book

    void SetUp() override {
        // This method runs before each test
        library.addBook(book); // Adds a book for testing
        library.registerUser(user); // Registers the user for testing
    }

    void TearDown() override {
        // This method runs after each test
        // Clean up code can go here if needed
    }
};

// Test adding a book
TEST_F(LibraryTest, AddBook) {
    Book newBook{"67890", "1984", "George Orwell"};  // New book to add
    library.addBook(newBook);  // Call the method to add the book
    EXPECT_EQ(library.findBook("67890")->getTitle(), "1984");  // Verify it was added correctly
}

// Test finding a book
TEST_F(LibraryTest, FindBook) {
    Book* foundBook = library.findBook("12345");  // Find the existing book
    EXPECT_EQ(foundBook->getTitle(), "The Great Gatsby");  // Verify the correct book is returned
}

// Test removing a book
TEST_F(LibraryTest, RemoveBook) {
    library.removeBook("12345");  // Remove the book
    EXPECT_THROW(library.findBook("12345"), std::runtime_error);  // Check if trying to find it throws an exception
}

// Test user borrowing a book
TEST_F(LibraryTest, UserBorrowBook) {
    // Borrow the book for the registered user
    library.borrowBook("12345", user.getUserID());
    EXPECT_FALSE(library.findBook("12345")->isAvailable());  // Check if the book is no longer available
}

// Test user returning a book
TEST_F(LibraryTest, UserReturnBook) {
    // User borrows the book first
    library.borrowBook("12345", user.getUserID());
    // User returns the book
    library.returnBook("12345", user.getUserID());
    EXPECT_TRUE(library.findBook("12345")->isAvailable());  // Check if the book is available again
}
