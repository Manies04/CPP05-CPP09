/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 22:53:41 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/07 22:53:43 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

struct Data
{
	int			id;
	std::string	name;
	double		value;

	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();
};