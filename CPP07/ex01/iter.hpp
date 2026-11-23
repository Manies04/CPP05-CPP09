#pragma once

#include <cstddef>

template <typename T, typename F>
void	iter(T *array, size_t const lenght, F func)
{
	if (!array)
		return ;
	for (size_t i = 0; i < lenght; i++)
		func(array[i]);
}