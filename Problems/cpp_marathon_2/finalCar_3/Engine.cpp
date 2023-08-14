#include <iostream>
#include "Engine.h"

Engine::Engine()
{
    engineNumber = "engine1223";
    engineType = EngineType::HYBIRD;
    engineHorsepower = 200;
    engineTorque = 31; // torque are in Newton meters
}

Engine::Engine(std::string enumber, enum EngineType etype, int horsepower, int torque)
    : engineNumber(enumber), engineType(etype), engineHorsepower(horsepower), engineTorque(torque)
{
}

Engine::Engine(Engine &engine)
{
    engineNumber = engine.engineHorsepower;
    engineType = engine.engineType;
    engineHorsepower = engine.engineHorsepower;
    engineTorque = engine.engineTorque;
}

Engine::~Engine()
{
}

std::string Engine::displayEngineType(EngineType type)
{
    if (type == EngineType::ICT)
        return "ICT";
    if (type == EngineType::HYBIRD)
        return "HYBIRD";
    else
        return "NA";
}

void operator<<(std::ostream &out, Engine &engine)
{
    out << "The engine Details are given below \n"
        << "Engine Number = " << engine.engineNumber
        << "\nEngine Type = " << engine.displayEngineType(engine.engineType)
        << "\nEngine Horsepower = " << engine.engineHorsepower
        << "\nEngine Torque = " << engine.engineTorque
        << "\n\n";
}