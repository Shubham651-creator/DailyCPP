#ifndef DATARECORD_H
#define DATARECORD_H

#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include "DataUnitType.h"
#include "DataUnit.h"

// Pointer to dataUnit instances
using Pointer = std::shared_ptr<DataUnit>;

// reference pointer to Dataunit instances
using refPointer = std::reference_wrapper<Pointer>;

class DataRecord
{
private:
    std::vector<int> _data_values_provided;
    std::vector<int> _data_values_expected;
    refPointer _data_unit;

public:
    // disable default constructor
    DataRecord() = default;

    // disable copy constrcutor
    DataRecord(const DataRecord &) = default;

    // disable copy operator
    DataRecord &operator=(DataRecord &) = default;

    // disable move constrcutor
    DataRecord(DataRecord &&) = default;

    // disable move operator
    DataRecord &operator=(DataRecord &&) = default;

    // parameterized constructor
    DataRecord(refPointer dataUnit, std::vector<int> provided, std::vector<int> expected);     
     
    // destructor
    ~DataRecord() = default;

    std::vector<int> dataValuesProvided() const { return _data_values_provided; }

    std::vector<int> dataValuesExpected() const { return _data_values_expected; }

    refPointer dataUnit() const { return _data_unit; }

    friend std::ostream &operator<<(std::ostream &os, const DataRecord &rhs);
};

#endif // DATARECORD_H
