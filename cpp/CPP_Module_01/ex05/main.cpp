/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:19:49 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 13:40:09 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {

	Harl harl;

	for (int i = 0; i < 3; i++)
	{
		std::cout << "\033[1;33m" << "Complain about DEBUG:" << "\033[0m" << std::endl;
		harl.complain("DEBUG");

		std::cout << "\033[1;33m" << "Complain about INFO:" << "\033[0m" << std::endl;
		harl.complain("INFO");

		std::cout << "\033[1;33m" << "Complain about WARNING:" << "\033[0m" << std::endl;
		harl.complain("WARNING");

		std::cout << "\033[1;33m" << "Complain about ERROR:" << "\033[0m" << std::endl;
		harl.complain("ERROR");

		std::cout << "\033[1;33m" << "Complain about OTHER:" << "\033[0m" << std::endl << std::endl;
		harl.complain("OTHER");
	}
	return 0;
}
