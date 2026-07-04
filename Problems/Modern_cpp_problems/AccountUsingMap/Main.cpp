#include "Functionalities.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include "Account.h"
#include "Customer.h"

// container hold customer pointer
using customerContaier = std::map<int, std::unique_ptr<Customer>>;

// container hold customer raw pointer
using RAWcustomerContainer = std::list<Customer *>;

// containe hold Account pointer
using accoutContainer = std::list<std::unique_ptr<Account>>;

int main()
{
    accoutContainer accountObject;
    customerContaier customerMap;

    try
    {
        CreateObjectCutomer(customerMap, accountObject);

        // display map object
        for (auto &[key, value] : customerMap)
        {
            std::cout << "Key = " << key << ": \n";
            std::cout << *(value.get()) << "\n\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Hight transaction amount id is :"
                  << HigherTransactionAmount(customerMap)
                  << "\n\n==========================================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "Matched cutomer type functin :\n";
        auto store = MatchedCustomerType(customerMap, CustomerType::VIP);
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
        auto store = BalanceOver5000(customerMap);
        // display the object
        if (store.has_value())
        {
            for (auto &value : store.value())
            {
                std::cout << *value << "\n\n";
            }
        }

        // std::cout << "==================================================\n";
        // HighestLowestCredits(customerMap);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "The averge of passed customer type is "
                  << AvergeOfStoreCredits(customerMap, CustomerType::PREMIUM)
                  << "\n\n======================================================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "The count of customr type of REGULARE is  "
                  << CountCustomerTypeRegular(customerMap)
                  << "\n\n======================================================\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}