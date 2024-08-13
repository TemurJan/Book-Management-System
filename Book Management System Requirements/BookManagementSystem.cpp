#include "BookManagementSystem.h"
#include "Library.h"
#include <map>
#include "Users.h"
#include <iostream>

BookManagementSystem::BookManagementSystem(Users* currentUser) :currentUser(currentUser) {}

void BookManagementSystem::toRegisterUser(const std::string& name, const std::string& email, const std::string& password, bool isAdmin)
{
    if (users.find(email) == users.end())
    {
        users[email] = Users(name, email, password, isAdmin);
        std::cout << "User registered successfully." << std::endl;
    }
    else {
        std::cout << "Email already registered." << std::endl;
    }
}

bool BookManagementSystem::toLoginUser(const std::string& email, const std::string& password)
{
    auto it = users.find(email);
    if (it != users.end() && it->second.checkPassword(password))
    {
        currentUser = &it->second;
        std::cout << "Logged in successfully." << std::endl;
        return true;
    }
    std::cout << "Login failed." << std::endl;
    return false;
}

void BookManagementSystem::toAddBook(const Book& book)
{
    if (currentUser && currentUser->isAdministrator())
    {
        library.toAdd(book);
        std::cout << "Book added successfully." << std::endl;
    }
    else
        std::cout << "Only administrators can add books." << std::endl;
}

void BookManagementSystem::toLogoutUser()
{
    currentUser = nullptr;
    std::cout << "Logged out successfully." << std::endl;
}

void BookManagementSystem::toRemoveBook(const Book& book)
{
    if (currentUser && currentUser->isAdministrator())
    {
        library.toRemove(book);
        std::cout << "Book removed successfully." << std::endl;
    }
    else
        std::cout << "Only administrators can remove books." << std::endl;
}

void BookManagementSystem::toViewBooks() const
{
    library.toShow();
}

void BookManagementSystem::toSearchBooks(const std::string& query) const
{
    for (const auto& book : library.getBooks())
        if (book.getTitle().find(query) != std::string::npos ||
            std::find(book.getAuthors().begin(), book.getAuthors().end(), query) != book.getAuthors().end() ||
            std::find(book.getGener().begin(), book.getGener().end(), query) != book.getGener().end())
            book.print();
}

void BookManagementSystem::toAddToFavorites(const Book& book)
{
    if (currentUser)
    {
        currentUser->toAddFavoritesBook(book);
        std::cout << "Book added to favorites." << std::endl;
    }
    else
        std::cout << "Please log in first." << std::endl;
}

void BookManagementSystem::toRemoveFromFavorites(const Book& book)
{
    if (currentUser)
    {
        currentUser->toRemoveFavoritesBook(book);
        std::cout << "Book removed from favorites." << std::endl;
    }
    else
        std::cout << "Please log in first." << std::endl;
}

void BookManagementSystem::viewFavorites() const
{
    if (currentUser)
    {
        std::cout << "Favorite books for " << currentUser->getName() << ":" << std::endl;
        for (const auto& book : currentUser->getFavorites())
            book.print();
    }
    else
        std::cout << "Please log in first." << std::endl;
}