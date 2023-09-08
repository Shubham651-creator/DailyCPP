#include "DataUnit.h"
std::ostream &operator<<(std::ostream &os, const DataUnit &rhs)
{
    os << "_unit_id: " << rhs._unit_id
       << " _unit_type: " << DisplayDataType(rhs._unit_type)
       << " _unit_reading: " << rhs._unit_reading;
    return os;
}
std::string DisplayDataType(DataUnitType type)
{
    if (type == DataUnitType::IN_HOUSE)
        return "IN_HOUSE";

    return "OUTSOURCED";
}
DataUnit::DataUnit(int id, DataUnitType type, float units)
    : _unit_id(id), _unit_type(type), _unit_reading(units) {}
