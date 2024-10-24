#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
private:
    std::string userID;
    std::string userName;
    std::vector<std::string> borrowedBooks;

public:
    User(const std::string& id, const std::string& name);
    
    std::string getUserID() const;
    std::string getUserName() const;
    void borrowBook(const std::string& bookID);
    void returnBook(const std::string& bookID);
    void listBorrowedBooks() const;
};

#endif // USER_H
