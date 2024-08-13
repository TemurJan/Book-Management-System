#pragma once
#include "Users.h"
#include <set>
#include <string>
#include "Library.h"
#include "Book.h"
#include <iostream>

Users::Users(std::string name, std::string email, std::string password, bool isAdmin)
{
    this->name = name;
    while (password.size() < 6)
    {
        std::cout << "Dear " + name + " your password is unvalide... Try again\n";
        std::cin >> password;
    }
    this->password = password;
    this->isAdmin = isAdmin;
    std::string temp = email;
    std::reverse(temp.begin(), temp.end());

    while (std::string(temp.begin(), temp.begin() + 10) != "moc.liamg@" &&
        std::string(temp.begin(), temp.begin() + 9) != "ma.liamg@" &&
        std::string(temp.begin(), temp.begin() + 9) != "ur.liamg@")
    {
        std::cout << "Dear " + name + " your email is wronge... Try again\n";
        std::string new_email;
        std::cin >> new_email;
        temp = new_email;
        std::reverse(temp.begin(), temp.end());
    }
    std::reverse(temp.begin(), temp.end());
    this->email = temp;
}

std::string Users::getName() const
{
    return name;
}

std::string Users::getEmail() const
{
    return email;
}

bool Users::checkPassword(const std::string& pass) const
{
    return pass == password;
}

bool Users::isAdministrator() const
{
    return isAdmin;
}

void Users::toAddFavoritesBook(const Book& other)
{
    favorites.insert(other);
}

void Users::toRemoveFavoritesBook(const Book& other)
{
    favorites.erase(other);
}

void Users::print()const
{
    std::cout << "Name: " << name << "\n" << "Email: " << email << "\n";
}

void Users::listOfFavoritesBook()
{
    for (const auto& elem : favorites)
        elem.print();
    std::cout << "\n";
}

std::set<Book> Users::getFavorites() const
{
    return favorites;
}
