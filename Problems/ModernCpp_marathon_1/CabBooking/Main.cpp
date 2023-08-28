#include <iostream>
#include <list>
#include <memory>
#include "CabBooking.h"
#include "OnlinePaymentCabBooking.h"
#include "CashPaymentCabBooking.h"
#include "Functionalities.h"

// list container which holds objects of onlinePayment
// and cashPayment
using container = std::list<std::shared_ptr<CabBooking>>;

int main()
{
    container objects;

    try
    {
        CreateObjects(objects);

        for (std::shared_ptr<CabBooking> &value : objects)
        {
            std::cout << *value << "\n";
        }

        std::cout << "\n================================\n";

        std::cout << "ConditionPickupLocation(objects,pune) :";
        for (std::shared_ptr<CabBooking> &value : ConditionPickupLocation(objects, "Pune"))
        {
            std::cout << *value << "\n";
        }
        std::cout << "\n================================\n";

        std::cout << "First N instance :\n";
        for (std::shared_ptr<CabBooking> &value : FirstNInstance(objects, 2))
        {
            std::cout << *value << "\n";
        }
        std::cout << "\n================================\n";

        std::cout << "max cab fare calculation is booking id is "
                  << MaxCabFareCalculation(objects)
                  << "\n===========================\n";

        std::cout << "average is " << AverageOfOnlinePayment(objects)
                  << "\n==================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}