#include "Functionalities.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include "Account.h"
#include "Customer.h"

// container hold customer pointer
using customerContaier = std::list<std::unique_ptr<Customer>>;

// containe hold Account pointer
using accoutContainer = std::list<std::unique_ptr<Account>>;

int main()
{

    customerContaier customerObject;
    accoutContainer accountObject;

    CreateObjectCutomer(customerObject, accountObject);

    // // display the object
    // for (auto &value : customerObject)
    // {
    //     std::cout << *value << "\n\n";
    // }

    try
    {
        std::cout << "Hight transaction amount id is :"
                  << HigherTransactionAmount(customerObject)
                  << "\n\n==========================================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Matched cutomer type functin :\n";
        auto store = MatchedCustomerType(customerObject, CustomerType::VIP);
        // display the object
        if (store.has_value())
        {
            for (auto &value : store.value())
            {
                std::cout << *value << "\n\n";
            }
        }

        std::cout
            << "\n\n==========================================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Balance over 5000 function \n\n";
        auto store = BalanceOver5000(customerObject);
        // display the object
        if (store.has_value())
        {
            for (auto &value : store.value())
            {
                std::cout << *value << "\n\n";
            }
        }

        std::cout << "==================================================\n";
        HighestLowestCredits(customerObject);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "The averge of passed customer type is "
                  << AvergeOfStoreCredits(customerObject, CustomerType::PREMIUM)
                  << "\n\n======================================================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "The count of customr type of REGULARE is  "
                  << CountCustomerTypeRegular(customerObject)
                  << "\n\n======================================================\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}