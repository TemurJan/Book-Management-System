#pragma once
#include <string>
#include <vector>

class User
{
private:
    std::string name;
    std::string email;
    std::string password;
    bool isAdmin;
    std::vector<Book> favorites;
public:
    User(std::string name, std::string email, std::string password, bool isAdmin = false)
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
    User() {}
    std::string getName() const
    {
        return name;
    }
    std::string getEmail() const
    {
        return email;
    }

    bool checkPassword(const std::string& pass) const
    {
        return pass == password;
    }

    bool isAdministrator() const
    {
        return isAdmin;
    }

    void toAddFavoritesBook(const Book& other)
    {
        if (std::find(favorites.begin(), favorites.end(), other) == favorites.end())
            favorites.push_back(other);
    }

    void toRemoveFavoritesBook(const Book& other)
    {
        std::size_t index = favorites.size();
        for (std::size_t i = 0; i < favorites.size(); ++i)
        {
            if (favorites[i] == other)
            {
                index = i;
                break;
            }
        }
        favorites.erase(favorites.begin() + index, favorites.begin() + index + 1);
    }

    void print()const
    {
        std::cout << "Name: " << name << "\n" << "Email: " << email << "\n";
    }

    void listOfFavoritesBook()
    {
        for (const auto& elem : favorites)
            elem.print();
        std::cout << "\n";
    }

    std::vector<Book> getFavorites() const
    {
        return favorites;
    }

};

