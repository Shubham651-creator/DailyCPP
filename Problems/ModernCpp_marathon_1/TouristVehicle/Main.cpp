#include <iostream>
#include <list>
#include <memory>
#include "TouristVehicle.h"
#include "Permit.h"
#include "Functionalites.h"

// list container which stores tourist objects
using touristVehicleContainer = std::list<std::shared_ptr<TouristVehicle>>;

int main()
{
    touristVehicleContainer touristObjects;

    try
    {
        CreateObjectsOfTourist(touristObjects);

        // display the information
        for (std::shared_ptr<TouristVehicle> value : touristObjects)
        {
            std::cout << *value << "\n";
        }

        std::cout << "\n=============================================================\n";

        std::cout<<"display the instance whose seat count >= 4 and permit type is lease\n";
        for (std::shared_ptr<TouristVehicle> value : ConditionSeatCountAndPermitType(touristObjects))
        {
            std::cout << *value << "\n";
        }
        std::cout << "\n=============================================================\n";

        std::cout<<"The average of booking charge of type CAB is "
        <<AvergeOfTypeCAB(touristObjects)
        <<".\n=========================================================\n";

        std::cout<<"The maximum booking charge and its serial number is "
        <<BookingChargeIsMaximum(touristObjects)
        <<".\n==============================================================\n";

        std::cout<<"The first N instances are \n";
        for (std::shared_ptr<TouristVehicle> value : FirstNInstance(touristObjects, 2))
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