#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H

enum class VehicleType
{
    UTILITY,
    SPORTS,
    PASSENGER,
    COMMUTE
};

inline std::string DisplayVehicleType(VehicleType type)
{
    if (type == VehicleType::PASSENGER)
    {
        return "PASSENGER";
    }

    if (type == VehicleType::UTILITY)
    {
        return "UTILITY";
    }

    if (type == VehicleType::COMMUTE)
    {
        return "COMMUTE";
    }

    return "SPORTS";
}
#endif // VEHICLETYPE_H
