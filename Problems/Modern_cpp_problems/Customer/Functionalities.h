#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include<vector>
#include<list>
#include"Customer.h"

// vector Container which store float
using container = std::vector<float>;

//list container to store Custome objects
using objectContainer = std::vector<Customer *>;

//creating objects
void CreateObjects(objectContainer& object);

// a function to find highest transacction amount and
// returns integer id
int HighestTransactionAmount(objectContainer& object);

//a function to find matching cutomertype and return that objects
objectContainer SearchCustomerType(objectContainer& object, CustomerType type);

//a function whose returns all instance of customer 
//whose 100<= credits <=200
objectContainer SearchCustomerCredits(objectContainer& object);

//a function to find highest and lowest credits and print it
void LowestHighestCredits(objectContainer& object);

//a function to find average of credits whose customer type matches
//and returns average value
float AverageOfTypesCredits(objectContainer& object, CustomerType type);


//deleting objects
void DeleteObjects(objectContainer& object);

#endif // FUNCTIONALITIES_H
