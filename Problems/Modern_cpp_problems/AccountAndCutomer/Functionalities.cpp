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

void CreateObjectCutomer(customerContaier &customerObject, accoutContainer &accountObject)
{
    accountObject.push_back(std::make_unique<Account>("101a", 1200.0f));
    accountObject.push_back(std::make_unique<Account>("102a", 2200.0f));
    accountObject.push_back(std::make_unique<Account>("103a", 3200.0f));

    auto itr = accountObject.begin();

    std::vector<float> arr1{10.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> arr2{10.0f, 20.0f, 3.0f, 4.0f, 50.0f};
    std::vector<float> arr3{10.0f, 2.0f, 3.0f, 40.0f, 5.0f};

    customerObject.push_back(std::make_unique<Customer>(
        101, "Shubham", CustomerType::PREMIUM,
        arr1,
        90.0f, std::move(*itr++)));
    customerObject.push_back(std::make_unique<Customer>(
        102, "Awale", CustomerType::VIP,
        arr2,
        120.0f, std::move(*itr++)));
    customerObject.push_back(std::make_unique<Customer>(
        103, "Simaran", CustomerType::REGULAR,
        arr3,
        290.0f, std::move(*itr)));
}

auto CalculateSum(const std::unique_ptr<Customer> &object)
{
    // bind iterator with variable ,then execute accumulate
    // because of resize and volatile nature of vector and list.
    auto a = object.get()->getCustomerTransactionAmounts();

    auto start = a.begin();
    auto end = a.end();

    return std::accumulate(
        start,
        end,
        0.0f);
}

std::string HigherTransactionAmount(customerContaier &customerObject)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    static std::vector<int> sum{0};
    static int i = 0, count = INT8_MIN;
    std::string higherId;

    // for (auto &object : customerObject)
    // {

    //     auto trasactionSum = 0;
    //     for (float &transaction : object.get()->getCustomerTransactionAmounts())
    //     {
    //         trasactionSum += transaction;
    //     }
    //     sum[i] = trasactionSum; // stored all transaction addition

    //     if (count < sum[i])
    //     {
    //         higherId = object.get()->getCustomerName();
    //         count = sum[i];
    //     }
    // }

    auto itr = std::max_element(
        customerObject.begin(),
        customerObject.end(),
        [&](std::unique_ptr<Customer> &obj1,
            std::unique_ptr<Customer> &obj2)
        {
            return CalculateSum(obj1) < CalculateSum(obj2);
        });

    higherId = itr->get()->getCustomerName();

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

    for (auto &object : customerObject)
    {
        if (type == object.get()->getCustomerType())
        {
            store.push_back(object.get());
        }
    }

    // auto itr = std::copy_if(
    //     customerObject.begin()->get(),
    //     customerObject.end()->get(),
    //     store.begin(),
    //     [&type](Customer *obj)
    //     {
    //         return type == obj->getCustomerType();
    //     });

    return std::make_optional(std::move(store));
}

std::optional<RAWcustomerContainer> BalanceOver5000(customerContaier &customerObject)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    RAWcustomerContainer store;

    for (auto &object : customerObject)
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

void HighestLowestCredits(customerContaier &customerObject)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    auto maxItr = std::max_element(
        customerObject.begin(),
        customerObject.end(),
        [](std::unique_ptr<Customer> &customer1,
           std::unique_ptr<Customer> &customer2)
        {
            return customer1.get()->getCustomerStoreCredits() <
                   customer2.get()->getCustomerStoreCredits();
        });
    std::cout << "The highest store credit customer is "
              << **maxItr << "\n";

    auto minItr = std::min_element(
        customerObject.begin(),
        customerObject.end(),
        [](std::unique_ptr<Customer> &customer1,
           std::unique_ptr<Customer> &customer2)
        {
            return customer1.get()->getCustomerStoreCredits() <
                   customer2.get()->getCustomerStoreCredits();
        });
    std::cout << "The Lowest store credit customer is "
              << **minItr << "\n";
}

float AvergeOfStoreCredits(customerContaier &customerObject, CustomerType type)
{
    // check whether container empty or not
    if (customerObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    // calculate the sum of all matched type
    float sum = std::accumulate(
        customerObject.begin(),
        customerObject.end(),
        0.0f,
        [&type](float ans, std::unique_ptr<Customer> &obj1)
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
        [&type](std::unique_ptr<Customer> &obj)
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
        [](std::unique_ptr<Customer> &object)
        {
            return object.get()->getCustomerType() == CustomerType::REGULAR;
        });
}
