#include "Engine.h"

Engine::Engine(float size, int hPower, EngineType etype)
    : _engine_size(size), _horsepower(hPower), _type(etype)
{
    if (size < 1.0f && size > 6.0f)
    {
        throw std::runtime_error("Value must be in 1 to 6\n");
    }
    if (_horsepower < 300 && _horsepower > 800)
    {
        throw std::runtime_error("Value must be in 300 to 800\n");
    }
}

std::string DisplayEngineType(EngineType type)
{
    if (type == EngineType::DIESEL)
        return "DIESEL";
    else
        return "PETROL";
}

std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    os << "_engine_size: " << rhs._engine_size
       << " _horsepower: " << rhs._horsepower
       << " _type: " << DisplayEngineType(rhs._type);
    return os;
}
