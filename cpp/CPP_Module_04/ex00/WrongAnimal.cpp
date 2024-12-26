/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:58:11 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 13:43:09 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongAnimal::WrongAnimal(void) : type("Notype") {
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal: " << type << " Overloaded constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & copy) : type(copy.type) {
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {

	std::cout << "WrongAnimal: ";
	if (!this->type.empty())
		std::cout << this->type << " ";
	std::cout << "Destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src) {

	if (this != &src)
	{
		std::cout << "WrongAnimal: Copy assignment operator called" << std::endl;
		this->type = src.type;
	}
	return *this;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << this->type << ": cannot make any noise!" << std::endl;
}
