/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:06:42 by msapin            #+#    #+#             */
/*   Updated: 2023/11/21 20:01:29 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

void    displayMessage(std::string message) {
	std::cout << std::endl << YELLOW << BOLD << message << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - INT" << RESET << std::endl;
		int firstInt = 50;
		int secondInt = 12;
		int thirdInt = 50;

		displayMessage("Trying SWAP implicit ( int )");
		std::cout << "BEFORE swap implicit" << std::endl << "firstInt: " << firstInt << " - secondInt: " << secondInt << std::endl << std::endl;
		::swap(firstInt, secondInt);
		std::cout << "AFTER swap implicit" << std::endl << "firstInt: " << firstInt << " - secondInt: " << secondInt << std::endl;
		
		displayMessage("Trying SWAP explicit ( int )");
		std::cout << "BEFORE swap explicit" << std::endl << "firstInt: " << firstInt << " - secondInt: " << secondInt << std::endl << std::endl;
		::swap<int>(firstInt, secondInt);
		std::cout << "AFTER swap explicit" << std::endl << "firstInt: " << firstInt << " - secondInt: " << secondInt << std::endl;
	
		displayMessage("Trying MIN implicit ( int ) 50 / 12");
		std::cout
		<< "firstInt  (" << firstInt << "): " << &firstInt << std::endl
		<< "secondInt (" << secondInt << "): " << &secondInt << std::endl << BOLD << GREEN
		<< "min       (" << ::min(firstInt, secondInt) << "): " << &::min(firstInt, secondInt) << std::endl;
	
		displayMessage("Trying MIN explicit ( int ) 50 / 50");
		std::cout
		<< "firstInt  (" << firstInt << "): " << &firstInt << std::endl
		<< "thirdInt  (" << thirdInt << "): " << &thirdInt << std::endl << BOLD << GREEN
		<< "min       (" << ::min<int>(firstInt, thirdInt) << "): " << &::min<int>(firstInt, thirdInt) << std::endl;
	
		displayMessage("Trying MAX implicit ( int ) 50 / 12");
		std::cout
		<< "firstInt  (" << firstInt << "): " << &firstInt << std::endl
		<< "secondInt (" << secondInt << "): " << &secondInt << std::endl << BOLD << GREEN
		<< "max       (" << ::max(firstInt, secondInt) << "): " << &::max(firstInt, secondInt) << std::endl;
	
		displayMessage("Trying MAX explicit ( int ) 50 / 50");
		std::cout
		<< "firstInt  (" << firstInt << "): " << &firstInt << std::endl
		<< "thirdInt  (" << thirdInt << "): " << &thirdInt << std::endl << BOLD << GREEN
		<< "max       (" << ::max<int>(firstInt, thirdInt) << "): " << &::max<int>(firstInt, thirdInt) << std::endl;
	}

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - FLOAT" << RESET << std::endl;
		float firstFloat = 50.5f;
		float secondFloat = 12.78f;
		float thirdFloat = 50.5f;

		displayMessage("Trying SWAP implicit ( float )");
		std::cout << "BEFORE swap implicit" << std::endl << "firstFloat: " << firstFloat << " - secondFloat: " << secondFloat << std::endl << std::endl;
		::swap(firstFloat, secondFloat);
		std::cout << "AFTER swap implicit" << std::endl << "firstFloat: " << firstFloat << " - secondFloat: " << secondFloat << std::endl;
		
		displayMessage("Trying SWAP explicit ( float )");
		std::cout << "BEFORE swap explicit" << std::endl << "firstFloat: " << firstFloat << " - secondFloat: " << secondFloat << std::endl << std::endl;
		::swap<float>(firstFloat, secondFloat);
		std::cout << "AFTER swap explicit" << std::endl << "firstFloat: " << firstFloat << " - secondFloat: " << secondFloat << std::endl;
	
		displayMessage("Trying MIN implicit ( float ) 50.5f / 12.78f");
		std::cout
		<< "firstFloat  (" << firstFloat << "): " << &firstFloat << std::endl
		<< "secondFloat (" << secondFloat << "): " << &secondFloat << std::endl << BOLD << GREEN
		<< "min         (" << ::min(firstFloat, secondFloat) << "): " << &::min(firstFloat, secondFloat) << std::endl;
	
		displayMessage("Trying MIN explicit ( float ) 50.5f / 50.5f");
		std::cout
		<< "firstFloat  (" << firstFloat << "): " << &firstFloat << std::endl
		<< "thirdFloat  (" << thirdFloat << "): " << &thirdFloat << std::endl << BOLD << GREEN
		<< "min         (" << ::min<float>(firstFloat, thirdFloat) << "): " << &::min<float>(firstFloat, thirdFloat) << std::endl;
	
		displayMessage("Trying MAX implicit ( float ) 50.5f / 12.78f");
		std::cout
		<< "firstFloat  (" << firstFloat << "): " << &firstFloat << std::endl
		<< "secondFloat (" << secondFloat << "): " << &secondFloat << std::endl << BOLD << GREEN
		<< "max         (" << ::max(firstFloat, secondFloat) << "): " << &::max(firstFloat, secondFloat) << std::endl;
	
		displayMessage("Trying MAX explicit ( float ) 50.5f / 50.5f");
		std::cout
		<< "firstFloat  (" << firstFloat << "): " << &firstFloat << std::endl
		<< "thirdFloat  (" << thirdFloat << "): " << &thirdFloat << std::endl << BOLD << GREEN
		<< "max         (" << ::max<float>(firstFloat, thirdFloat) << "): " << &::max<float>(firstFloat, thirdFloat) << std::endl;
	}

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - STRING" << RESET << std::endl;
		std::string firstString = "First sentence";
		std::string secondString = "Second sentence";
		std::string thirdString = "First sentence";

		displayMessage("Trying SWAP implicit ( std::string )");
		std::cout << "BEFORE swap implicit" << std::endl << "firstString: " << firstString << " - secondString: " << secondString << std::endl << std::endl;
		::swap(firstString, secondString);
		std::cout << "AFTER swap implicit" << std::endl << "firstString: " << firstString << " - secondString: " << secondString << std::endl;
		
		displayMessage("Trying SWAP explicit ( std::string )");
		std::cout << "BEFORE swap explicit" << std::endl << "firstString: " << firstString << " - secondString: " << secondString << std::endl << std::endl;
		::swap<std::string>(firstString, secondString);
		std::cout << "AFTER swap explicit" << std::endl << "firstString: " << firstString << " - secondString: " << secondString << std::endl;
	
		displayMessage("Trying MIN implicit ( std::string )");
		std::cout
		<< "firstString  (" << firstString << "):  " << &firstString << std::endl
		<< "secondString (" << secondString << "): " << &secondString << std::endl << BOLD << GREEN
		<< "min          (" << ::min(firstString, secondString) << "):  " << &::min(firstString, secondString) << std::endl;
	
		displayMessage("Trying MIN explicit ( std::string )");
		std::cout
		<< "firstString  (" << firstString << "): " << &firstString << std::endl
		<< "thirdString  (" << thirdString << "): " << &thirdString << std::endl << BOLD << GREEN
		<< "min          (" << ::min<std::string>(firstString, thirdString) << "): " << &::min<std::string>(firstString, thirdString) << std::endl;
	
		displayMessage("Trying MAX implicit ( std::string )");
		std::cout
		<< "firstString  (" << firstString << "):  " << &firstString << std::endl
		<< "secondString (" << secondString << "): " << &secondString << std::endl << BOLD << GREEN
		<< "max          (" << ::max(firstString, secondString) << "): " << &::max(firstString, secondString) << std::endl;
	
		displayMessage("Trying MAX explicit ( std::string )");
		std::cout
		<< "firstString  (" << firstString << "): " << &firstString << std::endl
		<< "thirdString  (" << thirdString << "): " << &thirdString << std::endl << BOLD << GREEN
		<< "max          (" << ::max<std::string>(firstString, thirdString) << "): " << &::max<std::string>(firstString, thirdString) << std::endl;
	}

	// {
	// 	std::cout << std::endl << GREEN << BOLD << "TESTS - WRONG that will not compile" << RESET << std::endl;
	// 	int firstInt = 50;
	// 	int secondInt = 12;
	// 	float thirdFloat = 50.67f;
		
	// 	displayMessage("Trying SWAP explicit with wrong type");
	// 	swap<float>(firstInt, secondInt);

	// 	displayMessage("Trying SWAP implicit with two different type");
	// 	swap(firstInt, thirdFloat);
	// }

	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - SUBJECT" << RESET << std::endl;

		int a = 2;
		int b = 3;

		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
		std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	}
	return 0;
}
