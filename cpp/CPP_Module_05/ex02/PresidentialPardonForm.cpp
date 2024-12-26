/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:35:43 by msapin            #+#    #+#             */
/*   Updated: 2023/10/23 12:29:34 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form("Default", 25, 5) {
	std::cout << BLACK << "PresidentialPardonForm: Default_shrubbery constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5) {
	std::cout << BLACK << "PresidentialPardonForm: " << target << " Overloaded constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : Form(copy) {
	std::cout << BLACK << "PresidentialPardonForm: " << copy.getName() << " Copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << BLACK << "PresidentialPardonForm: " << this->getName() << " Destructor called" << RESET << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "PresidentialPardonForm: Copy assignment operator" << RESET << std::endl;
		this->setIsSigned(src.getIsSigned());
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {

	if (this->isExecutable(executor))
	{
		std::cout << this->getName() << " is forgiven by Zaphod Beeblebrox." << std::endl;
	}
}
