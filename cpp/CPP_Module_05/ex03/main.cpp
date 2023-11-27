/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:57:46 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 14:21:55 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	displayMessage(const std::string sentence) {
	std::cout << std::endl << YELLOW << sentence << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX03 - Testing Intern" << "\033[0m" << std::endl;
		std::string name = "invalid name";
		displayMessage("Creating intern");
		Intern someRandomIntern;
		
		displayMessage("Using intern to create Form, invalid name");
		Form* invalidForm = someRandomIntern.makeForm("invalid name", "Target");

		displayMessage("Displaying form stats");
		std::cout << invalidForm << std::endl;

		displayMessage("Using intern to create Form, Shrubbery");
		Form* shrubberyForm = someRandomIntern.makeForm("shrubbery creation", "Target");

		displayMessage("Displaying Shrubbery stats");
		std::cout << *shrubberyForm << std::endl;

		displayMessage("Using intern to create Form, Robotomy");
		Form* robotomyForm = someRandomIntern.makeForm("robotomy request", "Target");

		displayMessage("Displaying Robotomy stats");
		std::cout << *robotomyForm << std::endl;

		displayMessage("Using intern to create Form, Presidential");
		Form* presidentialForm = someRandomIntern.makeForm("presidential pardon", "Target");

		displayMessage("Displaying Presidential stats");
		std::cout << *presidentialForm << std::endl;

		displayMessage("Creating Bureaucrat");
		Bureaucrat memberLow("MemberLow", 150);
		Bureaucrat memberHigh("MemberHigh", 1);

		displayMessage("memberLow trying to sign all form");
		memberLow.executeForm(*shrubberyForm);
		memberLow.executeForm(*robotomyForm);
		memberLow.executeForm(*presidentialForm);

		displayMessage("memberHigh signing all form");
		memberHigh.signForm(*shrubberyForm);
		memberHigh.signForm(*robotomyForm);
		memberHigh.signForm(*presidentialForm);

		displayMessage("memberLow trying to sign again");
		memberLow.executeForm(*shrubberyForm);
		memberLow.executeForm(*robotomyForm);
		memberLow.executeForm(*presidentialForm);

		displayMessage("memberHigh execute shrubberyForm");
		memberHigh.executeForm(*shrubberyForm);

		displayMessage("memberHigh execute robotomyForm");
		memberHigh.executeForm(*robotomyForm);
		
		displayMessage("memberHigh execute presidentialForm");
		memberHigh.executeForm(*presidentialForm);

		displayMessage("Deleting all");
		delete invalidForm;
		delete shrubberyForm;
		delete robotomyForm;
		delete presidentialForm;
	}

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX03 - Tests subject" << "\033[0m" << std::endl;
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		displayMessage("Displaying rrf stats");
		std::cout << *rrf << std::endl;

		displayMessage("Deleting all");
		delete rrf;
	}

	return 0;
}
