#pragma once
#include "Genre.h"
#include <iostream>
#include <vector>
#include <string>

Genre::Genre(std::vector<std::string> genre)
    :genre(std::move(genre)) {}

bool Genre::operator==(const Genre& other) const
{
    if (other.genre.size() != genre.size())
        return false;
    for (std::size_t i = 0; i < genre.size(); ++i)
        if (other.genre[i] != genre[i])
            return false;
    return true;
}

bool Genre::operator<(const Genre& other) const
{
    return genre < other.genre;
}

bool Genre::operator>(const Genre other) const
{
    return genre > other.genre;
}

bool Genre::operator<=(const Genre& other) const
{
    return genre <= other.genre;
}

bool Genre::operator>=(const Genre& other) const
{
    return genre >= other.genre;
}

std::vector<std::string> Genre::getGenre() const
{
    return genre;
}

void Genre::printGenre() const
{
    std::cout << "Genre: ";
    for (const auto& elem : genre)
        std::cout << elem << ", ";
    std::cout << "\n";
}