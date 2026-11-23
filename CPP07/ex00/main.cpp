/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:18:09 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/21 20:40:53 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	int a = 2;
	int b = 4;

	::swap(a, b);
	std::cout << "--- int ---" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;


	std::string c = "batata1";
	std::string d = "batata2";

	::swap(c, d);
	std::cout << std::endl << "--- string ---" << std::endl;
	std::cout << "a = " << c << ", b = " << d << std::endl;
	std::cout << "min( a, b ) = " << ::min(c, d) << std::endl;
	std::cout << "max( a, b ) = " << ::max(c, d) << std::endl;

	int	x = 42;
	int	y = 42;

	std::cout << std::endl << "--- iguais ---" << std::endl;
	std::cout << "&x = " << &x << ", &y = " << &y << std::endl;
	std::cout << "&min( x, y ) = " << &::min(x, y) << std::endl;
	std::cout << "&max( x, y ) = " << &::max(x, y) << std::endl;

	return (0);
}