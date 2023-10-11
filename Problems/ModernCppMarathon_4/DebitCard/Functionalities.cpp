#include "Functionalities.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
#include <vector>
#include <optional>
#include <variant>
#include "DebitCard.h"
#include "CreditCard.h"

// pointer to debit card
using PointerToDebit = std::shared_ptr<DebitCard>;
// vector container of debit card
using ContainerDebit = std::vector<PointerToDebit>;

// pointer to credit card
using PointerToCredit = std::shared_ptr<CreditCard>;
// vector container of credit card
using ContainerCredit = std::vector<PointerToCredit>;

// variant Pointer
using variantPointer = std::variant<PointerToCredit,
                                    PointerToDebit>;
// variant container
using variantContainer = std::vector<variantPointer>;

void CreateObject(variantContainer &container)
{
    // ContainerDebit container;
    container.push_back(std::make_shared<DebitCard>(
        123456,
        369,
        CardType::DOMESTIC,
        2469,
        120.0f));

    container.push_back(std::make_shared<DebitCard>(
        123457,
        367,
        CardType::INTERNATIONL,
        2467,
        127.0f));

    container.push_back(std::make_shared<DebitCard>(
        123458,
        368,
        CardType::DOMESTIC,
        2468,
        128.0f));

    container.push_back(std::make_shared<DebitCard>(
        123410,
        361,
        CardType::INTERNATIONL,
        2461,
        121.0f));

    container.push_back(std::make_shared<DebitCard>(
        123452,
        362,
        CardType::DOMESTIC,
        2462,
        122.0f));
}

float AverageOfCharge(variantContainer &variantObject, CardType type)
{
    // check whether container empty or not.
    if (variantObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = 0;
    float sum = 0;

    for (auto &objects : variantObject)
    {
        std::visit([&](auto &&pointer)
                   {count++; 
                    if(pointer->type() == type){
                        sum += pointer->annualCharge();
                    } },
                   objects);
    }

    return sum / count;
}

bool AllInstanceSameType(variantContainer &variantObject, CardType type)
{
    // check whether container empty or not.
    if (variantObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    bool flag = true;
    for (auto &objects : variantObject)
    {
        std::visit([&](auto &&pointer)
                   {
            if(type != pointer->type()){
                flag = false;
            } },
                   objects);
    }

    return flag;
}

variantContainer FirstNisntance(variantContainer &variantObject, int N)
{
    // check whether container empty or not.
    if (variantObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    variantContainer result;

    int count = 0;
    for (auto &value : variantObject)
    {
        if (count < N)
        {
            count++;
            result.push_back(value);
        }
    }

    return result;
}

int CheckCVV(variantContainer &variantObject, int N)
{
    // check whether container empty or not.
    if (variantObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int resultCVV;
    for (auto &value : variantObject)
    {
        std::visit([&](auto &&pointer)
                   {
            if(pointer->number() == N){
                resultCVV = pointer->cvv();
            } },
                   value);
    }

    return resultCVV;
}

int CountInstacneType(variantContainer &variantObject, CardType type)
{
    // check whether container empty or not.
    if (variantObject.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    int count = 0;
    for (auto &objects : variantObject)
    {
        std::visit([&](auto &&pointer)
                   {
            if(type == pointer->type()){
                count++;
            } },
                   objects);
    }

    return count;
}
