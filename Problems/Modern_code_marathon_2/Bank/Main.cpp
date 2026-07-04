#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <memory>
#include "Functionalities.h"
#include "Account.h"
#include "DebitCard.h"
#include "Bank.h"

// container which stores DebitCard instaneces
using debitCardContainer = std::list<std::shared_ptr<DebitCard>>;

// container which stores account instances
using accountContainer = std::vector<std::shared_ptr<Account>>;

// container which stores Bank instances
using bankContainer = std::list<std::shared_ptr<Bank>>;

// function pointer
using funcPointer = std::function<void(bankContainer &, int)>;

int main()
{
    bankContainer bankObjects;
    accountContainer accountObjects;
    debitCardContainer debitObjects;

    try
    {
        CreateObjects(bankObjects, accountObjects, debitObjects);

        for (auto &value : bankObjects)
        {
            std::cout << *value << '\n';
        }

        funcPointer fptr3 = &FirstNInstance;
        HigherOrderFunction(bankObjects, fptr3, 6);

        funcPointer fptr4 = &MinBalanceAtLeast;
        HigherOrderFunction(bankObjects, fptr3, 500);

        funcPointer fpte5 = &BelowThresholdBalance;
        HigherOrderFunction(bankObjects, fptr3, 6);

        using namespace std::placeholders;

        auto bindF1 = std::bind(&FirstNInstance, bankObjects, 10);
        FirstNInstance(bankObjects, 20);

        auto bindF2 = std::bind(&MinBalanceAtLeast,bankObjects, 6000);
        MinBalanceAtLeast(bankObjects, 600);

        auto bindF3 = std::bind(&BelowThresholdBalance, bankObjects,1000);
        BelowThresholdBalance(bankObjects, 4000);

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}