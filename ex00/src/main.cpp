#include "ScalarConvertor.hpp"
#include <iostream>
#include <string>
// TODO: add .0 and f behind double and float
int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	std::string ltr(av[1]);
	ScalarConvertor::convert(ltr);

	ScalarConvertor a;
	return 0;
}
