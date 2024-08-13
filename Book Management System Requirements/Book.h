#pragma once
#include <string>
#include "Authors.h"
#include "Genre.h"

class Book
{
private:
    std::string title;
    std::string description;
    Genre genre;
    Authors authors;
    std::size_t year;
public:
    Book(std::string title, std::string description, Genre genre, Authors authors, std::size_t year);

    Book() = default;
     
    void print() const;

    bool operator==(const Book& book) const;

    bool operator<(const Book& book) const;

    bool operator>(const Book& book) const;

    bool operator<=(const Book& book) const;

    bool operator>=(const Book& book) const;

    std::string getTitle()const;

    std::vector<std::string> getGener() const;

    std::vector<std::string> getAuthors() const;

    std::size_t getYear() const;

    bool empty() const;
};

