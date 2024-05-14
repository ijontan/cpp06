#pragma once

#include <ostream>

class Data
{
public:
	Data(void);
	~Data(void);
	Data(const Data &src);
	Data &operator=(const Data &rhs);
	void setvalue(int val);
	int getvalue(void);

private:
	int _value;
};

std::ostream &operator<<(std::ostream &os, Data data);
