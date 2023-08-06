#ifndef OVERFLOWEXCEPTION_H
#define OVERFLOWEXCEPTION_H

#include<cstring>

class OverflowException
{
private:
    char message[100];
public:
    OverflowException(const char* p);
    ~OverflowException();
    char* getMessage();
};


#endif // OVERFLOWEXCEPTION_H
