#pragma once
#include "Book.h"
#include <string>
#include "Authors.h"
#include "Genre.h"

Book::Book(std::string title, std::string description, Genre genre, Authors authors, std::size_t year)
    : title(std::move(title))
    , description(std::move(description))
    , genre(std::move(genre))
    , authors(std::move(authors))
    , year(year)
{}

void Book::print() const
{
    std::cout << "Title: " << title << "\n" << "Description: " << description << "\n";
    genre.printGenre();
    authors.printAuthors();
    std::cout << "Year: " << year << "\n";
    std::cout << std::endl;
}

bool Book::operator==(const Book& book) const
{
    return this->authors == book.authors &&
        this->description == book.description &&
        this->genre == book.genre &&
        this->title == book.title &&
        this->year == book.year;
}

bool Book::operator<(const Book& book) const
{
    return this->title < book.title;
}

bool Book::operator>(const Book& book) const
{
    return book < *this;
}

bool Book::operator<=(const Book& book) const
{
    return !(book < *this);
}

bool Book::operator>=(const Book& book) const
{
    return book <= *this;
}

std::string Book::getTitle()const
{
    return title;
}

std::vector<std::string> Book::getGener() const
{
    return genre.getGenre();
}

std::vector<std::string> Book::getAuthors() const
{
    return authors.getName();
}

std::size_t Book::getYear() const
{
    return year;
}

bool Book::empty() const
{
    return genre.getGenre().size() == 0;
}