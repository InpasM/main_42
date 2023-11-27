/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:49:52 by msapin            #+#    #+#             */
/*   Updated: 2023/11/15 15:27:15 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void    displayError(int index, char * elem) {

	std::string error[] = {
		"function call. Expect:  ./RPN  nb1  nb2  nb3  nb4 ... nbN",
		"invalid integer. Should be positive integer.",
		"invalid integer. Should only be numeric characters.",
		"invalid integer. Cannot exceed INT_MAX (2147483647).",
	};
	std::cout << RED << BOLD << "Error: " << RESET;
	if (elem)
		std::cout << elem << ": ";
	std::cout << error[index] << std::endl;
}

int main(int argc, char * argv[]) {

	if (argc == 1)
		return displayError(0, NULL), -1;
	PmergeMe	sequence(argv);

	if (sequence.getValidity())
	{
		std::cout << "Before:" << sequence << std::endl;

		sequence.sortAll();
		std::cout << "After: " << sequence << std::endl;
		
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector<int> : " << std::endl;
	}
	// else
	// 	std::cout << RED << BOLD << "Sequence is invalid" << RESET << std::endl;
	return 0;
}
