#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "TicketType.h"
#include <variant>

class Ticket
{
private:
    float _tax;
    TicketType _type;

public:
    Ticket() = delete;

    Ticket(const Ticket &) = delete;

    Ticket &operator=(Ticket &) = delete;

    Ticket(Ticket &&) = delete;

    Ticket &operator=(Ticket &&) = delete;

    Ticket(float tax, TicketType type);

    ~Ticket() = default;

    float tax() const { return _tax; }

    TicketType type() const { return _type; }

    friend std::ostream &operator<<(std::ostream &os, const Ticket &rhs);
};

std::string DisplayTicketType(TicketType type);

#endif // TICKET_H
