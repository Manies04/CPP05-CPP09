/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 01:06:39 by tiade-al          #+#    #+#             */
/*   Updated: 2026/11/23 01:06:40 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _data(NULL), _size(0)
{
}
template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (n > 0)
		_data = new T[n]();
}

template <typename T>
Array<T>::Array(Array const &other): _data(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		T	*newData = NULL;

		// Aloca primeiro: se new falhar, o objeto atual fica intacto
		if (other._size > 0)
		{
			newData = new T[other._size]();
			for (unsigned int i = 0; i < other._size; i++)
				newData[i] = other._data[i];
		}
		delete[] _data;
		_data = newData;
		_size = other._size;
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _data;
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
T const	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
const char	*Array<T>::OutOfBoundsException::what(void) const throw()
{
	return ("Array: index out of bounds");
}