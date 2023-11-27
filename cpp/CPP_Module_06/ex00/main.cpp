/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:33:58 by msapin            #+#    #+#             */
/*   Updated: 2023/11/20 13:03:47 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int    displayError(std::string words) {
	std::cout << RED << BOLD << "error: " << RESET << "Invalid function call " << words << std::endl
	<< "expected:  ./convert  literal  ('c', 42, 5.0f, -5.6)" << std::endl;
	return -1;
}

int main(int argc, char const *argv[]) {

	if (argc < 2)
		return displayError("missing an argument");
	else if (argc > 2)
		return displayError("too many arguments");
	ScalarConverter::convert(argv[1]);
	return 0;
}
