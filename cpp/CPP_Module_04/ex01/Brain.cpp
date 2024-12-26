/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:34:08 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 17:51:06 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain: Default constructor called" << std::endl;
}

Brain::Brain(Brain const & copy) {

	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain(void) {
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & src) {

	if (this != &src)
	{
		std::cout << "Brain: Copy assignment operator called" << std::endl;
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

void    Brain::addIdea(std::string idea, int index) {

	if (index < 0 || index >= NB_IDEA)
		std::cout << "Brain: invalid index!" << std::endl;
	else {
		this->_ideas[index] = idea;
	}
}

std::string	Brain::getIdea(int index) const {
	return this->_ideas[index];
}

std::ostream &	operator<<(std::ostream & o, Brain const & brain) {

	bool	empty = true;

	for (int i = 0; i < 100; i++)
	{
		if (!brain.getIdea(i).empty())
		{
			o << std::endl << "idea " << i << "/ " << brain.getIdea(i);
			empty = false;
		}
	}
	if (empty)
		o << "Brain is empty";
	return o;
}
