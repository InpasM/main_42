/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:35 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 21:45:43 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("Untyped") {
	std::cout << BLACK << "AMateria: Untyped Default constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << BLACK << "AMateria: " << type << " Overloaded constructor called" << RESET << std::endl;
}

AMateria::AMateria(AMateria const & copy) {

	std::cout << BLACK << "AMateria: " << copy.type << " Copy constructor called" << RESET << std::endl;
	*this = copy;
}

AMateria::~AMateria(void) {
	std::cout << BLACK << "AMateria: " << this->type << " Destructor called" << RESET << std::endl;
}

AMateria & AMateria::operator=(AMateria const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "AMateria: Copy assignment operator called" << RESET << std::endl;
		this->type = src.type;
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter & target) {
	std::cout << RED << this->type << " cannot do anything to " << target.getName() << RESET << std::endl;
}
