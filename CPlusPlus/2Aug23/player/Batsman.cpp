#include <iostream>
#include "Batsman.h"

Batsman::Batsman()
{
    strikeRate = 50.2;
    batsmanRuns = 210;
}
Batsman::Batsman(std::string name, int number, double weight, double height, int catches, double sRate, int runs)
    : Cricketer(name, number, weight, height, catches), strikeRate(sRate), batsmanRuns(runs)
{
}

Batsman::~Batsman()
{
}

void Batsman::accept()
{
    Cricketer::accept();
    std::cout << "\nEnter Strike rate = ";
    std::cin >> strikeRate;
    std::cout << "\nEnter runs = ";
    std::cin >> strikeRate;
    std::cout << "\n";
}

void Batsman::display()
{
    Cricketer::display();
    std::cout << "\nYour are batsman : \nStrike rate = " << strikeRate
              << "\nruns = " << batsmanRuns
              << "\n";
}
