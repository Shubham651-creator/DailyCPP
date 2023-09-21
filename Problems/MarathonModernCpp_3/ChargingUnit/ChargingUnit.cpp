#include "ChargingUnit.h"

ChargingUnit::ChargingUnit(std::string id, float rating, variantVariable lastUnits,
                           float capacity, float costKw)
    : _id(id), _rating_kw(rating), _last_5_discharged_units(lastUnits),
      _capacity(capacity), _cost_per_kw(costKw)
{
    float total = 0;
    std::visit([&](auto &&sum)
               {
                   
                    for(auto& i : sum){
                        total = total + i ;
                    } },
               last5DischargedUnits());

    if (total > capacity)
    {
        throw std::runtime_error("EXception\n");
    }
}

std::ostream &operator<<(std::ostream &os, const ChargingUnit &rhs)
{
    os << "_id: " << rhs._id
       << " _rating_kw: " << rhs._rating_kw
       << " _last_5_discharged_units: ";

    // print variant
    std::visit(
        [&](auto &&val)
        {
        for(float value : val){
            os << value <<"\t";
        } },
        rhs._last_5_discharged_units);

    os << " _capacity: " << rhs._capacity
       << " _cost_per_kw: " << rhs._cost_per_kw;

    return os;
}
