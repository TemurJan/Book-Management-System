#pragma once
#include <set>
#include <string>
#include "Library.h"
#include "Book.h"
#include <iostream>

class Users
{
private:
    std::string name;
    std::string email;
    std::string password;
    bool isAdmin;
    std::set<Book> favorites;
public:
    Users(std::string name, std::string email, std::string password, bool isAdmin = false);

    Users() = default;

    std::string getName() const;

    std::string getEmail() const;

    bool checkPassword(const std::string& pass) const;

    bool isAdministrator() const;

    void toAddFavoritesBook(const Book& other);

    void toRemoveFavoritesBook(const Book& other);

    void print() const;

    void listOfFavoritesBook();

    std::set<Book> getFavorites() const;

};

