#include "OverflowException.h"

OverflowException::OverflowException(const char *p)
{
    strcpy(message, p);
}

OverflowException::~OverflowException()
{
}

char *OverflowException::getMessage()
{
    return message;
}
