#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include<numeric>
#include <memory>
#include "DataRecord.h"
#include "DataUnit.h"

// container which stores DataRecore instance
using dataRecordContainer = std::vector<std::shared_ptr<DataRecord>>;

// container which stores DateUnit instances
using dataUnitContainer = std::vector<std::shared_ptr<DataUnit>>;

// function pointer
using funcPointer = std::function<void(dataRecordContainer &)>;

// create a 5 objects
void CreateObjects(dataRecordContainer &dataRecord, dataUnitContainer &dataUnit);

// a higher order function which accpets container and function wrapper
void HigherOrderFunction(dataRecordContainer &data, funcPointer &fns);

// 2. a function which accepts container and print it
void SumOfDataProvided(dataRecordContainer &data);

// 3. a function which accepts container and print it
void MaxUnitId(dataRecordContainer &data);

// 4. a function which accepts container and print it
void PrintInstanceForINHOUSE(dataRecordContainer &data);

// 5. a function which accepts container and print it
void PrintOddInstances(dataRecordContainer &data);

#endif // FUNCTIONALITIES_H
