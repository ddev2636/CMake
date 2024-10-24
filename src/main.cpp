/*
CMake Detailed Outline

Stage 1: A Basic Starting Point
1. Building a Basic Project
   - Understand project structure
   - Create a simple CMakeLists.txt
2. Specifying the C++ Standard
   - Learn how to set the C++ standard (e.g., C++11)
3. Adding a Version Number and Configured Header File
   - Specify project versioning
   - Learn about creating a config header file

Stage 2: Adding a Library
1. Creating a Library
   - Learn how to create a static library
2. Adding an Option
   - Understand how to create build options for your library

Stage 3: Adding Usage Requirements for a Library
1. Adding Usage Requirements for a Library
   - Learn how to define usage requirements for libraries
2. Setting the C++ Standard with Interface Libraries
   - Understand interface libraries and their usage

Stage 4: Adding Generator Expressions
1. Adding Compiler Warning Flags with Generator Expressions
   - Learn how to use generator expressions to customize builds

Stage 5: Installing and Testing
1. Install Rules
   - Learn how to define install rules for your project
2. Testing Support
   - Understand how to set up testing frameworks (e.g., Google Test)

Stage 6: Adding Support for a Testing Dashboard
1. Send Results to a Testing Dashboard
   - Learn how to integrate with CI/CD pipelines

Stage 7: Adding System Introspection
1. Assessing Dependency Availability
   - Understand how to check for dependencies in CMake

Stage 8: Adding a Custom Command and Generated File
1. Creating Custom Commands
   - Learn how to create custom build commands and generate files

Stage 9: Packaging an Installer
1. Packaging Your Application
   - Understand how to package your project for distribution

Stage 10: Selecting Static or Shared Libraries
1. Choosing Between Static and Shared Libraries
   - Learn the differences and how to configure them

Stage 11: Adding Export Configuration
1. Exporting CMake Configuration
   - Understand how to create export files for libraries

Stage 12: Packaging Debug and Release
1. Managing Debug and Release Configurations
   - Learn how to configure different build types
*/

#include <iostream>
#include "Library.h"
#include "User.h"
#include "Book.h"

int main() {
    // Check if the Library Management System is being used
#ifdef USE_LIBRARY
    Library library;

    // Add books to the library
    library.addBook(Book("B001", "1984", "George Orwell"));
    library.addBook(Book("B002", "To Kill a Mockingbird", "Harper Lee"));

    // Register users
    library.registerUser(User("U001", "Alice"));
    library.registerUser(User("U002", "Bob"));

    // List books and users
    library.listBooks();
    library.listUsers();

    // Borrow and return books
    library.borrowBook("B001", "U001");
    library.returnBook("B001", "U001");

#else
    std::cout << "Library Management System is not enabled." << std::endl;
#endif

    return 0;
}

