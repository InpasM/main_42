/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:10 by msapin            #+#    #+#             */
/*   Updated: 2023/10/02 18:46:47 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Notype") {
	std::cout << "AAnimal: Notype Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "AAnimal: " << type << " Overloaded constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & copy) : type(copy.type) {
	std::cout << "AAnimal: " << copy.type << " Copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal: " << this->type << " Destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & src) {

	if (this != &src)
	{
		std::cout << "AAnimal: Copy assignment operator called" << std::endl;
		this->type = src.type;
	}
	return *this;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

void	AAnimal::makeSound(void) const {
	std::cout << this->type << ": cannot make any noise!" << std::endl;
}

std::ostream &	operator<<(std::ostream & o, AAnimal const & i) {

	i.display(o);
	return o;
}
