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

int main()
{

    ContainerDebit debitObject;
    variantContainer variantObject;

    try
    {
        CreateObject(variantObject);

        for (auto &value : variantObject)
        {
            std::visit([](auto &&val)
                       { std::cout << *val << "\n"; },
                       value);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "The average of annual charge is "
                  << AverageOfCharge(variantObject, DebitCardType::DOMESTIC)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "first N isntance \n";
        for (auto &value : FirstNisntance(variantObject, 2))
        {
            std::visit([](auto &&val)
                       { std::cout << *val << "\n"; },
                       value);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "CVV\n"
                  << CheckCVV(variantObject, 123456)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "count instance \n"
                  << CountInstacneType(variantObject, DebitCardType::DOMESTIC)
                  << "\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}