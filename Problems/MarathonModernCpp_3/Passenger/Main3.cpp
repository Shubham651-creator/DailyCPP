#include <iostream>
#include <memory>
#include <variant>
#include <algorithm>
#include <vector>
#include <array>
#include <thread>
#include <future>
#include <numeric>
#include "Ticket.h"
#include "Passenger.h"
#include "Functionalities3.h"

using pointerOfTicket = std::shared_ptr<Ticket>;
using pointerOfPassenger = std::shared_ptr<Passenger>;

using TicketContainer = std::vector<pointerOfTicket>;
using PassengerContainer = std::vector<pointerOfPassenger>;

void DoNotMatchName(PassengerContainer &passengerObjects,
                    PassengerContainer &store,
                    std::future<std::string> &name)
{
    // check empty
    if (passengerObjects.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    std::string PName = name.get();
    for (auto &value : passengerObjects)
    {
        if (value.get()->getPassengerName() != PName)
        {
            store.push_back(value);
        }
    }
    for (auto &value : store)
    {
        std::cout << *value << '\n';
    }
}

int main()
{
    PassengerContainer passengerObjects;
    TicketContainer ticketObjects;

    try
    {
        CreateObjectTicket(std::ref(ticketObjects), 1220.0f, TicketType::GERNERAL);
        CreateObjectTicket(std::ref(ticketObjects), 2220.0f, TicketType::RESERVED);
        CreateObjectTicket(std::ref(ticketObjects), 3220.0f, TicketType::GERNERAL);
        CreateObjectTicket(std::ref(ticketObjects), 4220.0f, TicketType::RESERVED);
        CreateObjectTicket(std::ref(ticketObjects), 5220.0f, TicketType::RESERVED);

        std::array<std::thread, 5> threadObjects;

        threadObjects[0] = std::thread(&CreateObjectPassenger, std::ref(passengerObjects), std::ref(ticketObjects),
                                       101, "shubam", 21, std::ref(ticketObjects[0]), 1220.0f);
        threadObjects[1] = std::thread(&CreateObjectPassenger, std::ref(passengerObjects), std::ref(ticketObjects),
                                       102, "shubam", 22, std::ref(ticketObjects[1]), 1220.0f);
        threadObjects[2] = std::thread(&CreateObjectPassenger, std::ref(passengerObjects), std::ref(ticketObjects),
                                       103, "awale", 23, std::ref(ticketObjects[2]), 1220.0f);
        threadObjects[3] = std::thread(&CreateObjectPassenger, std::ref(passengerObjects), std::ref(ticketObjects),
                                       104, "shu", 24, std::ref(ticketObjects[3]), 1220.0f);
        threadObjects[4] = std::thread(&CreateObjectPassenger, std::ref(passengerObjects), std::ref(ticketObjects),
                                       105, "shubam", 25, std::ref(ticketObjects[4]), 1220.0f);

        for (int i = 0; i < 5; i++)
        {
            threadObjects[i].join();
        }

        for (auto &value : passengerObjects)
        {
            std::cout << *value << '\n';
        }

        std::cout << "thread of second function\n";
        std::vector<std::variant<int, std::string>> store;

        for (auto &value : passengerObjects)
        {
            store.push_back(value.get()->getPassengerId());
        }

        auto age = std::thread(&AverageOfAge, std::ref(passengerObjects), store);
        age.join();

        std::cout << "thread of third function\n";
        auto idFunction = std::thread(&IdMatchesPassenger, std::ref(passengerObjects),
                                      101);
        idFunction.join();

        std::cout << "thread of fourth function\n";
        auto fourFunction = std::thread(&PassengerFareFunction,
                                        std::ref(passengerObjects), std::ref(passengerObjects));
        fourFunction.join();

        std::cout << "thread of fifth function\n";
        TicketContainer passContainer;
        auto fiveFunction = std::thread(&FirstNInstance,
                                        std::ref(passengerObjects), std::ref(passContainer), 2);
        for (auto &value : passContainer)
        {
            std::cout << *value << '\n';
        }
        fiveFunction.join();

        std::cout << "thread of sixth function\n=================================================";

        std::string tempName;
        std::promise<std::string> NamePromise;
        std::future<std::string> futureName = NamePromise.get_future();

        PassengerContainer sixstore;

        std::async(std::launch::async, &DoNotMatchName,
                   std::ref(passengerObjects), std::ref(sixstore), std::ref(futureName));

        std::cout << "Enter name : ";
        std::cin >> tempName;
        NamePromise.set_value(tempName);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}