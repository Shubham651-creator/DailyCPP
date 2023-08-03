#include <iostream>
#include "Bowler.h"

Bowler::Bowler()
{
    NumberOfWickets = 10;
    bowlerTypes = BowlerTypes::FASTER;
}
Bowler::Bowler(std::string name, int number,
               double weight, double height, int catches, int wickets, BowlerTypes types)
    : Cricketer(name, number, weight, height, catches), NumberOfWickets(wickets), bowlerTypes(types)
{
}

Bowler::~Bowler()
{
}

void Bowler::accept()
{
    Cricketer::accept();
    std::cout << "\nEnter number of wickets = ";
    std::cin >> NumberOfWickets;
    std::cout << "\nEnter bowler type = 1.spinner 2.RIGHT_HANDED 3.LEFT_HANDED 4.FASTER\n";
    int bowler_type;
    std::cin >> bowler_type;
    switch (bowler_type)
    {
    case 1:
        bowlerTypes = BowlerTypes::SPINNER;
        break;
    case 2:
        bowlerTypes = BowlerTypes::RIGHT_HANDED;
        break;
    case 3:
        bowlerTypes = BowlerTypes::LEFT_HANDED;
        break;
    case 4:
        bowlerTypes = BowlerTypes::FASTER;
        break;
    }
}

std::string displayBowlerType(BowlerTypes bt)
{
    if (bt == BowlerTypes::FASTER)
        return "FASTER";
    if (bt == BowlerTypes::LEFT_HANDED)
        return "LEFT_HANDED";
    if (bt == BowlerTypes::RIGHT_HANDED)
        return "RIGHT_HANDED";
    else
        return "SPINNER";
}

void Bowler::display()
{
    Cricketer::display();
    std::cout << "\nnumber of wickets = " << NumberOfWickets
              << "\nbowler type = " << displayBowlerType(bowlerTypes)
              << "\n";
}
