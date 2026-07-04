#include <iostream>
#include <functional>
#include <memory>
#include <algorithm>
#include <numeric>
#include <vector>
#include "Functionalities.h"
#include "DataRecord.h"
#include "DataUnit.h"

// container which stores DataRecore instance
using dataRecordContainer = std::vector<std::shared_ptr<DataRecord>>;

// container which stores DateUnit instances
using dataUnitContainer = std::vector<std::shared_ptr<DataUnit>>;

// function pointer
using funcPointer = std::function<void(dataRecordContainer &)>;

int main()
{
    dataUnitContainer unitObjects;
    dataRecordContainer recordObjects;

    try
    {
        CreateObjects(recordObjects, unitObjects);

        funcPointer f2 = &SumOfDataProvided;
        HigherOrderFunction(recordObjects, f2);

        funcPointer f3 = &MaxUnitId;
        HigherOrderFunction(recordObjects, f3);

        funcPointer f4 = &PrintInstanceForINHOUSE;
        HigherOrderFunction(recordObjects, f4);

        funcPointer f5 = &PrintOddInstances;
        HigherOrderFunction(recordObjects, f5);

        // lambda functions
        funcPointer fptr = [](dataRecordContainer &data)
        {
            int sum = 0;
            for (auto value : data)
            {
                sum += value->dataUnit().get()->unitReading();
            }
            std::cout << "The averge is " << sum / data.size() << '\n';
        };
        HigherOrderFunction(recordObjects, fptr);

        funcPointer fptr2 = [](dataRecordContainer &data)
        {
            int min = INT16_MAX;
            for (auto &value : data)
            {
                if (min > value->dataUnit().get()->unitReading())
                {
                    min = value->dataUnit().get()->unitReading();
                }
            }
            std::cout << "The min is " << min << '\n';
        };
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}