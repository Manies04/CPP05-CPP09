/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 00:38:25 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/20 00:38:26 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm (const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return(*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return(_target);
}

void	ShrubberyCreationForm::executeAction() const
{
	std::string		filename = _target + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw FileOpenException();
	file << "       /\\         /\\" << std::endl;
	file << "      /**\\       /**\\" << std::endl;
	file << "     /****\\     /****\\" << std::endl;
	file << "    /******\\   /******\\" << std::endl;
	file << "   /********\\ /********\\" << std::endl;
	file << "       ||         ||" << std::endl;
	file << "       ||         ||" << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return ("Unable to create the shrubbery file");
}