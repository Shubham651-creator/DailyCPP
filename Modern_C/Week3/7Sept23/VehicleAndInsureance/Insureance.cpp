#include "Insureance.h"

std::ostream &operator<<(std::ostream &os, const Insureance &rhs)
{
    os << "insuranceId: " << rhs.insuranceId
       << " insuranceAmount: " << rhs.insuranceAmount
       << " insuranceType: " << DisplayInsuranceType(rhs.insuranceType);
    return os;
}
Insureance::Insureance(std::string id, float amount, InsuranceType type)
    : insuranceId(id), insuranceAmount(amount), insuranceType(type) {}

std::string DisplayInsuranceType(InsuranceType type)
{
    if (type == InsuranceType::ZERO_DEBT)
        return "ZERO_DEBT";
    return "REGULAR";
}