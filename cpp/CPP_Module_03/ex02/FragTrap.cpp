/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:58:26 by msapin            #+#    #+#             */
/*   Updated: 2023/10/18 15:45:43 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap: Unnamed Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap: " << name << " Overloaded constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap: " << this->_name << " Destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & src) {

	if (this != &src)
	{
		std::cout << "FragTrap: Copy assignment operator" << std::endl;
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void	FragTrap::highFivesGuys(void) {

	std::string	tmpAnswer;

	if (this->getHitPoints())
	{
		while (!std::cin.eof())
		{
			std::cout << this->getName() << ": HighFive ? (yes/no)" << std::endl << std::endl;
			std::cin >> tmpAnswer;
			if (tmpAnswer == "yes")
			{
				std::cout << this->getName() << ": Yeeaaahhhh!!  *clap*" << std::endl;
				break ;
			}
			else if (tmpAnswer == "no")
			{
				std::cout << this->getName() << ": Ok...  *sniff*" << std::endl;
				break ;
			}
		}
	}
	else
		std::cout << this->getName() << " is dead and cannot ask for a HighFive!" << std::endl;
}
