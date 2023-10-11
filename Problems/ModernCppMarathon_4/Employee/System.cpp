#include "System.h"

std::ostream &operator<<(std::ostream &os, const System &rhs)
{
    os << "_memory: " << DisplayMemoryType(rhs._memory)
       << " _disk_space: " << rhs._disk_space
       << " _allocation_number: " << rhs._allocation_number;
    return os;
}

std::string DisplayMemoryType(MemoryType type)
{
    if (type == MemoryType::_8GB)
    {
        return "_8GB";
    }
    if (type == MemoryType::_16GB)
    {
        return "_16GB";
    }
    return "_32GB";
}

System::System(MemoryType memory, float space, std::string allocation)
    : _memory(memory), _disk_space(space), _allocation_number(allocation)
{
}
