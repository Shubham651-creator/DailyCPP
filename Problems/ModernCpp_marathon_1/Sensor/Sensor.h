#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include "SensorType.h"

class Sensor
{
private:
    int _id;
    std::string _name;
    SensorType _type;
    int _reading;

public:
    // disable constructor
    Sensor() = delete;
    // disable copy constructor
    Sensor(const Sensor &) = delete;
    // disable operator constructor
    Sensor &operator=(Sensor &) = delete;
    // disable move constructor
    Sensor(const Sensor &&) = delete;
    // disable move operator constructor
    Sensor &operator=(Sensor &&) = delete;
    // parameterized constructor
    Sensor(int id, std::string name, SensorType type, int reading);

    ~Sensor() = default;

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    SensorType type() const { return _type; }
    void setType(const SensorType &type) { _type = type; }

    int reading() const { return _reading; }
    void setReading(int reading) { _reading = reading; }

    friend std::ostream &operator<<(std::ostream &os, const Sensor &rhs);
};

std::string DisplaySensorType(SensorType sensorType);

#endif // SENSOR_H
