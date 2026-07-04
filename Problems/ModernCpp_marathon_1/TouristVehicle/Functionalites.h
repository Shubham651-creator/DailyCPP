#ifndef FUNCTIONALITES_H
#define FUNCTIONALITES_H

#include <iostream>
#include <list>
#include <vector>
#include <memory>
#include <functional>
#include "TouristVehicle.h"
#include "PermitType.h"
#include "Permit.h"

// reference wrapper around shared ptr of Permit class
using permitContainer = std::vector<std::shared_ptr<Permit>>;

// list container which stores tourist objects
using touristVehicleContainer = std::list<std::shared_ptr<TouristVehicle>>;
using funPointer = std::function<touristVehicleContainer(touristVehicleContainer &, int)>;

touristVehicleContainer Operation(touristVehicleContainer &touristObject, funPointer &fn);

// create a objects of Tourist vechicles
void CreateObjectsOfTourist(touristVehicleContainer &touristObject, permitContainer &) noexcept;

// a function to find and return touristContainer which
//  seat count >= 4 and permit type is lease
touristVehicleContainer ConditionSeatCountAndPermitType(touristVehicleContainer &touristObject, int seats);

// a function to return averge of booking charge value whose tourist vechicle
// type is CAB.
float AvergeOfTypeCAB(touristVehicleContainer &touristObject);

// a function to return Permit object whose booking charge
// is maximum.
std::string BookingChargeIsMaximum(touristVehicleContainer &touristObject);

// a function to return first N instance of tourist vehicle
touristVehicleContainer FirstNInstance(touristVehicleContainer &touristObject, int N);

#endif // FUNCTIONALITES_H
