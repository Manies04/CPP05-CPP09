/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 00:38:57 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/20 00:38:58 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

AForm	*Intern::createShrubbery(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}
AForm	*Intern::createRobotomy(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}
AForm	*Intern::createPardon(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

Intern::Intern()
{
}
Intern::Intern(const Intern &other)
{
	(void)other;
}
Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}
Intern::~Intern()
{
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target) const
{
	typedef AForm *(Intern::*FormCreator)(const std::string &) const;
 
	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	const FormCreator	creators[3] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};
 
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	std::cout << "Intern couldn't create \"" << formName
		<< "\": this form does not exist." << std::endl;
	return (NULL);
}