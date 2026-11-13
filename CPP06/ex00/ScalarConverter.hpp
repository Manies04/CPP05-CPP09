#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <cctype>
#include <cerrno>
#include <cmath>

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();
};