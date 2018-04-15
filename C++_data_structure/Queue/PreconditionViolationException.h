#ifndef _PRECONDITIONVIOLATIONEXCEPTION_H_
#define _PRECONDITIONVIOLATIONEXCEPTION_H_
#include<stdexcept>

class PreconditionViolationException: public std::runtime_error
{
public:
  PreconditionViolationException(const char* message);
};

#endif
