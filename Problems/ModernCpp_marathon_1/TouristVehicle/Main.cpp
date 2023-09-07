#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include "TouristVehicle.h"
#include "Permit.h"
#include "Functionalites.h"

using permitContainer = std::vector<std::shared_ptr<Permit>>;
// list container which stores tourist objects
using touristVehicleContainer = std::list<std::shared_ptr<TouristVehicle>>;
using funPointer = std::function<touristVehicleContainer(touristVehicleContainer &, int)>;

int main()
{
    touristVehicleContainer touristObjects;
    permitContainer permitObject;

    try
    {
        CreateObjectsOfTourist(touristObjects, permitObject);

        // display the information
        for (std::shared_ptr<TouristVehicle> value : touristObjects)
        {
            std::cout << *value << "\n";
        }

        std::cout << "\n=============================================================\n";

        funPointer fptr1 = &ConditionSeatCountAndPermitType;

        std::cout << "display the instance whose seat count >= 4 and permit type is lease\n";
        for (std::shared_ptr<TouristVehicle> value : Operation(touristObjects, fptr1))
        {
            std::cout << *value << "\n";
        }
        std::cout << "\n=============================================================\n";

        std::cout << "The average of booking charge of type CAB is "
                  << AvergeOfTypeCAB(touristObjects)
                  << ".\n=========================================================\n";

        std::cout << "The maximum booking charge and its serial number is "
                  << BookingChargeIsMaximum(touristObjects)
                  << ".\n==============================================================\n";

        std::cout << "The first N instances are \n";

        funPointer fptr2 = &FirstNInstance;
        for(std::shared_ptr<TouristVehicle> value : Operation(touristObjects, fptr2))
        {
            std::cout << *value << "\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}