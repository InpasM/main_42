/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:22:10 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 13:33:02 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Notype") {
	std::cout << "Animal: Notype Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal: " << type << " Overloaded constructor called" << std::endl;
}

Animal::Animal(Animal const & copy) : type(copy.type) {
	std::cout << "Animal: " << copy.type << " Copy constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal: " << this->type << " Destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const & src) {

	if (this != &src)
	{
		std::cout << "Animal: Copy assignment operator called" << std::endl;
		this->type = src.type;
	}
	return *this;
}

std::string Animal::getType(void) const {
	return this->type;
}

void	Animal::makeSound(void) const {
	std::cout << this->type << ": cannot make any noise!" << std::endl;
}
