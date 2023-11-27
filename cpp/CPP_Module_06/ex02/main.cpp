/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:25:12 by msapin            #+#    #+#             */
/*   Updated: 2023/10/27 15:49:05 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	displayMessage(const std::string sentence) {
	std::cout << std::endl << YELLOW << sentence << RESET << std::endl;
}

Base * generate(void) {
	
	srand(time(NULL));
	int randNum = rand() % 3;

	switch (randNum) {
		case 0:
			return std::cout << "generate: instance of A()" << std::endl, new A();
		case 1:
			return std::cout << "generate: instance of B()" << std::endl, new B();
		case 2:
			return std::cout << "generate: instance of C()" << std::endl, new C();
	}
	return new Base();
}

void identify(Base * p) {
	
	std::cout << "identify by pointer: ";
	if (A *a = dynamic_cast<A*>(p))
		std::cout << "found object A" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "found object B" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "found object C" << std::endl;
	else
		std::cout << "unidentifiable object" << std::endl;
}

void identify(Base & p) {

	std::cout << "identify by reference: ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "found object A" << std::endl;
	}
	catch (...) {}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "found object B" << std::endl;
	}
	catch (...) {}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "found object C" << std::endl;
	}
	catch (...) {}
}

int main(void) {

	std::cout << std::endl << GREEN << BOLD << "EX02 - Loop generate of A, B, C classes" << RESET << std::endl;

	for (int i = 1; i <= 10; i++)
	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "LOOP " << i << "/" << RESET;
		displayMessage("generate random class");
		Base* newBase = generate();

		displayMessage("use identify(Base * p)");
		identify(newBase);

		displayMessage("use identify(Base & p)");
		identify(*newBase);
		
		sleep(1);
		delete newBase;
	}
	return 0;
}
