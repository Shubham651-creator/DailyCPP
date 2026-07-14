#include "Functionalities.h"

void CreateObjects(ContainerOfFight &container)
{
    std::shared_ptr<Flight> f1 = std::make_shared<Flight>(
        101,
        FlightType::COMMERCIAL,
        "Pune",
        "Delhi",
        2000.0f);

    std::shared_ptr<Flight> f2 = std::make_shared<Flight>(
        102,
        FlightType::PRIVATE,
        "PUne",
        "Sangli",
        435.0f);
    
    std::shared_ptr<Flight> f3 = std::make_shared<Flight>(
        103,
        FlightType::SPECIAL,
        "PUne",
        "Sangli",
        435.0f);
    
    std::shared_ptr<Flight> f4 = std::make_shared<Flight>(
        104,
        FlightType::PRIVATE,
        "PUne",
        "Sangli",
        435.0f);

    std::shared_ptr<Flight> f5 = std::make_shared<Flight>(
        105,
        FlightType::SPECIAL,
        "PUne",
        "Sangli",
        435.0f);

    container.push_back(f1);
    container.push_back(f2);
    container.push_back(f3);
    container.push_back(f4);
    container.push_back(f5);
}

float AverageOfFare(ContainerOfFight &container)
{
    if(container.empty()){
        throw std::runtime_error("Container is empty\n");
    }
    
    float sum=0;
    int count =0;

    for(std::shared_ptr<Flight>& value : container){
        sum += value->fare();
        count++;
    }

    return sum/count;
}

ContainerOfFight FirstNInstance(ContainerOfFight &container, int N)
{
    if(container.empty()){
        throw std::runtime_error("Container is empty\n");
    }

    ContainerOfFight result;
    int count = N;

    while(count > 0){
        result.push_back(container[N - count]);
        count --;
    }

    return result;

}

int MinimumFare(ContainerOfFight &container)
{
    if(container.empty()){
        throw std::runtime_error("Container is empty\n");
    }
    
    float max = 0;
    for(std::shared_ptr<Flight>& value : container){
        if(max < value->fare()){
            max = value->fare();
        }
    }

    float min = max;
    int id;
    for(std::shared_ptr<Flight>& value : container){
        if(min > value->fare()){
            min = value->fare();
            id = value->id();
        }
    }

    return id;
}
