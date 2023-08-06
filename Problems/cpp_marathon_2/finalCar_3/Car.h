#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarType.h"
#include "Engine.h"

class Car
{
private:
    std::string carId;
    std::string carBrand;
    enum CarType carType;

    // it's pointer to an Engine type instance
    Engine carEngine;
    float carPrice;

public:
    // default constructor
    Car();

    // parameterized constrctor
    Car(std::string id, std::string brand, enum CarType type, Engine etype , float price);

    // copy construtor
    Car(Car &car);

    // car destructor
    ~Car();

    // operator= overloading
    void operator=(Car &car);

    // operator+ overloading
    int operator+(Car &car);

    //accpt function
    void accept();

    CarType acceptCarType(int check);

    //display the car type enum
    std::string displayCarType(CarType type);

    std::string getCarId() const { return carId; }
    void setCarId(const std::string &carId_) { carId = carId_; }

    std::string getCarBrand() const { return carBrand; }
    void setCarBrand(const std::string &carBrand_) { carBrand = carBrand_; }

    enum CarType getCarType() const { return carType; }
    void setCarType(const enum CarType &carType_) { carType = carType_; }

    float getCarPrice() const { return carPrice; }
    void setCarPrice(float carPrice_) { carPrice = carPrice_; }

    // operator<< overloading
    friend void operator<<(std::ostream &out, Car &car);
};

#endif // CAR_H
