#ifndef FUNCTIONALITES_H
#define FUNCTIONALITES_H

#include <iostream>
#include <list>
#include <memory>
#include "TouristVehicle.h"
#include "PermitType.h"
#include "Permit.h"

// list container which stores tourist objects
using touristVehicleContainer = std::list<std::shared_ptr<TouristVehicle>>;

// create a objects of Tourist vechicles
void CreateObjectsOfTourist(touristVehicleContainer &touristObject) noexcept;

// a function to find and return touristContainer which
//  seat count >= 4 and permit type is lease
touristVehicleContainer ConditionSeatCountAndPermitType(touristVehicleContainer &touristObject);

// a function to return averge of booking charge value whose tourist vechicle
// type is CAB.
float AvergeOfTypeCAB(touristVehicleContainer &touristObject);

// a function to return Permit object whose booking charge
// is maximum.
std::string BookingChargeIsMaximum(touristVehicleContainer &touristObject);

// a function to return first N instance of tourist vehicle
touristVehicleContainer FirstNInstance(touristVehicleContainer &touristObject, int N);

#endif // FUNCTIONALITES_H
