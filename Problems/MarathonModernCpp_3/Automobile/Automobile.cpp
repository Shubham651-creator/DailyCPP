#include "Automobile.h"

Automobile::Automobile(std::variant<int, std::string> id, AutomobileType autoType,
                       std::string brand, pointerOfEngine engine,
                       float price, std::array<int, 4> pressure)
    : _id(id), _type(autoType), _brand(brand), _engine(engine),
      _price(price), _tyre_pressure_reading(pressure)
{
    int count = 0;
    for (int tyre : pressure)
    {
        if (tyre < 0 || tyre > 40)
        {
            tyre = count++;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Automobile &rhs)
{
    os << "_id: ";
    std::visit([&](auto &&val)
               { std::cout << val << "\n"; },
               rhs._id);
    os << " _type: " << DisplayAutomobileType(rhs._type)
       << " _brand: " << rhs._brand
       << " _engine: " << *(rhs._engine.get())
       << " _price: " << rhs._price
       << " _tyre_pressure_reading: ";

    for (auto i : rhs._tyre_pressure_reading)
    {
        os << i << '\t';
    }
    return os;
}

std::string DisplayAutomobileType(AutomobileType type)
{
    if (type == AutomobileType::SEPCIAL_PURPOSE)
        return "SEPCIAL_PURPOSE";
    if (type == AutomobileType::TRANSPORT)
        return "TRANSPORT";
    return "COMMUTE";
}
