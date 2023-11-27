/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:19:38 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 11:07:49 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int	main(void) {

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX03" << "\033[0m" << std::endl;
	{
		displayMessage("Create default DiamondTrap()");
		DiamondTrap	noName;
		std::cout << noName << std::endl;

		displayMessage("WhoAmI() Unnamed");
		noName.whoAmI();

		displayMessage("Displaying name of each class");
		std::cout << "ClapTrap name for noName : " << noName.ClapTrap::getName() << std::endl;
		std::cout << "ScavTrap name for noName : " << noName.ScavTrap::getName() << std::endl;
		std::cout << "FragTrap name for noName : " << noName.FragTrap::getName() << std::endl;

		displayMessage("Create overloaded DiamondTrap(name)");
		DiamondTrap	markus("Markus");
		std::cout << markus << std::endl;

		displayMessage("WhoAmI() Markus");
		markus.whoAmI();

		displayMessage("DiamondTrap use ScavTrap attack");
		markus.attack(noName.getName());

		displayMessage("DiamondTrap use ScavTrap's special function: guardGate()");
		markus.guardGate();

		displayMessage("DiamondTrap use FragTrap's special function: highFivesGuys()");
		markus.highFivesGuys();

		std::cout << std::endl;
	}
	return 0;
}
