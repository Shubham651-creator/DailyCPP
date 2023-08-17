#include "Functionalities.h"
#include "Car.h"
#include "CarType.h"

void CreateObjects(Container &data)
{
    /*
        emplace_back - it required all parameter to call parameterized constructor.

        emplace_back you will get return object ,not pointer.
    */

    data.emplace_back("001", "first", CarType::HATCHBACK, 2000, 30);
    data.emplace_back("002", "dzire", CarType::SEDAN, 95000, 20);
    data.emplace_back("003", "third", CarType::SUV, 58000, 60);
    data.emplace_back("004", "fourth", CarType::HATCHBACK, 790000, 80);
    data.emplace_back("005", "fifth", CarType::SUV, 790000, 90);
}

/*
    function calculate total price of all cars and returns the average
    by dividing  total by size of input list
*/

float AveragePrice(Container &data)
{
    float sum = 0;

    for (Car value : data)
    {
        sum += value.price();
    }

    return sum / data.size();
}

/*
    create 2 variables, one for tracking price and second to store model as strings,
    if price of current vehicle > highest price, then delete it.

    when in the for loop, following cases can be seen

    1) price of current vechicle < previous highPrice
        --------> no operation required
    2) price of current vehicle > previous high price
        -------> delete previous entry in the list, replace hightPrice
            and add new model to ModelNames.
    3) price of current vehicle is same as previous hight Price
        (new vehicle is also of same price)
        ----> add new model to modelNames list

*/
void ModelNameHightestPrice(Container &data)
{
    float highPrice = data.front().price(); // returns first price item inside list
    std::list<std::string> modelNames;

    for (Car value : data)
    {
        if (value.price() > highPrice)
        {
            // case 2
            highPrice = value.price();

            // delete the previous names
            modelNames.erase(modelNames.begin(), modelNames.end());
            // add new highprice car model
            // modelNames.push_back(value.model());
        }
        if (value.price() == highPrice)
        {
            modelNames.push_back(value.model());
        }
    }

    for (std::string name : modelNames)
    {
        std::cout << "model Name : " << name << "\n";
    }
}

Container CarsAboveThreshold(Container &data, float threshold)
{
    Container result;
    for (Car car : data)
    {
        if (threshold < car.price())
        {
            result.push_back(car);
        }
    }
    return result;
}
