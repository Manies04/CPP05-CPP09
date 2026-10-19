/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:20:26 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/16 17:13:49 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	title(const std::string &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

int	main()
{
	title("Valid bureaucrats");
	try
	{
		Bureaucrat	alice("Alice", 1);
		Bureaucrat	bob("Bob", 150);
		Bureaucrat	def;

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << def << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Grade 0 (too high)");
	try
	{
		Bureaucrat	b("Zero", 0);
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Grade 151 (too low)");
	try
	{
		Bureaucrat	b("Big", 151);
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Increment and decrement");
	try
	{
		Bureaucrat	carl("Carl", 3);

		std::cout << carl << std::endl;
		carl.incrementGrade();
		std::cout << "After increment: " << carl << std::endl;
		carl.decrementGrade();
		carl.decrementGrade();
		std::cout << "After 2 decrements: " << carl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Increment at grade 1");
	Bureaucrat	top("Top", 1);
	try
	{
		top.incrementGrade();
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Unchanged: " << top << std::endl;

	title("Decrement at grade 150");
	Bureaucrat	bottom("Bottom", 150);
	try
	{
		bottom.decrementGrade();
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Unchanged: " << bottom << std::endl;

	title("Catching the exact exception type");
	try
	{
		Bureaucrat	b("Dave", 200);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
	}

	title("Copy constructor and assignment");
	{
		Bureaucrat	original("Eve", 42);
		Bureaucrat	copy(original);
		Bureaucrat	assigned("Frank", 100);

		assigned = original;
		std::cout << "original: " << original << std::endl;
		std::cout << "copy:     " << copy << std::endl;
		std::cout << "assigned: " << assigned << std::endl;
	}
	return (0);
}

