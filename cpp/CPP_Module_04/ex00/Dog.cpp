/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:03 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 13:50:29 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog: Default constuctor called" << std::endl;
}

Dog::Dog(Dog const & copy) : Animal(copy) {
	std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & src) {
	
	if (this != &src)
	{
		std::cout << "Dog: Copy assignment operator called" << std::endl;
		this->type = src.type;
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << this->type << ": Waaooouuff!" << std::endl;
}
