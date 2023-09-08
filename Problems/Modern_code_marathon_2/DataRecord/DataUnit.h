#ifndef DATAUNIT_H
#define DATAUNIT_H

#include<iostream>
#include "DataUnitType.h"

class DataUnit
{
private:
    int _unit_id;
    DataUnitType _unit_type;
    float _unit_reading;

public:
    // disable default constructor
    DataUnit() = default;

    // disable copy constructor
    DataUnit(const DataUnit &) = default;

    // disable copy operator constructor
    DataUnit &operator=(DataUnit &) = default;

    // disable copy constructor
    DataUnit(DataUnit &&) = default;

    // disable copy operator constructor
    DataUnit &operator=(DataUnit &&) = default;

    // parameterized constructor
    DataUnit(int id, DataUnitType type, float units);

    // destructor
    ~DataUnit() = default;

    int unitId() const { return _unit_id; }

    DataUnitType unitType() const { return _unit_type; }

    float unitReading() const { return _unit_reading; }

    friend std::ostream &operator<<(std::ostream &os, const DataUnit &rhs);
};

std::string DisplayDataType(DataUnitType type);

#endif // DATAUNIT_H
