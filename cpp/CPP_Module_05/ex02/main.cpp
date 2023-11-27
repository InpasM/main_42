/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:57:46 by msapin            #+#    #+#             */
/*   Updated: 2023/11/16 14:08:42 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	displayMessage(const std::string sentence) {
	std::cout << std::endl << YELLOW << sentence << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX02 - Testing ShrubberyCreationForm" << "\033[0m" << std::endl;
		displayMessage("Creating Bureaucrat");
		Bureaucrat member("Member", 138);

		displayMessage("Creating ShrubberyCreationForm");
		ShrubberyCreationForm shrubForm("countryside");

		displayMessage("Displaying Form stats");
		std::cout << shrubForm << std::endl;

		displayMessage("Member try to execute shrubForm");
		member.executeForm(shrubForm);

		displayMessage("Member sign shrubForm");
		member.signForm(shrubForm);

		displayMessage("Member try to execute shrubForm again");
		member.executeForm(shrubForm);
		std::cout << member << std::endl;
		std::cout << shrubForm << std::endl;

		displayMessage("Member increment grade than execute shrubForm");
		member.incrementGrade();
		std::cout << member << std::endl;
		member.executeForm(shrubForm);

		displayMessage("Deleting all");
	}

	{
		std::cout << std::endl << "\033[1m\033[32m" << "TESTS EX02 - Testing RobotomyRequestForm" << "\033[0m" << std::endl;
		displayMessage("Creating Bureaucrat");
		Bureaucrat member("Member", 46);

		displayMessage("Creating RobotomyRequestForm");
		RobotomyRequestForm robotomyForm("Sara");

		displayMessage("Displaying Form stats");
		std::cout << robotomyForm << std::endl;

		displayMessage("Member try to execute robotomyForm");
		member.executeForm(robotomyForm);

		displayMessage("Member sign robotomyForm");
		member.signForm(robotomyForm);

		displayMessage("Member try to execute robotomyForm again");
		member.executeForm(robotomyForm);
		std::cout << member << std::endl;
		std::cout << robotomyForm << std::endl;

		displayMessage("Member increment grade than execute robotomyForm");
		member.incrementGrade();
		std::cout << member << std::endl;
		member.executeForm(robotomyForm);

		displayMessage("Deleting all");
	}

	{
		std::cout << std::endl << "\033[1m\033[32m" << "TESTS EX02 - Testing PresidentialPardonForm" << "\033[0m" << std::endl;
		displayMessage("Creating Bureaucrat");
		Bureaucrat member("Member", 6);

		displayMessage("Creating PresidentialPardonForm");
		PresidentialPardonForm pardonForm("Mike");

		displayMessage("Displaying Form stats");
		std::cout << pardonForm << std::endl;

		displayMessage("Member try to execute pardonForm");
		member.executeForm(pardonForm);

		displayMessage("Member sign pardonForm");
		member.signForm(pardonForm);

		displayMessage("Member try to execute pardonForm again");
		member.executeForm(pardonForm);
		std::cout << member << std::endl;
		std::cout << pardonForm << std::endl;

		displayMessage("Member increment grade than execute pardonForm");
		member.incrementGrade();
		std::cout << member << std::endl;
		member.executeForm(pardonForm);

		displayMessage("Deleting all");
	}

	return 0;
}
