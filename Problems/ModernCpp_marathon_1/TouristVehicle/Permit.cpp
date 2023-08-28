#include "Permit.h"

std::ostream &operator<<(std::ostream &os, const Permit &rhs)
{
    os << "\n_serial_number: " << rhs._serial_number
       << " \n_permit_type: " << DisplayPermitType(rhs._permit_type)
       << "\n _permit_duration_left: " << rhs._permit_duration_left
       <<"\n\n";
    return os;
}
std::string DisplayPermitType(PermitType type)
{
    if (type == PermitType::LEASE)
        return "LEASE";

    return "OWNED";
}

Permit::Permit(std::string serial, PermitType pType, int duration)
    : _serial_number(serial), _permit_type(pType), _permit_duration_left(duration) {}
