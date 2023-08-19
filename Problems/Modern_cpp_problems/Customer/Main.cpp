#include <iostream>
#include <vector>
#include <list>
#include "Functionalities.h"
#include "Customer.h"

// vector Container which store float
using container = std::vector<float>;

// list container to store Custome objects
using objectContainer = std::vector<Customer *>;

int main()
{
    objectContainer customerObjects;
    CreateObjects(customerObjects);

    std::cout << "HighestTransactionAmount(customerObjects): "
              << HighestTransactionAmount(customerObjects) 
              << "\n============================================================\n";

    std::cout<<"SearchCustomerType(customerObjects, CustomerType::PREMIUM) : \n";
    for(Customer* customer : SearchCustomerType(customerObjects, CustomerType::PREMIUM)){
    
        std::cout<<*customer<<"\n";
    }
    std::cout<<"==============================================================\n";

    std::cout<<"SearchCustomerCredits(customerObjects):\n";
    for(Customer* customer : SearchCustomerCredits(customerObjects)){
        std::cout<<*customer<<"\n";
    }
    std::cout<<"==============================================================\n";
    
    std::cout<<"LowestHighestCredits(customerObjects):\n";
    LowestHighestCredits(customerObjects);
    std::cout<<"\n==================================================================";

    std::cout<<"\nAverageOfTypesCredits(objectContainer, CustomerType::REGULAR):\n"
    <<AverageOfTypesCredits(customerObjects, CustomerType::REGULAR)
    <<"\n\n";

    DeleteObjects(customerObjects);

    return 0;
}