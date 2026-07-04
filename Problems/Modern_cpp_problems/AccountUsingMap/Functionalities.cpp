#include "Functionalities.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include <map>
#include "Account.h"
#include "Customer.h"

// container hold customer pointer
using customerContaier = std::map<int, std::unique_ptr<Customer>>;

// container hold customer raw pointer
using RAWcustomerContainer = std::list<Customer *>;

// containe hold Account pointer
using accoutContainer = std::list<std::unique_ptr<Account>>;

void CreateObjectCutomer(customerContaier &customerObject,
                         accoutContainer &accountObject)
{
    accountObject.push_back(std::make_unique<Account>("101a", 1200.0f));
    accountObject.push_back(std::make_unique<Account>("102a", 2200.0f));
    accountObject.push_back(std::make_unique<Account>("103a", 3200.0f));

    auto itr = accountObject.begin();

    customerObject.emplace(101,
                           std::make_unique<Customer>(101, "Shubam", CustomerType::PREMIUM,
                                                      std::vector{10.0f, 2.0f, 3.f, 4.f, 5.f},
                                                      120.0f,
                                                      std::move(*itr++)));

    customerObject.emplace(102,
                           std::make_unique<Customer>(102, "Awale", CustomerType::REGULAR,
                                                      std::vector{10.0f, 20.0f, 3.f, 4.f, 5.f},
                                                      120.0f,
                                                      std::move(*itr++)));

    customerObject.emplace(103,
                           std::make_unique<Customer>(103, "SIM-ran", CustomerType::VIP,
                                                      std::vector{10.0f, 2.0f, 3.f, 40.f, 50.f},
                                                      120.0f,
                                                      std::move(*itr++)));
}

std::string HigherTransactionAmount(customerContaier &customerObject)
{
    // check whether containe is empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Map containe is empty\n");
    }

    static std::vector<int> sum{0};
    static int i = 0, count = INT8_MIN;
    std::string higherId;

    for (auto &[key, object] : customerObject)
    {

        auto trasactionSum = 0;
        for (float &transaction : object.get()->getCustomerTransactionAmounts())
        {
            trasactionSum += transaction;
        }
        sum[i] = trasactionSum; // stored all transaction addition

        if (count < sum[i])
        {
            higherId = object.get()->getCustomerName();
            count = sum[i];
        }
    }

    return higherId;
}

std::optional<RAWcustomerContainer>
MatchedCustomerType(customerContaier &customerObject, CustomerType type)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    RAWcustomerContainer store;

    for (auto &[key, object] : customerObject)
    {
        if (type == object.get()->getCustomerType())
        {
            store.push_back(object.get());
        }
    }

    return std::make_optional(std::move(store));
}

std::optional<RAWcustomerContainer>
BalanceOver5000(customerContaier &customerObject)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    RAWcustomerContainer store;

    for (auto &[key, object] : customerObject)
    {
        if ((object.get()->getCustomerStoreCredits() >= 100 &&
             object.get()->getCustomerStoreCredits() <= 200) &&
            object.get()->getCustomerAccount()->balance() > 500)
        {
            store.push_back(object.get());
        }
    }

    return std::make_optional(std::move(store));
}

// void HighestLowestCredits(customerContaier &customerObject)
// {
//     // check whether container empty or not
//     if (customerObject.empty())
//     {
//         throw std::runtime_error("Container is empty\n");
//     }

//     auto maxItr = std::max_element(
//         customerObject.begin(),
//         customerObject.end(),
//         [](std::unique_ptr<Customer> &customer1,
//            std::unique_ptr<Customer> &customer2)
//         {
//             return customer1.get()->getCustomerStoreCredits() <
//                    customer2.get()->getCustomerStoreCredits();
//         });
//     std::cout << "The highest store credit customer is "
//               << *maxItr << "\n";

//     auto minItr = std::min_element(
//         customerObject.begin(),
//         customerObject.end(),
//         [](std::unique_ptr<Customer> &customer1,
//            std::unique_ptr<Customer> &customer2)
//         {
//             return customer1.get()->getCustomerStoreCredits() <
//                    customer2.get()->getCustomerStoreCredits();
//         });
//     std::cout << "The Lowest store credit customer is "
//               << **minItr << "\n";
// }

float AvergeOfStoreCredits(
    customerContaier &customerObject, CustomerType type)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    // calculate the sum of all matched type
    float sum = std::accumulate(
        customerObject.begin()->second,
        customerObject.end()->second,
        0.0f,
        [&type](float ans, auto &obj1)
        {
            if (type == obj1.get()->getCustomerType())
            {
                return obj1.get()->getCustomerStoreCredits() + ans;
            }

            return ans + 0.0f;
        });

    // calculate the count of all matched type
    int count = std::count_if(
        customerObject.begin(),
        customerObject.end(),
        [&type](auto &obj)
        {
            return type == obj.get()->getCustomerType();
        });

    return sum / (float)count;
}

int CountCustomerTypeRegular(customerContaier &customerObject)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    return std::count_if(
        customerObject.begin(),
        customerObject.end(),
        [](auto &object)
        {
            return object.get()->getCustomerType() == CustomerType::REGULAR;
        });
}
