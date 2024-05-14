#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include "Base.hpp"
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void)
{
	int randint = rand() % 3;

	switch (randint)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << 'C' << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << 'A' << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << 'B' << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << 'C' << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	Base *p;
	srand(time(NULL));
	p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);
}
