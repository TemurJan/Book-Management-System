#pragma once
#include "Library.h"
#include <vector>
#include <string>
#include "Book.h"

Library::Library(std::vector<Book> library)
    : library(std::move(library))
{}

void Library::toAdd(const Book& book)
{
    for (const auto& elem : library)
        if (check(elem, book))
            return;

    library.push_back(book);
}

void Library::toRemove(const Book& book)
{
    std::size_t index = library.size();
    for (std::size_t i = 0; i < library.size(); ++i)
    {
        if (check(library[i], book))
        {
            index = i;
            break;
        }
    }
    if (index == library.size())
        return;
    library.erase(library.begin() + index, library.begin() + index + 1);
}

void Library::toShow() const
{
    for (const auto& elem : library)
        elem.print();
}

std::vector<Book> Library::getBooks() const
{
    return library;
}