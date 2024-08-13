#pragma once
#include <iostream>
#include <vector>
#include <string>

class Genre
{
private:
    std::vector<std::string> genre;
public:
    Genre() = default;

    Genre(std::vector<std::string> genre);

    bool operator==(const Genre& other) const;

    bool operator<(const Genre& other) const;

    bool operator>(const Genre other) const;

    bool operator<=(const Genre& other) const;

    bool operator>=(const Genre& other) const;

    std::vector<std::string> getGenre() const;

    void printGenre() const;
};

