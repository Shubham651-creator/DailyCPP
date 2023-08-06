#ifndef UNDERFLOWEXCEPTION_H
#define UNDERFLOWEXCEPTION_H

#include <cstring>

class UnderflowException
{
private:
    char message[100];

public:
    UnderflowException(const char *p);
    ~UnderflowException();
    char *getMessage();
};

#endif // UNDERFLOWEXCEPTION_H
