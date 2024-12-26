/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:52 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 23:06:00 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria(), _used(false) {
	std::cout << BLACK << "Cure: Default constructor called" << RESET << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const & copy) : AMateria(copy), _used(false) {

	std::cout << BLACK << "Cure: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Cure::~Cure(void) {
	std::cout << BLACK << "Cure: Destructor called" << RESET << std::endl;
}

Cure & Cure::operator=(Cure const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "Cure: Copy assignment operator" << RESET << std::endl;
		this->type = src.type;
		this->_used = src._used;
	}
	return *this;
}

AMateria* Cure::clone(void) const {
	return new Cure();
}

void	Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

bool Cure::isUsed(void) const {
	return this->_used;
}

void Cure::updateUsed(void) {
	if (this->_used)
		this->_used = false;
	else
		this->_used = true;
}
