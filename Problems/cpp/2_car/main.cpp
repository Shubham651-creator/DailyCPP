//mini code-marathon: question 2
#include <iostream>

#include "Car.h"

int main()
{
    BookVehicle b1;
    b1->accept();
    b1->display();

    Car c1;
    std::cout << c1;
    Car Inventory[3];
    carCategory cat1;
    for (int i = 0; i < 3; i++)
    {
        Inventory[i].accept();
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << Inventory[i];
    }
    calculateAvg(Inventory, cat1);
}