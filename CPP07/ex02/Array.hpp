#pragma once

#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*_data;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &other);
		Array &operator=(Array const &other);
		~Array(void);

		T				&operator[](unsigned int index);
		T const			&operator[](unsigned int index) const;
		unsigned int	size(void)const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

#include "Array.tpp"