#include <iostream>
#include "Engine.h"
#include "Car.h"

Engine engine1("Engi@1", EngineType::HYBIRD, 2000, 403);
Engine engine2("Engi@2", EngineType::HYBIRD, 4000, 603);
Engine engine3("Engi@3", EngineType::ICT, 6500, 6054);

Car car1("car@1", "awale", CarType::SPORTS, engine1, 100300000);
Car car2("car@2", "sunil", CarType::HATCHBACK, engine1, 102300000);
Car car3("car@3", "ajnya", CarType::SEDAN, engine1, 100300400);

// return engineHorsePower of car id
int horsePowerFunction(std::string car_id)
{
    if (car1.getCarId() == car_id || car2.getCarId() == car_id || car3.getCarId() == car_id)
    {
        return engine1.getEngineHorsepower();
    }
    if (car2.getCarId() == car_id)
    {
        return engine2.getEngineHorsepower();
    }
    if (car3.getCarId() == car_id)
    {
        return engine3.getEngineHorsepower();
    }
    return -1;
}

// return All instance of car
// whose torque > 80 N.m
Car EngineTorqueFunction()
{
    if (engine1.getEngineTorque() > 80)
    {
        std::cout << car1;
        return car1;
    }

    if (engine2.getEngineTorque() > 80)
    {
        std::cout << car1;
        return car2;
    }

    if (engine3.getEngineTorque() > 80)
        std::cout << car1;
    return car3;

    return car1;
}

// return Engine class instance based on cartype
Engine checkCarTypes(CarType car_type)
{
    if (car1.getCarType() == car_type)
    {
        std::cout << engine1;
        return engine1;
    }

    if (car2.getCarType() == car_type)
    {
        std::cout << engine1;
        return engine2;
    }

    if (car3.getCarType() == car_type)
    {
        std::cout << engine1;
        return engine3;
    }

    return engine1;
}

// averger of horsepower of car provide conditons
int avergeOfHorsepower()
{
    int sum = 0, count = 1;
    if (engine1.getEngineType() == EngineType::ICT && car1.getCarPrice() > 100000)
    {
        sum += engine1.getEngineHorsepower();
        ++count;
    }
    if (engine2.getEngineType() == EngineType::ICT && car2.getCarPrice() > 100000)
    {
        sum += engine2.getEngineHorsepower();
        ++count;
    }
    if (engine3.getEngineType() == EngineType::ICT && car3.getCarPrice() > 100000)
    {
        sum += engine3.getEngineHorsepower();
        ++count;
    }

    return sum / count;
}

// return car id whose has lowest car price
int lowestCarPrice()
{
    int low = car1.getCarPrice();
    if (low > car2.getCarPrice())
    {
        low = car2.getCarPrice();
    }
    if (low > car3.getCarPrice())
    {
        low = car3.getCarPrice();
    }

    return low;
}

// client code
int main()
{

    std::string car_id;
    std::cout << "enter car id for horse power = ";
    std::cin >> car_id;
    std::cout << "The horse power is " << horsePowerFunction(car_id) << "\n";

    std::cout << "EngineTorqueFunction():\n";
    Car car4;
    EngineTorqueFunction();

    std::cout << "checkCarTypes():\n";
    checkCarTypes(CarType::SEDAN);

    std::cout << "The average is " << avergeOfHorsepower() << "\n";

    std::cout << "The additon of 2 instance = " << car1 + car2 << "\n";

    return 0;
}