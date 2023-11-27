/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 00:11:10 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 13:49:15 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	
	int	mikeN(5);
	int	georgeN(20);
	int	thomasN(-2);

	Zombie*	mikeHorde = zombieHorde(mikeN, "Mike");
	Zombie*	georgeHorde = zombieHorde(georgeN, "George");
	Zombie*	thomasHorde = zombieHorde(thomasN, "Thomas");
	
	for (int i = 0; i < mikeN; i++)
		mikeHorde[i].announce();
	
	for (int i = 0; i < georgeN; i++)
		georgeHorde[i].announce();

	for (int i = 0; i < thomasN; i++)
		thomasHorde[i].announce();

	delete [] georgeHorde;
	delete [] mikeHorde;
	delete [] thomasHorde;
	return (0);
}
