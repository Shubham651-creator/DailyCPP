#include <iostream>
#include "Electricity.h"

Electricity::Electricity()
{
    sanctionLoad = 1;
    presentReading = 20;
    previousReading = 10;
}

int Electricity::calculateElectricityBill()
{
    if (presentReading < previousReading)
        return 0;

    int consumption = presentReading - previousReading;

    if (sanctionLoad == 1)
        return (sanctionLoad * (int)ElectricitySlabs::E1) + (consumption * (int)ElectricitySlabs::E1 / 100);
    if (sanctionLoad == 3)
        return (sanctionLoad * (int)ElectricitySlabs::E2) + (consumption * (int)ElectricitySlabs::E2 / 100);
    else
        return (sanctionLoad * (int)ElectricitySlabs::E3) + (consumption * (int)ElectricitySlabs::E3 / 100);
}

void Electricity::accept()
{
    std::cout << "\nEnter Sanction load, present and previous load respectively\n";
    std::cin >> sanctionLoad >> presentReading >> previousReading;
    std::cout << "\n";
}

void Electricity::display()
{
    std::cout << "\nSanction load = " << sanctionLoad
              << "\npresent reading = " << presentReading
              << "\nprevious reading = " << previousReading
              << "\nfinal bill = " << calculateElectricityBill()
              << "\n\n";
}

Electricity::Electricity(int load, long presentR, long previousR)
    : sanctionLoad(load), presentReading(presentR), previousReading(previousR)
{
}

Electricity::~Electricity()
{
}
