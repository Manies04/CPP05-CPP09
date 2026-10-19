/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 00:20:26 by tiade-al          #+#    #+#             */
/*   Updated: 2026/10/19 21:53:03 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

static void	title(const std::string &text)
{
	std::cout << std::endl << "===== " << text << " =====" << std::endl;
}

// Signs and executes a form made by the intern, then frees it.
static void	process(const Bureaucrat &bureaucrat, AForm *form)
{
	if (form == NULL)
		return ;
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
}

int	main()
{
	std::srand(std::time(NULL));

	Intern		someRandomIntern;
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	middle("Middle", 70);

	title("Example from the subject");
	{
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		process(boss, rrf);
	}

	title("All three forms");
	process(boss, someRandomIntern.makeForm("shrubbery creation", "office"));
	process(boss, someRandomIntern.makeForm("presidential pardon", "Arthur Dent"));

	title("Bureaucrat without enough grade");
	process(middle, someRandomIntern.makeForm("presidential pardon", "Marvin"));

	title("Unknown form names");
	{
		AForm	*f1 = someRandomIntern.makeForm("coffee request", "Boss");
		AForm	*f2 = someRandomIntern.makeForm("Robotomy Request", "Bender");

		if (f1 == NULL && f2 == NULL)
			std::cout << "Both returned NULL, nothing to delete." << std::endl;
	}
	return (0);
}