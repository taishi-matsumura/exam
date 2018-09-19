#ifndef DERIVED_H
#define DERIVED_H

#include "Base.h"

class Sample2;

class Derived : public Base
{
public:
    Derived();
    virtual ~Derived();

private:
	Sample2* m_pSample2;
    virtual void Func2();
};

#endif // DERIVED_H
