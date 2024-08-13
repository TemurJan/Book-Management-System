//#include "Book.h"
//#include "Users.h"
#include <iostream>
#include "BookManagementSystem.h"

int main()
{
    BookManagementSystem system;

    system.toRegisterUser("Mika", "mikajan@gmail.com", "mika789");
    system.toRegisterUser("Admin", "admin@example.com", "admin123", true);

    if (system.toLoginUser("admin@example.com", "admin123")) {
        Book obj1("To Kill a Mockingbird", "This novel is set in the Depression-era South and follows young Scout Finch and her brother, Jem, as their father, lawyer Atticus Finch, defends a black man accused of raping a white woman. It addresses themes of racial injustice, moral growth, and compassion.", Genre({ "Fiction", "Classic", "Historical" }), Authors({ "Harper Lee" }), 1960);
        Book obj2("1984", "A dystopian novel that explores the dangers of totalitarianism. It is set in a world of perpetual war, pervasive government surveillance, and incessant public mind control, dictated by a political regime under the control of the Party and its emblem, Big Brother.", Genre({ "Fiction", "Dystopian", "Science Fiction" }), Authors({ "George Orwell" }), 1949);
        Book obj3("Pride and Prejudice", "This classic novel of manners explores the issues of marriage, money, and love among the British gentry of the early 19th century. It focuses on the relationship between Elizabeth Bennet and Mr. Darcy.", Genre({ "Fiction", "Romance", "Classic" }), Authors({ "Jane Austen" }), 1813);

        system.toAddBook(obj1);
        system.toAddBook(obj2);
        system.toAddBook(obj3);

        system.toLogoutUser();
    }

    if (system.toLoginUser("mikajan@gmail.com", "mika789")) {
        Book obj1("To Kill a Mockingbird", "This novel is set in the Depression-era South and follows young Scout Finch and her brother, Jem, as their father, lawyer Atticus Finch, defends a black man accused of raping a white woman. It addresses themes of racial injustice, moral growth, and compassion.", Genre({ "Fiction", "Classic", "Historical" }), Authors({ "Harper Lee" }), 1960);
        Book obj2("1984", "A dystopian novel that explores the dangers of totalitarianism. It is set in a world of perpetual war, pervasive government surveillance, and incessant public mind control, dictated by a political regime under the control of the Party and its emblem, Big Brother.", Genre({ "Fiction", "Dystopian", "Science Fiction" }), Authors({ "George Orwell" }), 1949);

        system.toAddToFavorites(obj1);
        system.toAddToFavorites(obj2);

        system.viewFavorites();

        system.toRemoveFromFavorites(obj1);
        system.viewFavorites();
    }

    return 0;

    /*
    Book obj1("To Kill a Mockingbird", "This novel is set in the Depression-era South and follows young Scout Finch and her brother, Jem, as their father, lawyer Atticus Finch, defends a black man accused of raping a white woman. It addresses themes of racial injustice, moral growth, and compassion.", Genre({ "Fiction", "Classic", "Historical" }), Authors({ "Harper Lee" }), 1960);
    Book obj2("To Kill a Mockingbird", "This novel is set in the Depression-era South and follows young Scout Finch and her brother, Jem, as their father, lawyer Atticus Finch, defends a black man accused of raping a white woman. It addresses themes of racial injustice, moral growth, and compassion.", Genre({ "Fiction", "Classic", "Historical" }), Authors({ "Harper Lee" }), 1968);
    Book obj3("1984", "A dystopian novel that explores the dangers of totalitarianism. It is set in a world of perpetual war, pervasive government surveillance, and incessant public mind control, dictated by a political regime under the control of the Party and its emblem, Big Brother.", Genre({ " Fiction", "Dystopian", "Science Fiction" }), Authors({ " George Orwell" }), 1949);
    Book obj4(" Pride and Prejudice", "This classic novel of manners explores the issues of marriage, money, and love among the British gentry of the early 19th century. It focuses on the relationship between Elizabeth Bennet and Mr. Darcy.", Genre({ "Fiction", "Romance", "Classic" }), Authors({ "Jane Austen" }), 1813);
    Book obj5("Moby - Dick", "The novel follows the adventures of the wandering sailor Ishmael and his voyage on the whaling ship Pequod, commanded by Captain Ahab.Ahab is obsessed with revenge against Moby Dick, the giant white sperm whale that on the ship's previous voyage destroyed Ahab's ship and severed his leg at the knee.", Genre({ "Fiction", "Adventure", "Classic" }), Authors({ "Herman Melville" }), 1234);

    Users user("Mika", "mikajan@gmail.com", "mika789");
    user.toAddFavoritesBook(obj1);
    user.toAddFavoritesBook(obj2);
    user.toAddFavoritesBook(obj3);
    user.toAddFavoritesBook(obj4);
    user.listOfFavoritesBook();
    user.toRemoveFavoritesBook(obj2);
    user.listOfFavoritesBook();
    /*
    Book obj1("To Kill a Mockingbird" , "This novel is set in the Depression-era South and follows young Scout Finch and her brother, Jem, as their father, lawyer Atticus Finch, defends a black man accused of raping a white woman. It addresses themes of racial injustice, moral growth, and compassion.",Genre( { "Fiction", "Classic", "Historical" }), Authors({ "Harper Lee" }), 1960);
    Book obj2("To Kill a Mockingbird" , "This novel is set in the Depression-era South and follows young Scout Finch and her brother, Jem, as their father, lawyer Atticus Finch, defends a black man accused of raping a white woman. It addresses themes of racial injustice, moral growth, and compassion.",Genre( { "Fiction", "Classic", "Historical" }), Authors({ "Harper Lee" }), 1968);
    Book obj3("1984" , "A dystopian novel that explores the dangers of totalitarianism. It is set in a world of perpetual war, pervasive government surveillance, and incessant public mind control, dictated by a political regime under the control of the Party and its emblem, Big Brother.",Genre( { " Fiction", "Dystopian", "Science Fiction" }),Authors( { " George Orwell" }), 1949);
    Book obj4(" Pride and Prejudice" , "This classic novel of manners explores the issues of marriage, money, and love among the British gentry of the early 19th century. It focuses on the relationship between Elizabeth Bennet and Mr. Darcy.",Genre( { "Fiction", "Romance", "Classic" }), Authors({ "Jane Austen" }), 1813);
    Book obj5("Moby - Dick" , "The novel follows the adventures of the wandering sailor Ishmael and his voyage on the whaling ship Pequod, commanded by Captain Ahab.Ahab is obsessed with revenge against Moby Dick, the giant white sperm whale that on the ship's previous voyage destroyed Ahab's ship and severed his leg at the knee.", Genre({ "Fiction", "Adventure", "Classic" }),Authors( { "Herman Melville" }), 1234);


    Library lib;
    lib.toAdd(obj1);
    lib.toAdd(obj2);
    lib.toAdd(obj3);
    lib.toAdd(obj4);
    lib.toRemove(obj2);
    lib.toShow();*/
}