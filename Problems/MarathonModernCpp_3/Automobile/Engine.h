#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    float _engine_size;
    int _horsepower;
    EngineType _type;

public:
    // disable construtor
    Engine() = delete;

    // disable copy constructor
    Engine(const Engine &) = delete;

    // disable opertpr
    Engine &operator=(Engine &) = delete;

    // disable move constructor
    Engine(Engine &&) = delete;

    // disable opertpr
    Engine &operator=(Engine &&) = delete;

    // paratermized constructor
    Engine(float size, int hPower, EngineType etype);

    // destructor
    ~Engine() = default;

    float engineSize() const { return _engine_size; }

    int horsepower() const { return _horsepower; }

    EngineType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

std::string DisplayEngineType(EngineType type);

#endif // ENGINE_H
