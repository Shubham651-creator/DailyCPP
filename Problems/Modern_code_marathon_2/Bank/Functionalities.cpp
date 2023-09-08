#include "Functionalities.h"
#include <vector>

// container which stores DebitCard instaneces
using debitCardContainer = std::list<std::shared_ptr<DebitCard>>;

// container which stores account instances
using accountContainer = std::vector<std::shared_ptr<Account>>;

// container which stores Bank instances
using bankContainer = std::list<std::shared_ptr<Bank>>;

// function pointer
using funcPointer = std::function<void(bankContainer &, int)>;

void CreateObjects(bankContainer &dataBank, accountContainer &dataAccount, debitCardContainer &dataDebitCard)
{

    dataAccount.push_back(std::make_shared<Account>("@174673", 500, 4030, std::make_shared<DebitCard>(101, 650961)));
    dataAccount.push_back(std::make_shared<Account>("@274673", 500, 4030, std::make_shared<DebitCard>(102, 250961)));
    dataAccount.push_back(std::make_shared<Account>("@374673", 500, 4030, std::make_shared<DebitCard>(103, 350961)));
    dataAccount.push_back(std::make_shared<Account>("@474673", 500, 4030, std::make_shared<DebitCard>(104, 450961)));
    dataAccount.push_back(std::make_shared<Account>("@574673", 500, 4050, std::make_shared<DebitCard>(105, 550961)));
    dataAccount.push_back(std::make_shared<Account>("@674673", 600, 6030, std::make_shared<DebitCard>(106, 650661)));

    dataBank.push_back(std::make_shared<Bank>("SBI", dataAccount[0]));
    dataBank.push_back(std::make_shared<Bank>("SBI", dataAccount[1]));
    dataBank.push_back(std::make_shared<Bank>("SBI", dataAccount[2]));
    dataBank.push_back(std::make_shared<Bank>("SBI", dataAccount[3]));
    dataBank.push_back(std::make_shared<Bank>("SBI", dataAccount[4]));
    dataBank.push_back(std::make_shared<Bank>("SBI", dataAccount[5]));
}

void HigherOrderFunction(bankContainer &data, funcPointer &fns, int N)
{
    // check whether empty or not
    if (data.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }

    fns(data, N);
}

void FirstNInstance(bankContainer &data, int N)
{
    // check whether empty or not
    if (data.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }
    int count = 0;
    for (auto &value : data)
    {
        if (count > N)
        {
            std::cout << *value << '\n';
        }
    }
}

void MinBalanceAtLeast(bankContainer &data, int N)
{
    // check whether empty or not
    if (data.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }
    for (auto &value : data)
    {
        if (value->accountsData()->minBalanceAmount() > 500 &&
            (value->accountsData()->card()->cvv() == 111 || value->accountsData()->card()->cvv() == 222 || value->accountsData()->card()->cvv() == 333 || value->accountsData()->card()->cvv() == 444 || value->accountsData()->card()->cvv() == 555 || value->accountsData()->card()->cvv() == 777))
        {
            std::cout << "True\n";
        }
        else
        {
            std::cout << "false\n";
        }
    }
}

void BelowThresholdBalance(bankContainer &data, int N)
{
    // check whether empty or not
    if (data.empty())
    {
        throw std::runtime_error("Container is empty\n");
    }
    for (auto &value : data)
    {
        if (value->accountsData()->minBalanceAmount() < N)
        {
            std::cout << *value << '\n';
        }
    }
}
