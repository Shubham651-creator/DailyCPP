#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <iostream>
#include "AutomobileTyep.h"
#include "Engine.h"
#include <memory>
#include <array>
#include <variant>

using pointerOfEngine = std::shared_ptr<Engine>;

class Automobile
{
private:
    std::variant<int, std::string> _id;
    AutomobileType _type;
    std::string _brand;
    pointerOfEngine _engine;
    float _price;
    std::array<int, 4> _tyre_pressure_reading;

public:
    // default constructor
    Automobile() = delete;

    // copy constructor
    Automobile(const Automobile &) = delete;

    // opertor constor
    Automobile &operator=(Automobile &) = delete;

    // move constructor
    Automobile(Automobile &&) = delete;

    // opertor constor
    Automobile &operator=(Automobile &&) = delete;

    // parameterzied constructor
    Automobile(std::variant<int, std::string> id, AutomobileType autoType, std::string brand,
               pointerOfEngine engine, float price, std::array<int, 4> pressure);

    // destructor
    ~Automobile() = default;

    std::variant<int, std::string> id() const { return _id; }
    void setId(const std::variant<int, std::string> &id) { _id = id; }

    AutomobileType type() const { return _type; }

    std::string brand() const { return _brand; }

    pointerOfEngine engine() const { return _engine; }

    float price() const { return _price; }

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
};

std::string DisplayAutomobileType(AutomobileType type);

#endif // AUTOMOBILE_H
