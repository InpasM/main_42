/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:49:22 by msapin            #+#    #+#             */
/*   Updated: 2023/10/23 13:18:00 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << BLACK << "Intern: Default constructor called" << RESET << std::endl;
}

Intern::Intern(Intern const & copy) {

	std::cout << BLACK << "Intern: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Intern::~Intern(void) {
	std::cout << BLACK << "Intern: Destructor called" << RESET << std::endl;
}

Intern & Intern::operator=(Intern const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "Intern: Copy assignment operator" << RESET << std::endl;
	}
	return *this;
}

Form * Intern::getShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form * Intern::getRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

Form * Intern::getPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

Form * Intern::makeForm(std::string name, std::string target) {

	std::string formChoice[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form * (Intern::*formFunction[3])(std::string) = {
		&Intern::getShrubbery,
		&Intern::getRobotomy,
		&Intern::getPresidential,
	};
	for (int i = 0; i < 3; i++)
	{
		if (name == formChoice[i])
			return (this->*formFunction[i])(target);
	}
	return NULL;
}
