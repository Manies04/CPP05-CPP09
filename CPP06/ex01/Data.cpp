/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 22:53:32 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/07 22:53:34 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : id(0), name(""), value(0.0)
{
}
 
Data::Data(const Data &other) : id(other.id), name(other.name), value(other.value)
{
}
 
Data	&Data::operator=(const Data &other)
{
	if (this != &other)
	{
		id = other.id;
		name = other.name;
		value = other.value;
	}
	return (*this);
}
 
Data::~Data()
{
}