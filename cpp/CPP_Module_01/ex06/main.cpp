/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:19:49 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 14:17:44 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {

	Harl harl;

	if (argc != 2)
		std::cerr << "Error" << std::endl << "HarlFilter: wrong function call" << std::endl
		<< std::endl << "expected:  ./HarlFilter  level ( DEBUG, INFO, WARNING, ERROR )"
		<< std::endl;
	else
		harl.complain(argv[1]);
	return 0;
}
