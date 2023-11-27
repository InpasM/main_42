/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:16:52 by msapin            #+#    #+#             */
/*   Updated: 2023/11/07 22:48:05 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void displayMessage(std::string msg) {
	std::cout << std::endl << YELLOW << BOLD << msg << RESET << std::endl;
}

int main(void) {

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - Basics" << RESET << std::endl;

		displayMessage("Creating default Span and try to add a number");
		Span emptySpan;
		try
		{
			emptySpan.addNumber(20);
		}
		catch(const std::exception& e)
		{
			std::cout << RED << BOLD << e.what() << RESET << std::endl;
		}

		displayMessage("Creating overloaded Span, add few numbers and display content");
		Span fiveSpan(5);
		try
		{
			fiveSpan.addNumber(20);
			fiveSpan.addNumber(1);
			fiveSpan.addNumber(180);
			fiveSpan.addNumber(52);
			fiveSpan.addNumber(17);
		}
		catch(const std::exception& e)
		{
			std::cout << RED << BOLD << e.what() << RESET << std::endl;
		}
		std::cout << fiveSpan;

		displayMessage("Creating copy of last Span and display content");
		Span copySpan(fiveSpan);
		std::cout << copySpan;

		displayMessage("Using assignment operator to copy fiveSpan into emptySpan and display content");
		emptySpan = fiveSpan;
		std::cout << emptySpan;

		displayMessage("Replacing all five number of fiveSpan by zero and display all copies");
		std::vector<int>::iterator it;
		for (it = fiveSpan.getVector().begin(); it != fiveSpan.getVector().end(); it++)
			*it = 0;

		std::cout << std::endl << BLACK << BOLD << "fiveSpan:" << RESET << std::endl << fiveSpan;
		std::cout << std::endl << BLACK << BOLD << "copySpan:" << RESET << std::endl << copySpan;
		std::cout << std::endl << BLACK << BOLD << "emptySpan:" << RESET << std::endl << emptySpan;

		displayMessage("Try to add an extra number to fiveSpan already full");
		try
		{
			fiveSpan.addNumber(99);
		}
		catch(const std::exception& e)
		{
			std::cout << RED << BOLD << e.what() << RESET << std::endl;
		}
	}

	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - shortestSpan() / longestSpan()" << RESET << std::endl;
		Span classicSpan(10);

		displayMessage("Try shortestSpan() / longestSpan() on empty span");

		try
		{
			std::cout << "shortestSpan: " << classicSpan.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << RED << BOLD << e.what() << RESET << std::endl;
		}
		try
		{
			std::cout << "longestSpan: " << classicSpan.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << RED << BOLD << e.what() << RESET << std::endl;
		}

		displayMessage("Try shortestSpan() / longestSpan() after added number to span");
		classicSpan.addNumber(364);
		classicSpan.addNumber(2);
		classicSpan.addNumber(18);
		classicSpan.addNumber(1000);
		classicSpan.addNumber(187);
		classicSpan.addNumber(65);
		classicSpan.addNumber(587);
		classicSpan.addNumber(765);
		classicSpan.addNumber(1);
		classicSpan.addNumber(3468);

		std::cout << "shortestSpan: " << classicSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << classicSpan.longestSpan() << std::endl;

		displayMessage("Try shortestSpan() / longestSpan() on extreme value");
		Span extremeSpan(3);

		extremeSpan.addNumber(-2147483648);
		extremeSpan.addNumber(2147483647);

		std::cout << "shortestSpan: " << extremeSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << extremeSpan.longestSpan() << std::endl;

		displayMessage("Add an extra number in extremeSpan");
		extremeSpan.addNumber(-2000000000);

		displayMessage("Try shortestSpan() / longestSpan() again");

		std::cout << "shortestSpan: " << extremeSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << extremeSpan.longestSpan() << std::endl << std::endl;
	}

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - Big span" << RESET << std::endl;
		displayMessage("Creating a span with 100000 of size and filling it");
		Span bigSpan(100000);

		bigSpan.fillSpan();

		displayMessage("Try shortestSpan() / longestSpan() on it");
		std::cout << "shortestSpan: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "longestSpan: " << bigSpan.longestSpan() << std::endl << std::endl;
	}

	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - fillRange" << RESET << std::endl;

		displayMessage("Creating a Span and filling it with fillRange and a vector");
		std::vector<int> fillVector;
		Span fillSpan(25);

		for (int i = 25; i > 0; i--)
			fillVector.push_back(i);

		fillSpan.fillRange(fillSpan.getVector().begin(), fillVector.begin(), fillVector.end());
		std::cout << fillSpan << std::endl;
	}

	{
		std::cout << std::endl << GREEN << BOLD << "TESTS - subject" << RESET << std::endl;
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}
