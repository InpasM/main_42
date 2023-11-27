/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:44:48 by msapin            #+#    #+#             */
/*   Updated: 2023/11/06 15:14:49 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) {

	std::vector<int> vectorOne;
	for (int i = 1; i <= 50; i++)
		vectorOne.push_back(i);

	int numToAdd[] = {0, 1, 2, 8, 23, 35, 17, 6, 42, 50, 70, 90, -5};
	int sizeArray = sizeof(numToAdd) / sizeof(int);
	std::vector<int> numToFound;
	for (int i = 0; i < sizeArray; i++)
		numToFound.push_back(numToAdd[i]);
	
	std::cout << std::endl << GREEN << BOLD << "TESTS easyfind() with vector of int" << std::endl << std::endl;
	std::vector<int>::iterator it;
	for (it = numToFound.begin(); it != numToFound.end(); it++)
	{
		try
		{
			std::cout << BLACK << "INT to found " << *it << ": " << RESET;
			std::cout << GREEN << BOLD << *easyfind(vectorOne, *it) << std::endl;
		}
		catch(const IntNotFoundException & e)
		{
			std::cout << RED << BOLD << e.what() << RESET << std::endl;
		}
	}
	return 0;
}
