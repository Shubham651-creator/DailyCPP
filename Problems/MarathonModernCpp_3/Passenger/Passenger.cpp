#include "Passenger.h"

Passenger::Passenger(std::variant<int, std::string> id,
                     std::string name, int age, pointerOfTicket ticket, float fare)
    : passengerId(id), passengerName(name), passengerAge(age), passengerTicket(ticket), passengerFare(fare)
{
}
std::ostream &operator<<(std::ostream &os, const Passenger &rhs)
{
    os << "passengerId: ";

    std::visit([&](auto &&val)
               { os << val << '\n'; },
               rhs.passengerId);
    os << " passengerName: " << rhs.passengerName
       << " passengerAge: " << rhs.passengerAge
       << " passengerTicket: " << *(rhs.passengerTicket.get())
       << " passengerFare: " << rhs.passengerFare;
    return os;
}
