

#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <list>
#include <memory>
#include "CabBooking.h"
#include "OnlinePaymentCabBooking.h"
#include "CashPaymentCabBooking.h"

// list container which holds objects of onlinePayment
// and cashPayment
using container = std::list<std::shared_ptr<CabBooking>>;

// create a objects of cashPayment and onlinePayment
void CreateObjects(container &objects);

// a function to find and return container of fare whose
// pickup location matches
container ConditionPickupLocation(container &objects, std::string location);

// return booking id whose fare is highest
std::string MaxCabFareCalculation(container &objects);

// return container of first N instance
container FirstNInstance(container &objects, int N);

// return float avergae value whose fare of onlinePayment
float AverageOfOnlinePayment(container &objects);

#endif // FUNCTIONALITIES_H
