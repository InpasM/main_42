/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:37:36 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 21:46:17 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("Unnamed") {

	std::cout << BLACK << "Character: Unnamed Default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
}

Character::Character(std::string name) : _name(name) {

	std::cout << BLACK << "Character: " << name << " Overloaded constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
}

Character::Character(Character const & copy) {

	std::cout << BLACK << "Character: " << copy._name << " Copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
		this->_unequipped[i] = NULL;
	}
	*this = copy;
}

Character::~Character(void) {

	std::cout << BLACK << "Character: Destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
		if (this->_unequipped[i])
		{
			delete this->_unequipped[i];
			this->_unequipped[i] = NULL;
		}
	}
}

Character & Character::operator=(Character const & src) {

	if (this != &src)
	{
		std::cout << BLACK << "Character: Copy assignment operator called" << RESET << std::endl;
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
			if (this->_unequipped[i])
				delete this->_unequipped[i];
			if (src._unequipped[i])
				this->_unequipped[i] = src._unequipped[i]->clone();
			else
				this->_unequipped[i] = NULL;
		}
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {

	int i = -1;

	if (!m)
		std::cout << RED << BOLD << "equip(): Materia invalid!" << RESET << std::endl;
	else
	{
		while (++i < 4)
		{
			if (!this->_inventory[i])
			{
				if (m->isUsed())
					std::cout << RED << BOLD << m->getType() << ": is already equipped/unequipped somewhere!" << RESET << std::endl;
				else
				{
					this->_inventory[i] = m;
					m->updateUsed();
				}
				break ;
			}
		}
		if (i == 4)
			std::cout << RED << BOLD << this->getName() << ": Materia inventory full!" << RESET << std::endl;
	}
}

void Character::unequip(int idx) {

	if (idx < 0 || idx > 3)
		std::cout << RED << BOLD << idx << ": invalid index, 0 -> 3 accepted!" << RESET << std::endl;
	else
	{
		if (!this->_inventory[idx])
			std::cout << RED << BOLD << this->_name << ": no Materia found in inventory at index " << idx << "!" << RESET << std::endl;
		else
		{
			if (this->_unequipped[3])
			{
				std::cout << RED << BOLD << "Unequipped full, array will be cleared of old Materia" << RESET << std::endl;
				for (int i = 0; i < 4; i++)
				{
					delete this->_unequipped[i];
					this->_unequipped[i] = NULL;
				}
				this->_unequipped[0] = this->_inventory[idx];
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					if (!this->_unequipped[i])
					{
						this->_unequipped[i] = this->_inventory[idx];
						break;
					}
				}
			}
			this->_inventory[idx] = NULL;
		}
	}
}

void Character::use(int idx, ICharacter& target) {

	if (idx < 0 || idx > 3)
		std::cout << RED << BOLD << idx << ": invalid index, 0 -> 3 accepted!" << RESET << std::endl;
	else
	{
		if (!this->_inventory[idx])
			std::cout << RED << BOLD << this->_name << ": no Materia found in inventory at index " << idx << "!" << RESET << std::endl;
		else
			this->_inventory[idx]->use(target);
	}
}

void Character::displayCharacter(void) const {
	
	std::cout << "Character " << this->_name << std::endl;
	if (this->_inventory[0] || this->_inventory[1] || this->_inventory[2] || this->_inventory[3])
	{
		std::cout << std::endl << "Inventory:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				std::cout << "- " << this->_inventory[i]->getType() << " (index: " << i << ")" << std::endl;
		}
	}
	if (this->_unequipped[0])
	{
		std::cout << std::endl << "Unequipped:" << std::endl;
		for (int i = 0; this->_unequipped[i]; i++)
			std::cout << "- " << this->_unequipped[i]->getType() << " (index: " << i << ")" << std::endl;
	}
}
