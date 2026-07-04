// #include <iostream>
#include <iostream>

#include "Car.h"

int Car::no = 2001;
BookVehicle::BookVehicle()
{
    cptr = new Car;
}

BookVehicle::~BookVehicle()
{
    delete cptr;
}

Car::Car()
{
    carNo = no;
    no++;
    vehicleBrand = "Toyota";
    cCategory = carCategory::SUV;
    insuaranceAmount = 200000.0f;
    carPrice = 700000.0f;
    numberOfSeats = 6;
}

void Car::accept()
{
    std::cout << "\nEnter vehicle Brand:";
    std::cin >> vehicleBrand;
    std::cout << "Enter car Price:";
    std::cin >> carPrice;
    std::cout << "Enter number of Seats: ";
    std::cin >> numberOfSeats;
    std::cout << "Enter Insuarance Amount:";
    std::cin >> insuaranceAmount;
    // std::cout<<"\nEnter Car Category:";
    // std::cin>>cCategory;
}

char Car::display()
{
    std::cout << "\n\nvehicle Brand:" << vehicleBrand;
    std::cout << "\nCar Price:" << carPrice;
    std::cout << "\nNumber of Seats: " << numberOfSeats;
    std::cout << "\nInsuarance Amount" << insuaranceAmount;
    // std::cout<<"\nEnter Car Category:";
    // std::cin>>cCategory;
    return '\n';
}

void operator<<(std::ostream &os, Car &c)
{
    os << c.display();
}

float calculateAvg(Car inventory[], carCategory cCat)
{
    float sum = 0.0f, avg;
    for (int i = 0; i < 3; i++)
    {
        sum += inventory[i].getCarPrice();
    }
    avg = sum / 3;
    std::cout << "\nAverage: " << avg;
    return avg;
}