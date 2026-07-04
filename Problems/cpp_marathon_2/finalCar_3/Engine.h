#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "EngineType.h"

class Engine
{
private:
    std::string engineNumber;
    enum EngineType engineType;
    int engineHorsepower;
    int engineTorque;

public:
    // default constructor
    Engine();

    // parameterized constrctor
    Engine(std::string number, enum EngineType etype, int horsepower, int torque);

    // copy constructor
    Engine(Engine &engine);

    // car destructor
    ~Engine();

    //accept
    void accept();

    // operator<< overloading
    friend void operator<<(std::ostream &out, Engine &engine);

    //display the engine type
    std::string displayEngineType(EngineType type);

    std::string getEngineNumber() const { return engineNumber; }
    void setEngineNumber(const std::string &engineNumber_) { engineNumber = engineNumber_; }

    enum EngineType getEngineType() const { return engineType; }
    void setEngineType(const enum EngineType &engineType_) { engineType = engineType_; }

    int getEngineHorsepower() const { return engineHorsepower; }
    void setEngineHorsepower(int engineHorsepower_) { engineHorsepower = engineHorsepower_; }

    int getEngineTorque() const { return engineTorque; }
    void setEngineTorque(int engineTorque_) { engineTorque = engineTorque_; }
};

#endif // ENGINE_H
