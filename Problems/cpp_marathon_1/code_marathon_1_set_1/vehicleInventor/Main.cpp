#include <iostream>
#include "BookVehicle.h"

int main()
{

    // we can access the Car class using BookVehicle class
    BookVehicle bookVehicle;
    std::cout << "\nDisplay the car class using bookvehicle class\n";
    bookVehicle->accept();
    bookVehicle->display();

    Car car[3];
    // Take a input
    std::cout << "\ndisplay the 3 car information\n\n";
    car[0].accept();
    car[1].accept();
    car[2].accept();
    // display the car class information
    std::cout << car[0];
    std::cout << car[1];
    std::cout << car[2];

    return 0;
}