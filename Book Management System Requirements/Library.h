#pragma once
#include <vector>
#include <string>
#include "Book.h"

class Library
{
private:
    std::vector<Book> library;

    bool equal(const std::vector<std::string>& rhs, const std::vector<std::string>& lhs)
    {
        if (rhs.size() and rhs.size() != lhs.size())
            return false;

        for (int i = 0; i < rhs.size(); ++i)
            if (rhs[i] != lhs[i])
                return false;
        return true;
    }

    bool check(const Book& rhs, const Book& lhs)
    {
        if (rhs.getTitle() == lhs.getTitle() && equal(rhs.getGener(), lhs.getGener()) &&
            equal(rhs.getAuthors(), lhs.getAuthors()) && rhs.getYear() == lhs.getYear())
            return true;
    }

public:
    Library(std::vector<Book> library);

    Library() = default;

    void toAdd(const Book& book);

    void toRemove(const Book& book);

    void toShow() const;

    std::vector<Book> getBooks() const;
};

