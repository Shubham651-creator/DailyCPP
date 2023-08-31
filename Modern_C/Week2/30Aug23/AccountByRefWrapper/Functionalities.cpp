#include "Functionalities.h"

void Operation(CustomerContainer &data, std::function<void(CustomerContainer &)> fn)
{
    fn(data);
}

void CreateObjects(CustomerContainer &data, AccountContainer &accountData)
{
    std::shared_ptr<Account> a1 = std::make_shared<Account>(101, "shubham", AccountType::BASIC);
    std::shared_ptr<Account> a2 = std::make_shared<Account>(102, "hubham", AccountType::PREMIUM);
    std::shared_ptr<Account> a3 = std::make_shared<Account>(103, "ubhamd", AccountType::BASIC);

    accountData.push_back(a1);
    accountData.push_back(a2);
    accountData.push_back(a3);

    data.push_back(std::make_shared<Customer>(std::ref(accountData[0]), "Omaker", 29));
    data.push_back(std::make_shared<Customer>(std::ref(accountData[1]), "shweta", 32));
    data.push_back(std::make_shared<Customer>(std::ref(accountData[2]), "Anita", 43));
}
