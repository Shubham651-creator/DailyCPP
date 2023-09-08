#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <list>
#include<functional>
#include <memory>
#include "Device.h"

// list container which stores Device objects
using Container = std::list<std::shared_ptr<Device>>;

//functional pointer 
using Pointer = std::function<void(Container&)>;

// create object of 5 instances
void CreateObjects(Container &data) noexcept;

// a function which accepts container of instances
// and a function that accept a one instance , return void
void ShowResults(Container& data, Pointer fn);

// a function which accepts sigle instance, return void
void FindDiscountPrice(Container& data);

// a function which accepts sigle instance, return void
void FindTaxAmount(Container& data);

#endif // FUNCTIONALITIES_H
