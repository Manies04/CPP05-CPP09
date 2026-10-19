/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:20:26 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/19 17:11:09 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

static void	title(const std::string &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

int	main()
{
	std::srand(std::time(NULL));

	Bureaucrat	boss("Boss", 1);
	Bureaucrat	middle("Middle", 70);
	Bureaucrat	intern("Intern", 150);

	title("Shrubbery (sign 145, exec 137)");
	{
		ShrubberyCreationForm	shrub("home");

		std::cout << shrub << std::endl;
		intern.executeForm(shrub);      // not signed yet
		intern.signForm(shrub);         // 150 > 145: fails
		middle.signForm(shrub);
		intern.executeForm(shrub);      // 150 > 137: fails
		middle.executeForm(shrub);      // creates home_shrubbery
	}

	title("Robotomy (sign 72, exec 45)");
	{
		RobotomyRequestForm	robot("Bender");

		middle.signForm(robot);
		middle.executeForm(robot);      // 70 > 45: fails
		for (int i = 0; i < 4; i++)
			boss.executeForm(robot);    // about 50% success
	}

	title("Presidential pardon (sign 25, exec 5)");
	{
		PresidentialPardonForm	pardon("Arthur Dent");

		middle.signForm(pardon);        // 70 > 25: fails
		boss.executeForm(pardon);       // not signed
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}

	title("Using forms through an AForm pointer");
	{
		AForm	*forms[3];

		forms[0] = new ShrubberyCreationForm("garden");
		forms[1] = new RobotomyRequestForm("Marvin");
		forms[2] = new PresidentialPardonForm("Ford Prefect");
		for (int i = 0; i < 3; i++)
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}

	title("Copy keeps target and signed status");
	{
		PresidentialPardonForm	original("Trillian");

		boss.signForm(original);
		PresidentialPardonForm	copy(original);
		std::cout << copy << std::endl;
		boss.executeForm(copy);
	}
	return (0);
}