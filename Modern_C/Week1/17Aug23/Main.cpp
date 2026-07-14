#include <iostream>
#include "Car.h"
#include "Functionalities.h"
#include <list>

// using Container = std::list<Car*>; //raw pointer
using Container = std::list<Car>;

// client code
// think like user first
int main()
{
    Container data;
    CreateObjects(data);

    // a function to find average price
    float price = AveragePrice(data);
    std::cout << "The average price is " << price << "\n";

    // a function to find car with highes price and print its _model
    ModelNameHightestPrice(data);

    // a function to find and print the returned list of all cars which are above a threshold
    Container thresholdResult = CarsAboveThreshold(data, 10000);

    std::cout << "Printing the result of above  threshold function:\n";
    for (Car value : thresholdResult)
    {
        std::cout << value << "\n";
    }

    return 0;
}