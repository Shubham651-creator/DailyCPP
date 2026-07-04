#include <iostream>
#include "Car.h"

Car::Car()
{
    carId = "H@123";
    carBrand = "Honda";
    carType = CarType::SEDAN;
    carEngine = new Engine("egine123", EngineType::ICT, 200, 43);
    carPrice = 50000;
}

Car::Car(std::string id, std::string brand, enum CarType type, Engine *engine, float price)
    : carId(id), carBrand(brand), carType(type), carEngine(engine), carPrice(price)
{
}

Car::Car(Car &car)
{
    carId = car.carId;
    carBrand = car.carBrand;
    carType = car.carType;
    carEngine = car.carEngine;
    carPrice = car.carPrice;
}

Car::~Car()
{
    // delete carEngine;
}

// car1.operator=(car2)
// car1= car2
void Car::operator=(Car &car)
{
    carId = car.carId;
    carBrand = car.carBrand;
    carType = car.carType;
    carEngine = car.carEngine;
    carPrice = car.carPrice;
}

// car3 = car1.operator+(car2)
// car3 = car1 + car2
int Car::operator+(Car &car)
{
    int carTemp;
    // add price to 2 car instance
    carTemp = carPrice + car.carPrice;

    return carTemp;
}

std::string Car::displayCarType(CarType type)
{
    if (type == CarType::SEDAN)
        return "SEDAN";
    if (type == CarType::SUV)
        return "SUV";
    if (type == CarType::SPORTS)
        return "SPORTS";
    else
        return "HATCHBACK";
}

void Car::accept()
{
    std::cout << "Enter the Car info : \n"
              << "Enter car id = ";
    std::cin >> carId;
    std::cout << "\nEnter car brand = ";
    std::cin >> carBrand;
    std::cout << "\nEnter car type : 1.sedan; 2.suv; 3.sports; 4.hatchbatck\n";

    int check;
    carType = acceptCarType(check);

    std::cout << "\nEnter Engine details :";

    std::cout << "\nEnter car price = ";
    std::cin >> carPrice;

    std::cout << "\n\n";
}

CarType Car::acceptCarType(int check)
{
    if (check == 0)
        return CarType::SEDAN;
    if (check == 1)
        return CarType::SUV;
    if (check == 2)
        return CarType::SPORTS;
    if (check == 3)
        return CarType::HATCHBACK;

    return CarType::HATCHBACK;
}

// display the car information
void operator<<(std::ostream &out, Car &car)
{
    out << "The car information is below :\n";
    out << "Car id = " << car.carId
        << "\nCar Brand = " << car.carBrand
        << "\nCar type =" << car.displayCarType(car.carType)
        << "\ncar Price = " << car.carPrice
        << "\nCar Engine = \n";

    std::cout<<car.carEngine;

    out << "\n\n";
}
