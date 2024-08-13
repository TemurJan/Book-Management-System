#pragma once
#include "Authors.h"
#include <iostream>
#include <string>
#include <vector>

Authors::Authors(std::vector<std::string> name) :name(std::move(name)) {}

bool Authors::operator==(const Authors& other) const
{
    if (other.name.size() != name.size())
        return false;
    for (std::size_t i = 0; i < name.size(); ++i)
        if (name[i] != other.name[i])
            return false;
    return true;
}

bool Authors::operator<(const Authors& other) const
{
    return name < other.name;
}

bool Authors::operator>(const Authors& other) const
{
    return name > other.name;

}

bool Authors::operator<=(const Authors& other) const
{
    return !(name > other.name);
}

bool Authors::operator>=(const Authors& other) const
{
    return !(name < other.name);
}

void Authors::printAuthors() const
{
    std::cout << "Authors: ";
    for (const auto& elem : name)
        std::cout << elem << ", ";
    std::cout << "\n";
}

std::vector<std::string> Authors::getName() const
{
    return name;
}