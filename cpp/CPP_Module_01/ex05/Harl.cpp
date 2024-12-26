/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:19:55 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 13:39:47 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level) {

	std::string levelArray[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functionArray[4])() const = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 4; i++)
	{
		if (levelArray[i] == level)
			(this->*(functionArray[i]))();
	}	
}

void	Harl::debug(void) const {
	std::cout << "[ DEBUG ]" << std::endl
	<< "I love having extra bacon for my 7XL-double-cheese-triple-\
pickle-special-ketchup burger. I really do !" << std::endl << std::endl;
}

void	Harl::info(void) const {
	std::cout << "[ INFO ]" << std::endl
	<< "I cannot believe adding extra bacon costs more money." << std::endl
	<< "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
	<< std::endl << std::endl;
}

void	Harl::warning(void) const {
	std::cout << "[ WARNING ]" << std::endl
	<< "I think I deserve to have some extra bacon for free." << std::endl
	<< "I’ve been coming for years whereas you started working here since last month." 
	<< std::endl << std::endl;
}

void	Harl::error(void) const {
	std::cerr << "[ ERROR ]" << std::endl
	<< "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}
