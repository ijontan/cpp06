#include "Data.hpp"
#include <ostream>

/***********************************
 * Constructors
 ***********************************/

Data::Data(void) : _value(0)
{
}

Data::Data(const Data &src) : _value(src._value)
{
}

Data &Data::operator=(const Data &rhs)
{
	_value = rhs._value;
	return *this;
}

/***********************************
 * Destructors
 ***********************************/

Data::~Data(void)
{
}

void Data::setvalue(int val)
{
	_value = val;
}

int Data::getvalue(void)
{
	return _value;
}

std::ostream &operator<<(std::ostream &os, Data data){

	os << data.getvalue();
	return os;
}
