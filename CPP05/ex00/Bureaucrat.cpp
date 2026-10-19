/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:20:16 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/19 23:23:26 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(_lowestGrade)
{
}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < _highestGrade)
		throw GradeTooHighException();
	if (grade > _lowestGrade)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) //only copies grade cause _name is const and can only be set in an initialization list
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}
Bureaucrat::~Bureaucrat()
{
}

const std::string	&Bureaucrat::getName()const
{
	return(_name);
}
int	Bureaucrat::getGrade()const
{
	return(_grade);
}
void	Bureaucrat::incrementGrade()
{
	if (_grade <= _highestGrade)
		throw GradeTooHighException();
	--_grade;
}
void	Bureaucrat::decrementGrade()
{
	if (_grade >= _lowestGrade)
		throw GradeTooLowException();
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
