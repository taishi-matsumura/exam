#include "Derived.h"
#include "Sample2.h"
#include <iostream>

Derived::Derived()
{
	std::cout << "Derived::Derived()" << std::endl;
}

Derived::~Derived()
{
	std::cout << "Derived::~Derived()" << std::endl;
	delete m_pSample2;
}

void Derived::Func2()
{
	m_pSample2 = new Sample2();
	m_pSample2->Func();
	delete m_pSample2;
	m_pSample2 = NULL;
}
