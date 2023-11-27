/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:46:10 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 13:51:47 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void) {

	std::cout << "TEST with reference" << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl << "TEST with pointer" << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << std::endl << "TEST without giving weapon" << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	mike("Mike");
		mike.attack();
		mike.setWeapon(club);
		club.setType("some other type of club");
		mike.attack();
	}
	return 0;
}
