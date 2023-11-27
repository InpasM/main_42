/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:19:38 by msapin            #+#    #+#             */
/*   Updated: 2023/10/20 10:57:51 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

int	main(void) {

	ClapTrap	mike("Mike");
	ClapTrap	george("George");
	ClapTrap	tom("Tom");
	ClapTrap	forCopy;

	displayMessage("display stat before copy");
	std::cout << forCopy << std::endl;
	forCopy = george;
	displayMessage("display stat after copy");
	std::cout << forCopy << std::endl;

	displayMessage("attack without attackDamage points");
	mike.attack(george.getName());
	george.takeDamage(mike.getAttackDamage());
	
	displayMessage("attack that kill");
	mike.setAttackDamage(10);
	mike.attack(george.getName());
	george.takeDamage(mike.getAttackDamage());

	displayMessage("try to attack someone even if dead");
	george.attack(mike.getName());

	displayMessage("character recover hit points after death");
	george.beRepaired(5);

	displayMessage("normal attack");
	tom.setAttackDamage(5);
	tom.attack(mike.getName());
	mike.takeDamage(tom.getAttackDamage());

	displayMessage("character recover hit points");
	mike.beRepaired(15);

	displayMessage("using << operator to display stats of player");
	std::cout << mike << std::endl;
	std::cout << george << std::endl;
	std::cout << tom << std::endl;

	displayMessage("set energy points to zero then try to attack");
	tom.setEnergyPoints(0);
	tom.attack(mike.getName());

	displayMessage("try to heal with zero energy points");
	tom.beRepaired(10);

	displayMessage("attack with way more damage than hit points");
	mike.setAttackDamage(100);
	mike.attack(tom.getName());
	tom.takeDamage(mike.getAttackDamage());
	
	std::cout << std::endl;
	return 0;
}
