/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:10 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 14:19:38 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(Cat const & copy) : Animal(copy), _brain(new Brain()) {
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat(void) {
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
}

Cat & Cat::operator=(Cat const & src) {

	if (this != &src)
	{
		std::cout << "Cat: Copy assignment operator called" << std::endl;
		for (int i = 0; i < 100; i++)
			this->_brain->addIdea(src._brain->getIdea(i), i);
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << this->type << ": Miiaaaoooouuhh!" << std::endl;
}

void	Cat::setIdea(std::string idea, int index) {
	this->_brain->addIdea(idea, index);
}

void	Cat::display(std::ostream & o) const {
	o << "Cat: " << *this->_brain;
}
