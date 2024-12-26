/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:10:17 by msapin            #+#    #+#             */
/*   Updated: 2023/10/18 15:58:00 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap: Unnamed Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardingGate = false;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap: " << name << " Overloaded constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_guardingGate = false;
}

ScavTrap::ScavTrap(ScavTrap const & copy) : ClapTrap(copy) {
	std::cout << "ScavTrap: " << copy._name << " Copy constructor called" << std::endl;
	this->setGuardingGate(copy.getGuardingGate());
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap: " << this->_name << " Destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src) {

	if (this != &src)
	{
		std::cout << "ScavTrap: Copy assignment operator" << std::endl;
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
		this->_guardingGate = src._guardingGate;
	}
	return *this;
}

bool	ScavTrap::getGuardingGate(void) const {
	return this->_guardingGate;
}

void	ScavTrap::setGuardingGate(bool mode) {
	this->_guardingGate = mode;
}

void	ScavTrap::guardGate(void) {

	if (this->getHitPoints() == 0)
		std::cout << "ScavTrap " << this->getName() << " is dead and cannot be in gate keeper mode!" << std::endl;
	else if (this->getGuardingGate())
		std::cout << "ScavTrap " << this->getName() << " is already in gate keeper mode!" << std::endl;
	else
	{
		this->setGuardingGate(true);
		std::cout << "ScavTrap " << this->getName() << " is now in gate keeper mode!" << std::endl;
	}
}

void	ScavTrap::attack(std::string const & target) {

	if (this->getHitPoints() == 0)
		std::cout << this->getName() << " is dead and cannot destroy anyone!" << std::endl;
	else
	{
		if (this->getEnergyPoints() > 0)
		{
			std::cout << this->getName() << " destroy " << target << std::endl;
			this->setEnergyPoints(this->getEnergyPoints() - 1);
		}
		else
			std::cout << this->getName() << " doesn't have enough energy points to destroy!" << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & o, ScavTrap const & i) {
	o << i.getName() << ":  " << i.getHitPoints() << " hit points,  " << i.getEnergyPoints()
	<< " energy points,  " << i.getAttackDamage() << " damage points,  ";
	if (i.getGuardingGate())
		o << "is guarding the gate!";
	else
		o << "is not guarding the gate!";
	return o;
}
