#include <iostream>
#include "AllRounder.h"

AllRounder::AllRounder()
{
    allRounderRank = 17965;
}

AllRounder::AllRounder(std::string name, int number,
                       double weight, double height, int catches, int wickets,
                       BowlerTypes Type, double sRate, int runs, int rank)
    : Cricketer(name, number, weight, height, catches),
      Bowler(name, number, weight, height, catches, wickets, Type),
      Batsman(name, number, weight, height, catches, sRate, runs),
      allRounderRank(rank)
{
}

AllRounder::~AllRounder()
{
}

void AllRounder::accept()
{
    // Batsman::accept();
    Bowler::accept();

    std::cout << "\nEnter Strike rate = ";
    std::cin >> strikeRate;
    std::cout << "\nEnter runs = ";
    std::cin >> strikeRate;
    std::cout << "\n";

    std::cout << "\nEnter all rounder rank = ";
    std::cin >> allRounderRank;
    std::cout << "\n";
}

void AllRounder::display()
{
    Bowler::display();
    // Batsman::display();
    std::cout << "\nStrike rate = " << strikeRate
              << "\nruns = " << batsmanRuns << "\n";

    std::cout << "\n all rounder rank = " << allRounderRank
              << "\n";
}
