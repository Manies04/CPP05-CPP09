/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:18:09 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/07 23:18:42 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
 
int	main(void)
{
	Data	data;
 
	data.id = 42;
	data.name = "tiade-al";
	data.value = 4.2;
 
	uintptr_t	raw = Serializer::serialize(&data);
	Data		*back = Serializer::deserialize(raw);
 
	std::cout << "Original address : " << &data << std::endl;
	std::cout << "Serialized (dec) : " << raw << std::endl;
	std::cout << "Serialized (hex) : 0x" << std::hex << raw << std::dec << std::endl;
	std::cout << "Deserialized     : " << back << std::endl;
 
	if (back == &data)
		std::cout << "OK: deserialize(serialize(&data)) == &data" << std::endl;
	else
		std::cout << "KO: pointers are different" << std::endl;
 
	// The struct is still usable through the recovered pointer
	std::cout << "id    = " << back->id << std::endl;
	std::cout << "name  = " << back->name << std::endl;
	std::cout << "value = " << back->value << std::endl;
 
	// Changing it through back changes the original: it's the same object
	back->id = 2026;
	std::cout << "back->id = 2026 -> data.id = " << data.id << std::endl;
	return (0);
}