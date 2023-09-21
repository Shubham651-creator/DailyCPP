#ifndef FUNCTIONALITIES3_H
#define FUNCTIONALITIES3_H

#include <iostream>
#include <memory>
#include <variant>
#include <algorithm>
#include <vector>
#include <future>
#include <thread>
#include <numeric>
#include "Ticket.h"
#include "Passenger.h"

using pointerOfTicket = std::shared_ptr<Ticket>;
using pointerOfPassenger = std::shared_ptr<Passenger>;

using TicketContainer = std::vector<pointerOfTicket>;
using PassengerContainer = std::vector<pointerOfPassenger>;

/*
    Create objects using async
*/

void CreateObjectTicket(TicketContainer &ticketObjects,
                        float tax, TicketType type);

void CreateObjectPassenger(PassengerContainer &passengerObjects, TicketContainer &ticketObjects,
                           std::variant<int, std::string> id, std::string name,
                           int age, pointerOfTicket ticket, float fare);

/*
    2. print average passenger age whose id matche
    with instance
*/
void AverageOfAge(PassengerContainer &passengerObjects,
                  std::vector<std::variant<int, std::string>> id);

/*
    3. print details of passenger instance whose id matche
*/
void IdMatchesPassenger(PassengerContainer &passengerObjects,
                        std::variant<int, std::string> id);

/*
    4.  print details of passenger whose fare is min
    from container of instance passed
*/
void PassengerFareFunction(PassengerContainer &passengerObjects,
                           PassengerContainer &fareObject);

/*
    5. copy ticket of first N instances of passger class
*/
void FirstNInstance(PassengerContainer &passengerObjects, TicketContainer &ticketObject,
                    int N);

/*
    6. accpets name and containe of passenger.
    it stores all instacne whose don't match wiht name
*/
void DoNotMatchName(PassengerContainer &passengerObjects,
                    PassengerContainer &store,
                    std::future<std::string> &name);

#endif // FUNCTIONALITIES3_H
