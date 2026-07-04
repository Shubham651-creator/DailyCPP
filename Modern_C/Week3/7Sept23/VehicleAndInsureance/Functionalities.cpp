#include "Functionalities.h"
#include "Car.h"
#include <future>
#include <thread>

std::mutex mt;

using carPointer = std::unique_ptr<Car>;
using carContainer = std::list<carPointer>;
using rawContainerOfInsurance = std::list<Car *>;

using insurancePointer = std::unique_ptr<Insureance>;
using insuranceContainer = std::list<insurancePointer>;

// void CreateObjects(insuranceContainer &insuranceData, carContainer &carData)
// {
//     std::unique_ptr<Insureance> i1 = std::make_unique<Insureance>(
//         "ins101",
//         1000.0f,
//         InsuranceType::ZERO_DEBT);

//     std::unique_ptr<Insureance> i2 = std::make_unique<Insureance>(
//         "ins102",
//         2000.0f,
//         InsuranceType::ZERO_DEBT);

//     std::unique_ptr<Insureance> i3 = std::make_unique<Insureance>(
//         "ins103",
//         3430.0f,
//         InsuranceType::REGULAR);

//     // // async thread
//     // std::future<std::unique_ptr<Insureance>> i4 = std::async(
//     //     std::launch::async,
//     //     std::make_unique<Insureance>,

//     //     "ins104",
//     //     40000.0f,
//     //     InsuranceType::REGULAR);

//     insuranceData.push_back(std::move(i1));
//     insuranceData.push_back(std::move(i2));
//     insuranceData.push_back(std::move(i3));

//     auto itr = insuranceData.begin();

//     // implement unique ptr without maker function
//     Car *c1 = new Car(
//         "c101",
//         2019,
//         VehicleType::PRIVATE,
//         std::ref(*itr++), // take reference from std::list container
//         CarType::SEDAN,
//         890000.0f,
//         "blue");

//     std::unique_ptr<Car> unique_c1(std::move(c1));
//     carData.push_back(std::move(unique_c1));

//     // implemet unique ptr without maker function
//     Car *c2 = new Car(
//         "c102", 2023, VehicleType::COMMERCIAL, std::ref(*itr++),
//         CarType::HATCHBACK,
//         78404440.f,
//         "White");
//     std::unique_ptr<Car> unique_c2(std::move(c2));
//     carData.push_back(std::move(unique_c2));

//     // implemet unique ptr with maker function
//     std::unique_ptr<Car> c3 = std::make_unique<Car>(
//         "c103", 2021, VehicleType::PRIVATE, std::ref(*itr++),
//         CarType::SUV,
//         56744400.0f,
//         "red");
//     carData.push_back(std::move(c3));
// }

// called by each single threads
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
                  std::string cColour)
{

    std::unique_ptr<Insureance> i1 = std::make_unique<Insureance>(
        insId,
        insAmount,
        insType);

    mt.lock();
    insuranceObject.push_back(std::move(i1));

    std::unique_ptr<Car> c3 = std::make_unique<Car>(
        id,
        registration,
        type,
        std::ref(insuranceObject.back()), // back() gives last element of container
        cType,
        cPrice,
        cColour);

    carObject.push_back(std::move(c3));
    mt.unlock();
}

std::optional<rawContainerOfInsurance> CarAboveInsuranceThreshold(
    carContainer &carData, float threshold)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    rawContainerOfInsurance result;

    for (carPointer &value : carData)
    {
        if (value->getVehicleInsurancePlan().get()->getInsuranceAmount() > threshold)
        {
            result.push_back(value.get()); // store raw pointer of unqiue ptr
        }
    }

    if (result.empty())
    {
        return std::nullopt;
    }

    return result;
}

bool CheckCarType(carContainer &carData, CarType type)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    for (carPointer &value : carData)
    {
        if (type != value->getCarType())
        {
            return false;
        }
    }
    return true;
}

void FindLowestHighestInterest(carContainer &carData)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    std::variant<int, std::string> VechialId;
    float max = 0.0f;
    // for (carPointer &value : carData)
    // {
    //     if (max < value.get()->getVehicleInsurancePlan().get()->getInsuranceAmount())
    //     {
    //         max = value.get()->getVehicleInsurancePlan().get()->getInsuranceAmount();
    //         VechialId = value->getVehicleId();
    //     }
    // }

    auto maxItr = std::max_element(
        carData.begin(),
        carData.end(),
        [&](carPointer& obj1, carPointer& obj2){
            return obj1.get()->getVehicleInsurancePlan().get()->getInsuranceAmount() >
            obj2.get()->getVehicleInsurancePlan().get()->getInsuranceAmount();
        }
    );

    // print max interest of vehical id
    std::visit([&](auto &&maxValId)
               { std::cout << "The max vehical interest is " << maxValId << '\n'; },
               maxItr->get()->getVehicleId());

    // float min = max;
    // for (carPointer &value : carData)
    // {
    //     if (min > value.get()->getVehicleInsurancePlan().get()->getInsuranceAmount())
    //     {
    //         min = value.get()->getVehicleInsurancePlan().get()->getInsuranceAmount();
    //         VechialId = value->getVehicleId();
    //     }
    // }

    auto minItr = std::min_element(
        carData.begin(),
        carData.end(),
        [&](carPointer& obj1, carPointer& obj2){
            return obj1.get()->getVehicleInsurancePlan().get()->getInsuranceAmount() <
            obj2.get()->getVehicleInsurancePlan().get()->getInsuranceAmount();
        }
    );
    // print min interest of vehical id
    std::visit([&](auto &&minValId)
               { std::cout << "The min vehical interest is " << minValId << '\n'; },
               minItr->get()->getVehicleId());
}

int CountOfVehicleOnGivenCondition(carContainer &carData,
                                   VehicleType &type, int registrationYear)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    int countOfVehicle = 0;
    for (carPointer &value : carData)
    {
        if (type == value.get()->getVehicleType() &&
            registrationYear == value.get()->getVehicleRegistration())
        {
            countOfVehicle++;
        }
    }
    return countOfVehicle;
}

std::optional<rawContainerOfInsurance> FunctionOfZeroDebt(carContainer &carData,
                                                          VehicleType type, std::string colour)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    rawContainerOfInsurance rawCarObjects;

    for (carPointer &value : carData)
    {
        if (type == value.get()->getVehicleType() && colour == value->getCarColour() && value.get()->getVehicleInsurancePlan().get()->getInsuranceType() == InsuranceType::ZERO_DEBT)
        {
            rawCarObjects.push_back(value.get());
        }
    }

    if (rawCarObjects.empty())
    {
        return std::nullopt;
    }
    return rawCarObjects;
}

std::optional<rawContainerOfInsurance> MeasureTaxFunction(carContainer &carData)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    rawContainerOfInsurance rawCarObjects;

    for (carPointer &value : carData)
    {
        std::cout << "The tax is "
                  << value.get()->getCarPrice() * 0.1 << '\n';
    }

    if (rawCarObjects.empty())
    {
        return std::nullopt;
    }
    return rawCarObjects;
}

std::variant<int, std::string> FunctionOfCarColour(carContainer &carData, std::string colour)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    for (carPointer &value : carData)
    {
        if (colour == value.get()->getCarColour())
        {
            return value.get()->getVehicleId();
        }
    }

    return "NOT matched with any condition\n";
}

float CalculateAvergeCarPrice(carContainer &carData)
{
    // empty input
    if (carData.empty())
    {
        throw std::runtime_error("Car Container is empty\n");
    }

    float sum = std::accumulate(
        carData.begin(),
        carData.end(),
        0.0f,
        [&](int sum , carPointer& obj){
            return sum + obj.get()->getCarPrice();
        }
    );
}
