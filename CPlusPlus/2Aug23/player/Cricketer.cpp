#include <iostream>
#include "Cricketer.h"

Cricketer::Cricketer()
{
    numberOfCatches = 10;
}
Cricketer::Cricketer(std::string name, int number, double weight, double height, int catches)
    : Player(name, number, weight, height), numberOfCatches(catches)
{
}

Cricketer::~Cricketer()
{
}

void Cricketer::accept()
{
    Player::accept(); // to accept from player class
    std::cout << "\nEnter number of catches = ";
    std::cin >> numberOfCatches;
    std::cout << "\n";
}

void Cricketer::display()
{
    Player::display(); // to display from player class
    std::cout << "\nNumbe of catches = " << numberOfCatches
              << "\n";
}
