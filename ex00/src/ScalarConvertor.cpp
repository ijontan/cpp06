#include "ScalarConvertor.hpp"
#include <cctype>
#include <cstddef>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T>
static T stonum(string ltr)
{
	std::stringstream ss(ltr);
	T ret;

	ss >> ret;
	return ret;
}

typedef enum
{
	ERROR,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOF,
	PSEUDOD,
} t_numType;

static t_numType isNum(string ltr)
{
	static const string plusminus("+-");
	bool found_comma = false;
	if (plusminus.find(ltr.at(0)) == string::npos && !isdigit(ltr.at(0)))
		return ERROR;
	for (size_t i = 1; i < ltr.length() - 1; i++)
	{
		char c = ltr.at(i);
		if (c == '.')
		{
			if (found_comma)
				return ERROR;
			found_comma = true;
			continue;
		}
		if (!isdigit(c))
			return ERROR;
	}
	char last_c = ltr.at(ltr.length() - 1);
	if (isdigit(last_c))
	{
		if (found_comma)
			return DOUBLE;
		return INT;
	}
	if (last_c == 'f')
		return FLOAT;
	return ERROR;
}

static t_numType getType(string ltr)
{
	if (ltr.length() == 1 && ltr.at(0) > std::numeric_limits<char>::min() &&
		ltr.at(0) < std::numeric_limits<char>::max() && !isdigit(ltr.at(0)))
		return CHAR;
	if (ltr == "+inf" || ltr == "-inf" || ltr == "nan")
		return PSEUDOD;
	if (ltr == "+inff" || ltr == "-inff" || ltr == "nanf")
		return PSEUDOF;
	return isNum(ltr);
}

static void printIfChar(char val)
{
	cout << "char: " << val << "\nint: " << static_cast<int>(val)
		 << "\nfloat: " << static_cast<float>(val)
		 << "\ndouble: " << static_cast<double>(val) << endl;
}

static void printIfInt(int val)
{
	if (isprint(val))
		cout << "char: " << static_cast<char>(val);
	else
		cout << "char: not displayable";
	cout << "\nint: " << val << "\nfloat: " << static_cast<float>(val)
		 << "\ndouble: " << static_cast<double>(val) << endl;
}

static void printIfFloat(float val)
{
	if (isprint(val))
		cout << "char: " << static_cast<char>(val);
	else
		cout << "char: not displayable";
	cout << "\nint: " << static_cast<int>(val) << "\nfloat: " << val
		 << "\ndouble: " << static_cast<double>(val) << endl;
}

static void printIfDouble(double val)
{
	if (isprint(val))
		cout << "char: " << static_cast<char>(val);
	else
		cout << "char: not displayable";
	cout << "\nint: " << static_cast<int>(val)
		 << "\nfloat: " << static_cast<float>(val) << "\ndouble: " << val
		 << endl;
}

static void printIfPseudo(string ltr, t_numType type)
{
	cout << "char: not in range\nint: not in range\n";
	if (type == PSEUDOF)
	{
		cout << "\nfloat: " << ltr
			 << "\ndouble: " << ltr.substr(0, ltr.length() - 1) << endl;
	}
	else if (type == PSEUDOD)
		cout << "\nfloat: " << ltr << "f\ndouble: " << ltr << endl;
}

void ScalarConvertor::convert(string ltr)
{
	switch (getType(ltr))
	{
	case CHAR:
		printIfChar(ltr.at(0));
		break;
	case INT:
		printIfInt(stonum<int>(ltr));
		break;
	case FLOAT:
		printIfFloat(stonum<float>(ltr));
		break;
	case DOUBLE:
		printIfDouble(stonum<double>(ltr));
		break;
	case PSEUDOF:
		printIfPseudo(ltr, PSEUDOF);
		break;
	case PSEUDOD:
		printIfPseudo(ltr, PSEUDOD);
		break;
	default:
		std::cerr << "error: invalid input" << endl;
	}
}
