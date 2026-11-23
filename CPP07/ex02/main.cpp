/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 01:06:21 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/23 01:06:22 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int	main(void)
{
	Array<int>			empty;
	Array<int>			ints(3);
	Array<std::string>	strs(2);

	std::cout << "empty.size() = " << empty.size() << std::endl;
	std::cout << "ints(3)      = " << ints[0] << " " << ints[1] << " " << ints[2] << std::endl;

	strs[0] = "ola";
	Array<std::string>	copy(strs);
	Array<std::string>	assigned;
	assigned = strs;
	strs[0] = "mudou";
	std::cout << "strs[0] = " << strs[0] << ", copy[0] = " << copy[0]
		<< ", assigned[0] = " << assigned[0] << std::endl;

	Array<int> const	constInts(ints);
	std::cout << "constInts[0] = " << constInts[0] << std::endl;
	// constInts[0] = 1;	// nao compila: instancia const

	try { std::cout << ints[3] << std::endl; }
	catch (std::exception const &e) { std::cout << "ints[3]: " << e.what() << std::endl; }
	return (0);
}