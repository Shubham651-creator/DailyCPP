#include <iostream>
// #include "Batsman.h"
// #include "Bowler.h"
#include "AllRounder.h"

int main()
{
    //AllRounder all("Jadeja", 239, 56, 6, 70, 59, BowlerTypes::FASTER, 55.5, 100, 1);
    //AllRounder all("Ajinkya",71, 65.5, 6.0, 24,  40, BowlerTypes::LEFT_HANDED, 150.90, 210, 2);
    AllRounder all;
    all.accept();
    all.display();

    // Batsman b1("Dhoni",007, 78, 6.0, 100, 40.3, 300);
    // b1.display();

    // Bowler bo1("shami",239,56,6,70,59, BowlerTypes::FASTER);
    // bo1.display();

    // Cricketer cricket("Dhoni",007, 78, 6.0, 100);
    // cricket.display();

    return 0;
}