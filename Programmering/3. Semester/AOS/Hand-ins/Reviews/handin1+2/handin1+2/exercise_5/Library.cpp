#include "Library.h"
#include <iostream>
#include <algorithm>

void Library::addBook(int id, int category)
{
    books.push_back(Book(id, category));
    checkBalance();
}

bool Library::borrowBook(int id)
{
    for (auto &b : books)
    {
        if (b.id == id && !b.borrowed)
        {
            b.borrowed = true;
            return true;
        }
    }
    return false;
}

bool Library::returnBook(int id)
{
    for (auto &b : books)
    {
        if (b.id == id && b.borrowed)
        {
            b.borrowed = false;
            return true;
        }
    }
    return false;
}

void Library::displayAvailableBooks() const
{
    for (const auto &b : books)
    {
        if (!b.borrowed)
            std::cout << "Book ID: " << b.id << ", Category: " << b.category << "\n";
    }
}

void Library::displayBorrowedBooks() const
{
    for (const auto &b : books)
    {
        if (b.borrowed)
            std::cout << "Book ID: " << b.id << ", Category: " << b.category << "\n";
    }
}

int Library::countBooksInCategory(int category) const
{
    int count = 0;
    for (const auto &b : books)
    {
        if (b.category == category)
            count++;
    }
    return count;
}

//Der er tilføjet noter til nedenstående funktion som sørger for Warning hvis en kategori overstiger gennemsnittet med mere end 2 gange, da det kan fremstå lidt forvirrende.
void Library::checkBalance()
{
    std::vector<int> categoriesBefore; //Indeholde alle de unikke kategorier, der fandtes, før den nye bog blev tilføjet.
    int totalBefore = 0; //Tæller, hvor mange bøger der var i alt før tilføjelsen.

    for (size_t i = 0; i + 1 < books.size(); i++) //Loop som stopper 1 bog før den seneste.
    {
        totalBefore++; //Tæller mængden af categorier
        if (std::find(categoriesBefore.begin(), categoriesBefore.end(), books[i].category) == categoriesBefore.end())
            categoriesBefore.push_back(books[i].category);
    }

    if (categoriesBefore.empty()) //Hvis der ikke var nogen bøger før, giver det ingen mening at beregne et gennemsnit
        return;

    double average = static_cast<double>(totalBefore) / categoriesBefore.size();
    double threshold = 2 * average; //Grænsen vi sammenligner op imod.

    std::vector<int> checkedCategories; //Liste til at holde styr på, hvilke kategorier vi allerede har tjekket inklusiv nyeste tilføjet bog.
    for (const auto &b : books)
    {
        if (std::find(checkedCategories.begin(), checkedCategories.end(), b.category) != checkedCategories.end()) //Tjekker om categorien allerede findes og går videre hvis den findes.
            continue;

        checkedCategories.push_back(b.category); //Slå op hvor mange bøger den nu (efter tilføjelsen) indeholder i alt.
        int count = countBooksInCategory(b.category);

        if (count > threshold) //Hvis denne kategoris nuværende antal overstiger grænsen udskrives en advarsel.
        {
            std::cout << "Warning: Category " << b.category << " has " << count
                      << " books, more than twice the average of " << average << ".\n";
        }
    }
}