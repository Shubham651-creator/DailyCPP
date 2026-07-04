#include "Functionalities.h"
#include "Customer.h"
#include "list"

// vector Container which store float
using container = std::vector<float>;

// // list container to store Custome objects
// using objectContainer = std::vector<Customer *>;

void CreateObjects(objectContainer &object)
{
    Customer *one = new Customer(
        101,
        "Shubham",
        CustomerType::PREMIUM,
        {101.0f, 23.0f, 802.0f},
        20.0f);

    Customer *two = new Customer(
        102,
        "Shreya",
        CustomerType::REGULAR,
        {201.0f, 63.0f, 202.0f},
        140.0f);

    Customer *three = new Customer(
        103,
        "Anita",
        CustomerType::REGULAR,
        {201.0f, 433.0f, 202.0f},
        343.0f);

    object.push_back(one);
    object.push_back(two);
    object.push_back(three);
}

int HighestTransactionAmount(objectContainer &object)
{
    //check container empty or not
    if(object.empty()){
        std::runtime_error("Container is empty\n");
    }

    float high = 0;
    int customerId;
    for(Customer* customer : object){
        float sum =0;
        for(float value : customer->getCustomerTransactionAmounts()){
            sum += value;
        }
        if(sum > high) {
            high = sum;
            customerId = customer->getCustomerId();
        }
    }

    return customerId;
}

objectContainer SearchCustomerType(objectContainer &object, CustomerType type)
{
    //check container empty or not
    if(object.empty()){
        std::runtime_error("Container is empty\n");
    }

    objectContainer store;
    for(Customer* customer : object){
        if(type == customer->getCustomerType()){
            store.push_back(customer);
        }
    }
    return store;
}

objectContainer SearchCustomerCredits(objectContainer &object)
{
    //check container empty or not
    if(object.empty()){
        std::runtime_error("Container is empty\n");
    }

    objectContainer store;
    for(Customer* customer: object){
        if(100 <= customer->getCustomerStoreCredits() && customer->getCustomerStoreCredits() <= 200){
            store.push_back(customer);
        }
    }

    return store;
}

void LowestHighestCredits(objectContainer &object)
{
    //check container empty or not
    if(object.empty()){
        std::runtime_error("Container is empty\n");
    }

    float lowCredits =0 , highCredits = 0;
    //check highest credits
    for(Customer* customer : object){

        if(highCredits < customer->getCustomerStoreCredits()){
            highCredits = customer->getCustomerStoreCredits();
        }
    }

    //set initial low as high for further calculations
    lowCredits = highCredits;
    //check lowest credits
    for(Customer* customer: object){
        if(lowCredits > customer->getCustomerStoreCredits()){
            lowCredits = customer->getCustomerStoreCredits();
        }
    }

    std::cout<<"The lowest and highest credit of customer are "
    <<lowCredits <<" and "<< highCredits <<" repectively \n";
}

float AverageOfTypesCredits(objectContainer &object, CustomerType type)
{
    //check container empty or not
    if(object.empty()){
        std::runtime_error("Container is empty\n");
    }

    float sum = 0;
    int count = 0;
    for(Customer* customer : object){
        if(type == customer->getCustomerType()){
            sum += customer->getCustomerStoreCredits();
            count++;
        }
    }

    return sum /count;
}

void DeleteObjects(objectContainer &object)
{
    //delete objects one by one
    for (Customer *customer : object)
    {
        delete customer;
    }
}
