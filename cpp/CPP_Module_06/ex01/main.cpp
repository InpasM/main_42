/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:47:38 by msapin            #+#    #+#             */
/*   Updated: 2023/11/20 12:59:34 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	displayMessage(const std::string sentence) {
	std::cout << std::endl << YELLOW << sentence << RESET << std::endl;
}

int main(void)
{
	Data* dataVar = new Data();
	Data dataVarStack;

	displayMessage("Assigning value to Data allocated than displaying it");
	dataVar->words = "dataVar words";
	dataVar->nbInt = 50;
	dataVar->nbFloat = 60.742f;
	dataVar->nbDouble = 80.5012;

	std::cout << "dataVar values:" << std::endl
	<< "words: " << dataVar->words << std::endl
	<< "nbInt: " << dataVar->nbInt << std::endl
	<< "nbFloat: " << dataVar->nbFloat << std::endl
	<< "nbDouble: " << dataVar->nbDouble << std::endl;

	displayMessage("Assigning value to Data than displaying it");
	dataVarStack.words = "dataVarStack words";
	dataVarStack.nbInt = 25;
	dataVarStack.nbFloat = 30.371f;
	dataVarStack.nbDouble = 40.2506;

	std::cout << "dataVarStack values:" << std::endl
	<< "words: " << dataVarStack.words << std::endl
	<< "nbInt: " << dataVarStack.nbInt << std::endl
	<< "nbFloat: " << dataVarStack.nbFloat << std::endl
	<< "nbDouble: " << dataVarStack.nbDouble << std::endl;

	displayMessage("Use serialize on dataVar than deserialize and display value");
	uintptr_t ptrDataVar = Serializer::serialize(dataVar);
	Data* newDataVar = Serializer::deserialize(ptrDataVar);

	std::cout << "newDataVar values:" << std::endl
	<< "words: " << newDataVar->words << std::endl
	<< "nbInt: " << newDataVar->nbInt << std::endl
	<< "nbFloat: " << newDataVar->nbFloat << std::endl
	<< "nbDouble: " << newDataVar->nbDouble << std::endl;

	displayMessage("Use serialize on dataVarStack than deserialize and display value");
	uintptr_t ptrDataVarStack = Serializer::serialize(&dataVarStack);
	Data* newDataVarStack = Serializer::deserialize(ptrDataVarStack);

	std::cout << "newDataVarStack values:" << std::endl
	<< "words: " << newDataVarStack->words << std::endl
	<< "nbInt: " << newDataVarStack->nbInt << std::endl
	<< "nbFloat: " << newDataVarStack->nbFloat << std::endl
	<< "nbDouble: " << newDataVarStack->nbDouble << std::endl;
	
	delete dataVar;
	return 0;
}
