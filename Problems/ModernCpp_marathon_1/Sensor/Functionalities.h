#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <list>
#include <memory>
#include "Sensor.h"
#include "SensorType.h"

// store the shared ptr in container of list
using container = std::list<std::shared_ptr<Sensor>>;

// create the objects
void CreateObjects(container &object) noexcept;

// a function whose check all instance of sensor show
//_reading value above 25
bool ReadingAbove25(container &object);

// a function to find count of sensor of instance of _type
// passed as parameter
int CountOfSensorOfType(container &object, SensorType sensorType);

// a function to return container of all sensor which
// _reading is 15 or above
// and _type is TYRE_PRESSURE
container ConditionOnReadingAndType(container& object);

#endif // FUNCTIONALITIES_H
