#pragma once
#include <vector>
#include <string>

class Authors
{
private:
    std::vector<std::string> name;
public:
    Authors(std::vector<std::string> name);

    Authors() = default;

    bool operator==(const Authors& other) const;

    bool operator<(const Authors& other) const;

    bool operator>(const Authors& other) const;

    bool operator<=(const Authors& other) const;

    bool operator>=(const Authors& other) const;

    void printAuthors() const;

    std::vector<std::string> getName() const;
};

