/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:35:33 by msapin            #+#    #+#             */
/*   Updated: 2023/10/18 15:58:00 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap(), _name("Unnamed") {

	std::cout << "DiamondTrap: Unnamed Default constructor called" << std::endl;
	ClapTrap::_name = "Unnamed_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name), _name(name) {

	std::cout << "DiamondTrap: " << name << " Overloaded constructor called" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(DiamondTrap const & copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	std::cout << "DiamondTrap: " << copy._name << " Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap: " << this->_name << " Destructor called" << std::endl;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & src) {
	
	if (this != &src)
	{
		std::cout << "DiamondTrap: Copy assignment operator" << std::endl;

		ClapTrap::operator=(src);
        FragTrap::operator=(src);
        ScavTrap::operator=(src);
		this->DiamondTrap::_name = src.DiamondTrap::_name;
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

void	DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap's name is: " << this->_name << " and ClapTrap's name: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getDiamondName(void) const {
    return this->DiamondTrap::_name;
}

std::ostream & operator<<(std::ostream & o, DiamondTrap const & i) {

	o << i.getDiamondName() << ":  " << i.getHitPoints() << " hit points,  " << i.getEnergyPoints()
	<< " energy points,  " << i.getAttackDamage() << " damage points";
	return o;
}
