#pragma once
#include "Library.h"
#include <map>
#include "Users.h"
#include <iostream>

class BookManagementSystem
{
private:
    Library library;
    std::map<std::string, Users> users;
    Users* currentUser;
public:
    BookManagementSystem(Users* currentUser = (Users*)nullptr); 

    void toRegisterUser(const std::string& name, const std::string& email, const std::string& password, bool isAdmin = false);

    bool toLoginUser(const std::string& email, const std::string& password);

    void toAddBook(const Book& book);

    void toLogoutUser();

    void toRemoveBook(const Book& book);

    void toViewBooks() const;

    void toSearchBooks(const std::string& query) const;

    void toAddToFavorites(const Book& book);

    void toRemoveFromFavorites(const Book& book);

    void viewFavorites() const;
};

