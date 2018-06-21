#include "Derived.h"

#include <iostream>

int main()
{
#if 0
    Base* pBases = new Derived[5];

//	pBases[1].Func1();

	delete[] pBases;
#else
	Base* pBase = new Derived();
	pBase->Func1();
	delete pBase;
#endif
	while(1);
	return 0;
}
