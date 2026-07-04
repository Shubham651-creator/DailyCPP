#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"

class Car
{
private:
    std::string _id;
    std::string _model;
    CarType _type;
    float _price;
    int _fuelCapacity;

public:
    // disable default constructor
    Car() = delete;

    // enabled shollow copy construtor
    Car(const Car &) = default;

    // a function which returns a Car& called "operator=" which accepts one const
    // Car lvalue reference is disabled
    Car &operator=(const Car &) = delete;

    // move function
    Car(Car &&) = delete;

    // move operator function
    Car &operator=(Car &&) = delete;

    // enable destructor
    ~Car() = default;

    // parameterized construtor
    Car(std::string id, std::string model, CarType type, float price, int fuelCap);

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    int fuelCapacity() const { return _fuelCapacity; }
    void setFuelCapacity(int fuelCapacity) { _fuelCapacity = fuelCapacity; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

std::string displayCarType(CarType type);

#endif // CAR_H
