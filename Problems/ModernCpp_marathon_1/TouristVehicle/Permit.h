#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>
#include <list>
#include <memory>
#include "TouristVehicleType.h"
#include "PermitType.h"

class Permit
{
private:
    std::string _serial_number;
    PermitType _permit_type;
    int _permit_duration_left;

public:
    // disable default constructor
    Permit() = delete;

    // disable copy constructor
    explicit Permit(const Permit &) = delete;

    // disable copy operator constructor
    Permit &operator=(Permit &) = delete;

    // disable move constructor
    Permit(const Permit &&) = delete;

    // disable move operator constructor
    Permit &operator=(Permit &&) = delete;

    // paramterized constructor
    Permit(std::string serial, PermitType pType, int duration);
    
    // destructor
    ~Permit() = default;

    std::string serialNumber() const { return _serial_number; }
    void setSerialNumber(const std::string &serial_number) { _serial_number = serial_number; }

    PermitType permitType() const { return _permit_type; }
    void setPermitType(const PermitType &permit_type) { _permit_type = permit_type; }

    int permitDurationLeft() const { return _permit_duration_left; }
    void setPermitDurationLeft(int permit_duration_left) { _permit_duration_left = permit_duration_left; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

std::string DisplayPermitType(PermitType type);

#endif // PERMIT_H
