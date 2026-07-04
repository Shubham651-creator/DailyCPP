#include "Vehicle.h"

Vehicle::Vehicle(std::variant<int, std::string> id, int registration, VehicleType type, refPointer plan)
    : vehicleId(id), vehicleRegistration(registration), vehicleType(type), vehicleInsurancePlan(plan) {}

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs)
{
    os << "vehicleId: ";

    std::visit([&](auto&& val){ os << val;}, rhs.vehicleId);

    os << " vehicleRegistration: " << rhs.vehicleRegistration
       << " vehicleType: " << DisplayVehicleType(rhs.vehicleType)
       << " vehicleInsurancePlan: " << *(rhs.vehicleInsurancePlan.get());
    return os;
}

std::string DisplayVehicleType(VehicleType type)
{
    if (type == VehicleType::SPECIAL_PURPOSE)
        return "SPECIAL_PURPOSE";
    if (type == VehicleType::COMMERCIAL)
        return "COMMERCIAL";

    return "PRVIATE";
}
