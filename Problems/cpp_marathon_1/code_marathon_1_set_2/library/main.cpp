#include <iostream>
#include "Book.h"
#include "Library.h"

float categoryTotal[4] = {0, 0, 0, 0};
float countTheCategory[4] = {0, 0, 0, 0};

void calculateAvg(Book book, int Category)
{
    if (Category == 1)
    {
        categoryTotal[0] = categoryTotal[0] + book.getPrice();
        countTheCategory[0]++;
    }
    if (Category == 2)
    {
        categoryTotal[1] = categoryTotal[1] + book.getPrice();
        countTheCategory[1]++;
    }
    if (Category == 3)
    {
        categoryTotal[2] = categoryTotal[2] + book.getPrice();
        countTheCategory[2]++;
    }
    if (Category == 4)
    {
        categoryTotal[3] = categoryTotal[3] + book.getPrice();
        countTheCategory[3]++;
    }
}

void displayAverge(Book pile[], int n)
{
    int ChooseCategory;
    std::cout << "Submit new books\n";
    for (int pileCount = 0; pileCount < n; pileCount++)
    {
        std::cin >> pile[pileCount];
        std::cout << "Choose your book Category: 1.Fiction 2.Biography 3.History 4.Adventure\n";
        std::cin >> ChooseCategory;
        calculateAvg(pile[pileCount], ChooseCategory);
    }
    float fictionAvg = categoryTotal[0] / countTheCategory[0];
    float biographyAvg = categoryTotal[1] / countTheCategory[1];
    float historyAvg = categoryTotal[2] / countTheCategory[2];
    float adventureAvg = categoryTotal[3] / countTheCategory[3];

    // handle ending conditions
    if (fictionAvg >= 0)
        fictionAvg;
    else
        fictionAvg = 0;

    if (biographyAvg >= 0)
        biographyAvg;
    else
        biographyAvg = 0;

    if (historyAvg >= 0)
        historyAvg;
    else
        historyAvg = 0;

    if (adventureAvg >= 0)
        adventureAvg;
    else
        adventureAvg = 0;

    // Display the new books information

    for (int Count = 0; Count < n; Count++)
    {
        pile[Count].display();
    }

    // display averages
    std::cout << "Averge price of books fiction is " << fictionAvg << "\n"<< "Averge price of books biography is " << biographyAvg << "\n"<< "Averge price of books history is " << historyAvg << "\n"<< "Averge price of books adventure is " << adventureAvg << "\n";
}

int main()
{
    Library FirstLibrary;
    FirstLibrary->accept();
    FirstLibrary->display();
    // Three object of book class
    Book pile[3];
    int n = 3;
    // It display the averge of every category
    displayAverge(pile, n);
}
