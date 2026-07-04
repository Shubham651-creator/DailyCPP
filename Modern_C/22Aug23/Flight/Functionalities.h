#include"Flight.h"
#include"FlightType.h"
#include<memory>
#include<iostream>
#include<vector>

//vector of container which holds object of Flight
using ContainerOfFight = std::vector<std::shared_ptr<Flight>>;

//create a objects
void CreateObjects(ContainerOfFight& container);

//a function to find to average of all fare
float AverageOfFare(ContainerOfFight& container);

//a function to find the first N instance of flights from a container
ContainerOfFight FirstNInstance(ContainerOfFight& container, int N);

//a function to find the _id of the flight with the minimum _fare
int MinimumFare(ContainerOfFight& container);