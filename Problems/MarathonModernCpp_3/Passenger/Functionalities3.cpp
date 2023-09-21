#include "Functionalities3.h"
#include <mutex>

std::mutex mt;

using pointerOfTicket = std::shared_ptr<Ticket>;
using pointerOfPassenger = std::shared_ptr<Passenger>;

using TicketContainer = std::vector<pointerOfTicket>;
using PassengerContainer = std::vector<pointerOfPassenger>;

void CreateObjectTicket(TicketContainer &ticketObjects, float tax, TicketType type)
{
    ticketObjects.emplace_back(std::make_shared<Ticket>(tax, type));
}

void CreateObjectPassenger(PassengerContainer &passengerObjects, TicketContainer &ticketObjects,
                           std::variant<int, std::string> id, std::string name, int age,
                           pointerOfTicket ticket, float fare)
{
    passengerObjects.emplace_back(std::make_shared<Passenger>(
        id, name, age, std::ref(ticket), fare));
}

void AverageOfAge(PassengerContainer &passengerObjects,
                  std::vector<std::variant<int, std::string>> id)
{
    // check empty
    if (passengerObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }
    int sum = 0;
    for (auto &i : id)
    {
        std::visit([&](auto &&tempId)
                   {
            for(auto& value : passengerObjects){
                if(i == value.get()->getPassengerId()){
                    sum += value.get()->getPassengerAge();
                }
            } },
                   i);
    }

    std::cout << "average of age is \n"
              << sum / passengerObjects.size() << "\n\n";
}

void IdMatchesPassenger(PassengerContainer &passengerObjects, std::variant<int, std::string> id)
{
    // check empty
    if (passengerObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    for (auto &value : passengerObjects)
    {
        if (value.get()->getPassengerId() == id)
        {
            std::cout << *value << '\n';
        }
    }
}

void PassengerFareFunction(PassengerContainer &passengerObjects,
                           PassengerContainer &fareObject)
{
    // check empty
    if (passengerObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto itr = std::min_element(
        fareObject.begin(),
        fareObject.end(),
        [&](pointerOfPassenger &obj1, pointerOfPassenger &obj2)
        {
            return obj1.get()->getPassengerFare() < obj2.get()->getPassengerFare();
        });

    std::cout << "The minimun of fare instance is \n"
              << *(itr.base()->get()) << "\n\n";
}

void FirstNInstance(PassengerContainer &passengerObjects,
                    TicketContainer &ticketObject, int N)
{
    // check empty
    if (passengerObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    for (int i = 0; i < N; i++)
    {
        ticketObject.push_back(passengerObjects[i].get()->getPassengerTicket());
    }

    for (auto &value : ticketObject)
    {
        std::cout << *value << '\n';
    }
}


