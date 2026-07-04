#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <memory>
#include <variant>
#include "Insureance.h"
#include "VehicleType.h"

using insurancePointer = std::unique_ptr<Insureance>;
using refPointer = std::reference_wrapper<insurancePointer>;

class Vehicle
{
private:
    std::variant<int, std::string> vehicleId;
    int vehicleRegistration;
    VehicleType vehicleType;
    refPointer vehicleInsurancePlan;
    // insurancePointer _vPointer;

public:
    Vehicle() = delete;

    Vehicle(const Vehicle &) = delete;

    Vehicle &operator=(Vehicle &) = delete;

    Vehicle(Vehicle &&) = delete;

    Vehicle &operator=(Vehicle &&) = delete;

    Vehicle(std::variant<int, std::string> id, int registration, VehicleType type, refPointer plan);

    ~Vehicle() = default;

    int getVehicleRegistration() const { return vehicleRegistration; }

    VehicleType getVehicleType() const { return vehicleType; }

    std::variant<int, std::string> getVehicleId() const { return vehicleId; }

    refPointer getVehicleInsurancePlan() const { return vehicleInsurancePlan; }

    // // getter of unique ptr
    // Insureance *vPointer() const { return _vPointer.get(); }
    // void setVPointer(Insureance *&vPointer) { _vPointer.reset(vPointer); }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

std::string DisplayVehicleType(VehicleType type);

#endif // VEHICLE_H
