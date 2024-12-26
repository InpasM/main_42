/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:19:40 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 11:01:14 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hitPoints(10), 
_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap: Unnamed Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), 
_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap: " << this->_name << " Overloaded constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & copy) {
	std::cout << "ClapTrap: " << copy._name << " Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap: " << this->_name << " Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src) {

	if (this != &src)
	{
		std::cout << "ClapTrap: Copy assignment operator" << std::endl;
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

std::string const &	ClapTrap::getName(void) const {
	return this->_name;
}

int	ClapTrap::getHitPoints(void) const {
	return	this->_hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const {
	return	this->_energyPoints;
}

int	ClapTrap::getAttackDamage(void) const {
	return	this->_attackDamage;
}

void	ClapTrap::setName(std::string name) {
	this->_name = name;
}

void	ClapTrap::setHitPoints(int hitPoints) {

	if (hitPoints < 0)
		this->_hitPoints = 0;
	else
		this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints) {
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage) {
	this->_attackDamage = attackDamage;
}

void	ClapTrap::attack(std::string const & target) {

	if (this->getHitPoints() == 0)
		std::cout << this->getName() << " is dead and cannot attack anyone!" << std::endl;
	else
	{
		if (this->getEnergyPoints() > 0)
		{
			std::cout << this->getName() << " attack " << target << std::endl;
			this->setEnergyPoints(this->getEnergyPoints() - 1);
		}
		else
			std::cout << this->getName() << " doesn't have enough energy points to attack!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (amount == 0)
		std::cout << this->getName() << " doesn't take any damage" << std::endl;
	else
	{
		if (this->getHitPoints() == 0)
			std::cout << this->getName() << " is already dead and cannot take more damage!" << std::endl;
		else
		{
			std::cout << this->getName() << " lose " << amount << " hit points! ";
			this->setHitPoints(this->getHitPoints() - amount);
			if (this->getHitPoints() == 0)
				std::cout << this->getName() << " has died from this attack!" << std::endl;
			else
				std::cout << this->getName() << " has now " << this->getHitPoints() << " points left" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->getHitPoints() == 0)
		std::cout << this->getName() << " is dead and cannot recover!" << std::endl;
	else if (this->getEnergyPoints() == 0)
		std::cout << this->getName() << " doesn't have enough energy points to recover!" << std::endl;
	else
	{
		if (amount == 0)
			std::cout << this->getName() << " recover zero points!" << std::endl;
		else
		{
			std::cout << this->getName() << " recover " << amount << " hit points! Making a total of "
			<< this->getHitPoints() + amount << " points." << std::endl;
			this->setHitPoints(this->getHitPoints() + amount);
		}
	}
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & i) {

	o << i.getName() << ":  " << i.getHitPoints() << " hit points,  " << i.getEnergyPoints()
	<< " energy points,  " << i.getAttackDamage() << " damage points";
	return o;
}
