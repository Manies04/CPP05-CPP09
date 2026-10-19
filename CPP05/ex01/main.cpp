/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:20:26 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/16 23:51:27 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	title(const std::string &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

int	main()
{
	title("Valid forms");
	try
	{
		Form	tax("Tax", 50, 25);
		Form	def;

		std::cout << tax << std::endl;
		std::cout << def << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Grade to sign 0 (too high)");
	try
	{
		Form	f("Bad", 0, 50);
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Grade to execute 151 (too low)");
	try
	{
		Form	f("Bad", 50, 151);
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	title("Bureaucrat with enough grade signs");
	{
		Bureaucrat	boss("Boss", 10);
		Form		contract("Contract", 50, 25);

		std::cout << contract << std::endl;
		boss.signForm(contract);
		std::cout << contract << std::endl;
	}

	title("Bureaucrat with too low grade fails");
	{
		Bureaucrat	intern("Intern", 120);
		Form		permit("Permit", 100, 50);

		intern.signForm(permit);
		std::cout << permit << std::endl;
	}

	title("Same grade as required signs (limit case)");
	{
		Bureaucrat	clerk("Clerk", 100);
		Form		permit("Permit", 100, 50);

		clerk.signForm(permit);
		std::cout << permit << std::endl;
	}

	title("beSigned called directly throws");
	try
	{
		Bureaucrat	intern("Intern", 150);
		Form		secret("Secret", 1, 1);

		secret.beSigned(intern);
		std::cout << "This line must not be printed" << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Caught Form::GradeTooLowException: " << e.what() << std::endl;
	}

	title("Copy and assignment");
	{
		Bureaucrat	boss("Boss", 1);
		Form		original("Original", 30, 20);

		boss.signForm(original);
		Form		copy(original);
		Form		assigned("Other", 140, 140);

		assigned = original;
		std::cout << "original: " << original << std::endl;
		std::cout << "copy:     " << copy << std::endl;
		std::cout << "assigned: " << assigned << std::endl;
	}
	return (0);
}