/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:18:22 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/13 14:19:20 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

//////////////////////////////////////////////////////////////////////

static const double	INF = std::numeric_limits<double>::infinity();

static void	printNumber(double d, int digits, const char *suffix)
{
	if (d != d)
		std::cout << "nan";
	else if (std::fabs(d) == INF)
		std::cout << (d > 0 ? "+inf" : "-inf");
	else if (d == std::floor(d) && std::fabs(d) < 1e16)
		std::cout << std::fixed << std::setprecision(1) << d;
	else
	{
		std::cout.unsetf(std::ios::fixed);
		std::cout << std::setprecision(digits) << d;
	}
	std::cout << suffix << std::endl;
}

static void	printAll(double d, int digits)
{
	std::cout << "char: ";
	if (d != d || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

	std::cout << "int: ";
	if (d != d || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (std::fabs(d) > FLT_MAX && std::fabs(d) != INF)
		std::cout << "impossible" << std::endl;
	else
		printNumber(static_cast<float>(d), FLT_DIG, "f");

	std::cout << "double: ";
	printNumber(d, digits, "");
}

static void	printImpossible()
{
	std::cout << "char: impossible\nint: impossible\n"
		<< "float: impossible\ndouble: impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string &s)
{
	// 1. char: 'a' (with quotes) or a single character that is not a digit
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return (printAll(s[1], DBL_DIG));
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return (printAll(s[0], DBL_DIG));

	// 2. number: let strtod read it, then look at what is left after the number
	bool	pseudo = (s == "nan" || s == "+inf" || s == "-inf"
					|| s == "nanf" || s == "+inff" || s == "-inff");
	bool	decimal = !s.empty() && s.find_first_not_of("+-.0123456789f") == std::string::npos;
	bool	hasDot = s.find('.') != std::string::npos;
	char	*end;

	errno = 0;
	double		d = std::strtod(s.c_str(), &end);
	std::string	rest(end);

	if ((!pseudo && !decimal) || end == s.c_str() || errno == ERANGE)
		return (printImpossible());
	if (rest == "f" && (hasDot || pseudo))                 // float: 4.2f, nanf
	{
		if (std::fabs(d) > FLT_MAX && std::fabs(d) != INF)
			return (printImpossible());
		return (printAll(static_cast<float>(d), FLT_DIG));
	}
	if (!rest.empty())                                      // 42f, 4.2.2 ...
		return (printImpossible());
	if (!hasDot && !pseudo && d >= INT_MIN && d <= INT_MAX) // int: 42
		return (printAll(static_cast<int>(d), DBL_DIG));
	printAll(d, DBL_DIG);                                   // double: 4.2, nan, too big int
}