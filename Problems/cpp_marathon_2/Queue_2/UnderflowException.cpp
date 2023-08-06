#include "UnderflowException.h"

UnderflowException::UnderflowException(const char *p)
{
    strcpy(message, p);
}

UnderflowException::~UnderflowException()
{
}
char *UnderflowException::getMessage()
{
    return message;
}
