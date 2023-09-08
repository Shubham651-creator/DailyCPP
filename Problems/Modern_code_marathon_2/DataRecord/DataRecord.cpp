#include "DataRecord.h"

std::ostream &operator<<(std::ostream &os, const DataRecord &rhs)
{
    os << "\n_data_values_provided:\t ";
    for (auto &values : rhs._data_values_provided)
    {
        os << values << '\t';
    }

    os << "\n _data_values_expected: ";
    for (auto &values : rhs._data_values_expected)
    {
        os << values << '\t';
    }

    os << " \n_data_unit: " << *(rhs._data_unit.get()) << '\n';
    return os;
}

DataRecord::DataRecord(refPointer dataUnit, std::vector<int> provided, std::vector<int> expected)
    : _data_values_provided(provided), _data_values_expected(expected), _data_unit(dataUnit) {}
 