/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:19:38 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 11:04:13 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int	main(void) {

	std::cout << std::endl << std::endl << "\033[1m\033[32m" << "TESTS EX02" << "\033[0m" << std::endl;
	{
		displayMessage("Create default FragTrap()");
		FragTrap	noName;
		std::cout << noName << std::endl;

		displayMessage("Create overloaded FragTrap(name)");
		FragTrap	markus("Markus");
		std::cout << markus << std::endl;
		
		displayMessage("display stat before copy");
		FragTrap	forCopy("ForCopy");
		std::cout << forCopy << std::endl;
		forCopy = markus;
		displayMessage("display stat after copy");
		std::cout << forCopy << std::endl;

		displayMessage("FragTrap attack other FragTrap until he's dead");
		while (noName.getHitPoints())
		{
			markus.attack(noName.getName());
			noName.takeDamage(markus.getAttackDamage());
		}
		displayMessage("FragTrap attack again even if other is dead");
		markus.attack(noName.getName());
		noName.takeDamage(markus.getAttackDamage());

		displayMessage("FragTrap ask for high five until yes or no");
		markus.highFivesGuys();

		displayMessage("FragTrap try to ask for high five but he's dead");
		noName.highFivesGuys();
		
		std::cout << std::endl;
	}
	return 0;
}
