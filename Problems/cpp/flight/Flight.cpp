#include <iostream>
#include "Flight.h"

Flight::Flight()
{
    flightNumber = 916;
    flightDestination = "Pune --> kolhpur";
    flightDistance = 300.0f;
    flightFuel = calculateFuelQuantity(flightDistance);
}

Flight::~Flight()
{
}

Flight::Flight(int fNumber, std::string fDestination, float fDistance)
{
    flightNumber = fNumber;
    flightDestination = fDestination;
    flightDistance = fDistance;
    flightFuel = calculateFuelQuantity(flightDistance);
}

float Flight::calculateFuelQuantity(float fDistance)
{ 
    if (fDistance <= 1000.0f)
    {
        return 500.0f;
    }
    if (fDistance > 1000.0f && fDistance <= 2000.0f)
    {
        return 1100.0f;
    }
    else
    {
        return 2200.0f;
    }
}

void Flight::feedInfo()
{
    std::cout << "Enter Flight number:";
    std::cin >> flightNumber;

    std::cout << "Enter flight Destination :";
    std::cin >> flightDestination;

    std::cout << "Enter flight Distance: ";
    std::cin >> flightDistance;

    flightFuel = calculateFuelQuantity(flightDistance);

    std::cout<<"\n";
}

void Flight::showInfo()
{
    std::cout << "Flight number:" << flightNumber << "\n";
    std::cout << "Flight Destination :" << flightDestination << "\n";
    std::cout << "Flight Distance :" << flightDistance << "\n";
    std::cout << "Flight Fuel :" << flightFuel << "\n\n";
}
