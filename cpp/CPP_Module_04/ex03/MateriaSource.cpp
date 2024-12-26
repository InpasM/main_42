/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:03 by msapin            #+#    #+#             */
/*   Updated: 2023/10/03 16:13:33 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {

	std::cout << BLACK << "MateriaSource: Default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materiaArray[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & copy) {

	std::cout << BLACK << "MateriaSource: Copy constructor called" << RESET << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void) {
	
	std::cout << BLACK << "MateriaSource: Destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaArray[i])
			delete this->_materiaArray[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "MateriaSource: Copy assignment operator called" << RESET << std::endl;
		for (int i = 0; i < 4; i++)
		{
			if (this->_materiaArray[i])
				delete this->_materiaArray[i];
			if (src._materiaArray[i])
				this->_materiaArray[i] = src._materiaArray[i];
			else
				this->_materiaArray[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* rhs) {

	int	i = -1;

	while (++i < 4)
	{
		if (!this->_materiaArray[i]) {
			this->_materiaArray[i] = rhs;
			break ;
		}
	}
	if (i == 4)
	{
		std::cout << RED << BOLD << "MateriaSource: array full, cannot learn any other Materia!" << RESET << std::endl;
		delete rhs;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {

	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaArray[i] && type == this->_materiaArray[i]->getType())
			return this->_materiaArray[i]->clone();
	}
	return 0;
}

void MateriaSource::displayContent(void) const {

	if (this->_materiaArray[0])
		std::cout << "MateriaSource contains:" << std::endl;
	else
		std::cout << "MateriaSource doesn't contains any Materia!" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaArray[i])
			std::cout << "- " << this->_materiaArray[i]->getType() << " (index: " << i << ")" << std::endl;
	}
}
