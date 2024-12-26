/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:58:07 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 16:54:07 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & copy) : WrongAnimal(copy) {
	std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & src) {

	if (this != &src)
	{
		std::cout << "WrongCat: Copy assignment operator called" << std::endl;
		this->type = src.type;
	}
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << this->type << ": Miiaaaoooouuhh!" << std::endl;
}
