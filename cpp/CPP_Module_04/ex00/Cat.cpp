/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:27:10 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 13:50:19 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(Cat const & copy) : Animal(copy) {
	std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat: Destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & src) {

	if (this != &src)
	{
		std::cout << "Cat: Copy assignment operator called" << std::endl;
		this->type = src.type;
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << this->type << ": Miiaaaoooouuhh!" << std::endl;
}
