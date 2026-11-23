/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:18:09 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/22 00:03:25 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	print(T const &x)
{
	std::cout << x << " ";
}

template <typename T>
void	increment(T &x)
{
	x++;
}

int	main(void)
{
	int			ints[] = {0, 1, 2};
	const int	cints[] = {10, 20, 30};
	double		doubles[] = {1.5, 2.5, 3.5};
	std::string	strs[] = {"ola", "42"};

	::iter(ints, 3, increment<int>);
	::iter(ints, 3, print<int>);			std::cout << std::endl;
	
	::iter(cints, 3, print<int>);			std::cout << std::endl;
	// ::iter(cints, 3, increment<int>);   // não compila: não se pode alterar um array const
	
	::iter(doubles, 3, increment<double>);
	::iter(doubles, 3, print<double>);		std::cout << std::endl;
	
	::iter(strs, 2, print<std::string>);	std::cout << std::endl;

	return (0);
}