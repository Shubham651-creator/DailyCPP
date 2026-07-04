#include "Sensor.h"

Sensor::Sensor(int id, std::string name, SensorType type, int reading)
    : _id(id), _name(name), _type(type), _reading(reading) {}

std::ostream &operator<<(std::ostream &os, const Sensor &rhs)
{
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _type: " << DisplaySensorType(rhs._type)
       << " _reading: " << rhs._reading;
    return os;
}

std::string DisplaySensorType(SensorType sensorType)
{
    if (sensorType == SensorType::CABIN_PRESSURE)
        return "CABIN_PRESSURE";
    if (sensorType == SensorType::TYPE_PRESSURE)
        return "TYPE_PRESSURE";

    return "TEMPERTURE";
}
