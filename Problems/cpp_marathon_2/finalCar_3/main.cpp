#include <iostream>
#include "Engine.h"
#include "Car.h"

// Engine engine1("Engi@1", EngineType::HYBIRD, 2000, 403);
// Engine engine2("Engi@2", EngineType::HYBIRD, 4000, 603);
// Engine engine3("Engi@3", EngineType::ICT, 6500, 6054);

// Car car1("car@1", "awale", CarType::SPORTS, engine1, 100300000);
// Car car2("car@2", "sunil", CarType::HATCHBACK, engine2, 102300000);
// Car car3("car@3", "ajinkya", CarType::SEDAN, engine3, 100300400);

// return engineHorsePower of car id
int horsePowerFunction(std::string car_id, Car **arr)
{
    for (int itr = 0; itr < 3; itr++)
    {
        if (arr[itr]->getCarId() == car_id)
        {
            return arr[itr]->getCarEngine()->getEngineHorsepower();
        }
    }
    return -1;
}

// return All instance of car
// whose torque > 80 N.m
Car *EngineTorqueFunction(Car **arr)
{
    for (int itr = 0; itr < 3; itr++)
    {
        if (arr[itr]->getCarEngine()->getEngineTorque() > 80)
        {
            return arr[itr];
        }
    }

    return arr[1];
}

// return Engine class instance based on cartype
Engine *checkCarTypes(CarType car_type, Car **arr)
{
    for (int itr = 0; itr < 3; itr++)
    {
        if (arr[itr]->getCarType() == car_type)
        {
            return arr[itr]->getCarEngine();
        }
    }

    return arr[1]->getCarEngine();
}

// averger of horsepower of car provide conditons
int avergeOfHorsepower(Car **arr)
{
    int sum = 0, count = 1;

    for (int itr = 0; itr < 3; itr++)
    {
        if (arr[itr]->getCarEngine()->getEngineType() == EngineType::ICT && arr[itr]->getCarPrice() > 100000)
        {
            sum += arr[itr]->getCarEngine()->getEngineHorsepower();
            ++count;
        }
    }

    return sum / count;
}

// return car id whose has lowest car price
int lowestCarPrice(Car **arr)
{
    int low = arr[0]->getCarPrice();

    for (int itr = 0; itr < 3; itr++)
    {
        if (low > arr[itr]->getCarPrice())
        {
            low = arr[itr]->getCarPrice();
        }
    }

    return low;
}

// client code
int main()
{
    // array of car pointer
    Car *car[3];
    car[0] = new Car("car@1", "awale", CarType::SPORTS, new Engine("Engine@1", EngineType::HYBIRD, 2000, 403), 200300000);
    car[1] = new Car("car@2", "sunil", CarType::HATCHBACK, new Engine("Engine@2", EngineType::HYBIRD, 4000, 603), 102300000);
    car[2] = new Car("car@3", "ajinkya", CarType::SEDAN, new Engine("Engi@3", EngineType::ICT, 6500, 6054), 100300400);

    std::string car_id;
    std::cout << "enter car id for horse power = ";
    std::cin >> car_id;
    std::cout << "The horse power is " << horsePowerFunction(car_id, car) << "\n";

    std::cout << "\n\nEngineTorqueFunction():\n";
    Car *car4;
    car4 = EngineTorqueFunction(car);
    std::cout << *car4;

    Engine *engine;
    std::cout << "\n\ncheckCarTypes():\n";
    engine = checkCarTypes(CarType::SEDAN, car);
    std::cout << *engine;

    std::cout << "\n\nThe average of horsepower is " << avergeOfHorsepower(car) << "\n";

    std::cout << "\n\nThe additon of 2 instance = " << *car[0] + *car[1] << "\n\n";

    return 0;
}