#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <list>
#include <functional>
#include "Vehicle.h"
#include "Car.h"
#include "Insureance.h"
#include<algorithm>
#include<numeric>

using carPointer = std::unique_ptr<Car>;
using carContainer = std::list<carPointer>;

using insurancePointer = std::unique_ptr<Insureance>;
using insuranceContainer = std::list<insurancePointer>;

using rawContainerOfInsurance = std::list<Car *>;

/*
    A function to create insurance objects and car objects.

    Design the function in such a way that we create only one
    object each time the function is called.

    This function must be executed in seperate thread in each call
    such that one thread only create and pushes one object
    into the container.
*/
void CreateObjects(insuranceContainer &insuranceData, carContainer &carData);

void CreateObject(insuranceContainer &insuranceObject,
                  carContainer &carObject,
                  std::string insId,
                  float insAmount,
                  InsuranceType insType,
                  std::variant<int, std::string> id,
                  int registration,
                  VehicleType type,
                  CarType cType,
                  float cPrice,
                  std::string cColour);

/*
    A function to return Container of cars above threshold
*/
std::optional<rawContainerOfInsurance> CarAboveInsuranceThreshold(carContainer &carData, float);

/*
    1. A function that check all car instances are matched with
    second arg CarType.
*/
bool CheckCarType(carContainer &carData, CarType type);

/*
    2. A function to find lowest and highest InterestAmount
     and print vehcial id !
*/
void FindLowestHighestInterest(carContainer &carData);

/*
    3. A function return count of car whose matches with args
    vehicletype and vehicleRegistration year.
*/
int CountOfVehicleOnGivenCondition(carContainer &carData,
                                   VehicleType &type, int registrationYear);

/*
    4. A function whose return container of car whose matches
        - instanceType is zero debt
        - vehicle type as second arg
        - carColour as last arg
*/
std::optional<rawContainerOfInsurance> FunctionOfZeroDebt(carContainer &carData,
                                                          VehicleType type, std::string colour);

/*
    5. A function that return car container with contains tax.
    a tax should be 10% of car price.
*/
std::optional<rawContainerOfInsurance> MeasureTaxFunction(carContainer &carData);

/*
    6. A function who return vehicle id whose matched with
    car colour as arg.
*/
std::variant<int, std::string> FunctionOfCarColour(carContainer &carData,
                                                   std::string colour);

/*
    7. A function that calculate average of all car price instances.
*/
float CalculateAvergeCarPrice(carContainer &carData);

template <typename... Args>
float FindTotalPrice(Args&... carObject) //right to left assoication
{
    
    return (carObject.get()->getCarPrice() + ...);
}

#endif // FUNCTIONALITIES_H
