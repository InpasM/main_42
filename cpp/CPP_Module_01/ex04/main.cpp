/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 22:58:40 by msapin            #+#    #+#             */
/*   Updated: 2023/08/29 14:28:32 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	displayError(std::string name, int numError) {
	std::string err[4];

	err[0] = ": wrong function call\n\nexpected:  ./sed  filename  s1  s2";
	err[1] = ": invalid, cannot be empty";
	err[2] = ": no such file or directory";
	err[3] = ": cannot create such file";

	std::cout << "Error" << std::endl << name << err[numError] << std::endl;
	return -1;
}

int	main(int argc, char** argv) {

	Sed*	sed = new Sed;

	if (argc != 4)
		displayError("sed", 0);
	else
	{
		if (sed->parseArgs(argv) != 0)
			return -1;
		sed->searchFile();
		delete sed;
	}
	return 0;
}
