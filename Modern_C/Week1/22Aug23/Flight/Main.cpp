#include <iostream>
#include <memory>
#include <vector>
#include "Functionalities.h"
#include "Flight.h"

// vector of container which holds object of Flight
using ContainerOfFight = std::vector<std::shared_ptr<Flight>>;

int main()
{
    ContainerOfFight container;

    // create object function
    CreateObjects(container);

    std::cout<<"AverageOfFare(container) : \n" <<AverageOfFare(container)<<"\n\n";

    std::cout<<"MinimumFare(container):\n"<<MinimumFare(container)<<"\n\n";

    std::cout<<"FirstNInstance(container,2):\n";
     //display
    for (std::shared_ptr<Flight> value : FirstNInstance(container, 2))
    {
        std::cout << *value << "\n\n";
    }

    return 0;
}