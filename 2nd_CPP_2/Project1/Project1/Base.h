#ifndef BASE_H
#define BASE_H

class Sample1;

class Base
{
public:
    Base();
    virtual ~Base();
	inline void Func1() { Func2(); }

private:
    virtual void Func2();
	Sample1* m_pSample1;
};

#endif // BASE_H
