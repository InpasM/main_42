/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:16:47 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 21:47:29 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria(), _used(false) {

	std::cout << BLACK << "Ice: Default constructor called" << RESET << std::endl;
	this->type = "ice";
}

Ice::Ice(Ice const & copy) : AMateria(copy),_used(false) {

	std::cout << BLACK << "Ice: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

Ice::~Ice(void) {
	std::cout << BLACK << "Ice: Destructor called" << RESET << std::endl;
}

Ice & Ice::operator=(Ice const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "Ice: Copy assignment operator" << RESET << std::endl;
		this->type = src.type;
		this->_used = src._used;
	}
	return *this;
}

AMateria* Ice::clone(void) const {
	return new Ice();
}

void	Ice::use(ICharacter & target) {
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}

bool Ice::isUsed(void) const {
	return this->_used;
}

void Ice::updateUsed(void) {

	if (this->_used)
		this->_used = false;
	else
		this->_used = true;
}
