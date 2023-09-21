#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <memory>
#include <variant>
#include "Ticket.h"

using pointerOfTicket = std::shared_ptr<Ticket>;

class Passenger
{
private:
    std::variant<int, std::string> passengerId;
    std::string passengerName;
    int passengerAge;
    pointerOfTicket passengerTicket;
    float passengerFare;

public:
    Passenger() = delete;

    Passenger(const Passenger &) = delete;

    Passenger &operator=(Passenger &) = delete;

    Passenger(Passenger &&) = delete;

    Passenger &operator=(Passenger &&) = delete;

    Passenger(std::variant<int, std::string> id, std::string name,
              int age, pointerOfTicket ticket, float fare);

    ~Passenger() = default;

    std::variant<int, std::string> getPassengerId() const { return passengerId; }

    std::string getPassengerName() const { return passengerName; }

    int getPassengerAge() const { return passengerAge; }

    pointerOfTicket getPassengerTicket() const { return passengerTicket; }

    float getPassengerFare() const { return passengerFare; }

    friend std::ostream &operator<<(std::ostream &os, const Passenger &rhs);
};

#endif // PASSENGER_H
