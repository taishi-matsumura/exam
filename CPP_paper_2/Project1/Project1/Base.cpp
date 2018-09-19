#include "Base.h"
#include "Sample1.h"
#include <iostream>

Base::Base()
{
	std::cout << "Base::Base()" << std::endl;
	m_pSample1 = new Sample1();
}

Base::~Base()
{
	std::cout << "Base::~Base()" << std::endl;
	delete m_pSample1;
}

void Base::Func2()
{
	m_pSample1->Func();
}
