#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; i++)
	{
		Base	*p = generate();

		std::cout << "identify(Base*): ";
		identify(p);
		std::cout << "identify(Base&): ";
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	std::cout << "identify(NULL):  ";
	identify(static_cast<Base *>(NULL));

	Base	plain;
	std::cout << "identify(plain Base*): ";
	identify(&plain);
	std::cout << "identify(plain Base&): ";
	identify(plain);
	return (0);
}
