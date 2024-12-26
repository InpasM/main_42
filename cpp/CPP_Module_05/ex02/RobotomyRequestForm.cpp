/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:19:10 by msapin            #+#    #+#             */
/*   Updated: 2023/10/23 15:55:38 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form("Default", 72, 45) {
	std::cout << BLACK << "RobotomyRequestForm: Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45) {
	std::cout << BLACK << "RobotomyRequestForm: " << target << " Overloaded constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy) : Form(copy) {
	std::cout << BLACK << "RobotomyRequestForm: " << copy.getName() << " Copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << BLACK << "RobotomyRequestForm: " << this->getName() << " Destructor called" << RESET << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "RobotomyRequestForm: Copy assignment operator" << RESET << std::endl;
		this->setIsSigned(src.getIsSigned());
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	if (this->isExecutable(executor))
	{
		srand(time(NULL));
		int	success = rand() % 2;

		std::cout << "*** DRILLING NOISE *** ";
		if (success)
			std::cout << GREEN << "Robotomy of " << this->getName() << " was successful!" << RESET << std::endl;
		else
			std::cout << RED << "Robotomy of " << this->getName() << " failed!" << RESET << std::endl;
	}
}
