/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:19:38 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 11:03:54 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int	main(void) {

	std::cout << std::endl << "\033[1m\033[32m" << "TESTS EX01" << "\033[0m" << std::endl;
	{
		displayMessage("Create default ScavTrap()");
		ScavTrap	noName;
		std::cout << noName << std::endl;

		displayMessage("Create overloaded ScavTrap(name)");
		ScavTrap	markus("Markus");
		std::cout << markus << std::endl;

		displayMessage("Change value of ScavTrap using ClapTrap function");
		markus.setHitPoints(150);
		std::cout << markus << std::endl;

		displayMessage("Attack using ClapTrap function attack()");
		markus.ClapTrap::attack(noName.getName());
		noName.takeDamage(markus.getAttackDamage());

		displayMessage("Attack using ScavTrap function attack() after upgraded attackDamage");
		markus.setAttackDamage(150);
		markus.attack(noName.getName());
		noName.takeDamage(markus.getAttackDamage());

		displayMessage("Using guardGate() function");
		markus.guardGate();

		displayMessage("Trying an other time guardGate() function");
		markus.guardGate();

		displayMessage("Using guardGate() function when dead");
		noName.guardGate();

		displayMessage("displaying stats of scavtrap");
		std::cout << markus << std::endl;
		std::cout << noName << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
