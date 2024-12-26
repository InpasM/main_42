/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:03 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 16:49:37 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << "Dog: Default constuctor called" << std::endl;
}

Dog::Dog(Dog const & copy) : AAnimal(copy), _brain(new Brain()) {
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog(void) {
	std::cout << "Dog: Destructor called" << std::endl;
	delete this->_brain;
}

Dog & Dog::operator=(Dog const & src) {

	if (this != &src)
	{
		std::cout << "Dog: Copy assignment operator called" << std::endl;
		for (int i = 0; i < 100; i++)
			this->_brain->addIdea(src._brain->getIdea(i), i);
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << this->type << ": Waaooouuff!" << std::endl;
}

void	Dog::setIdea(std::string idea, int index) {
	this->_brain->addIdea(idea, index);
}

void	Dog::display(std::ostream & o) const {
	o << "Dog: " << *this->_brain;
}
