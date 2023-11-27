/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:49:24 by msapin            #+#    #+#             */
/*   Updated: 2023/11/22 17:39:50 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << YELLOW << BOLD << sentence << RESET << std::endl;
}

class TestClass {

	public:
		TestClass(void) : _name("NameTest") {};
		std::string const & getName(void) const {return this->_name;};

	private:
		std::string _name;
};

std::ostream & operator<<(std::ostream & o, TestClass const & i) {
	(void)i;
	o << i.getName();
	return o;
}

void increNumber(int & var) {var++;}
void increNumber(float & var) {var++;}
void increNumber(double & var) {var++;}

void toUpper(std::string & str) {
	if (str.empty())
		return ;
	str[0] = toupper(str[0]);
}

int main(void) {

	{
		std::cout << std::endl  << std::endl << GREEN << BOLD << "EX01 - TESTS INT" << std::endl;
		int intArray[] = {5, 20, 3, 68, 7};

		displayMessage("Display array of int using function displayArray");
		iter(intArray, 5, displayVar);
		iter(intArray, 5, increNumber);
		displayMessage("Display array of int after using function increNumber");
		iter(intArray, 5, displayVar);
	}

	{
		std::cout << std::endl  << std::endl << GREEN << BOLD << "EX01 - TESTS FLOAT" << std::endl;
		float floatArray[] = {5.58f, 20.63f, 3.0f, 68.87f, 7.95845f};

		displayMessage("Display array of float using function displayArray");
		iter(floatArray, 5, displayVar);
		iter(floatArray, 5, increNumber);
		displayMessage("Display array of float after using function increNumber");
		iter(floatArray, 5, displayVar);
	}

	{
		std::cout << std::endl  << std::endl << GREEN << BOLD << "EX01 - TESTS DOUBLE" << std::endl;
		double doubleArray[] = {5.580, 20.63, 3.0, 68.87, 7.95845};

		displayMessage("Display array of double using function displayArray");
		iter(doubleArray, 5, displayVar);
		iter(doubleArray, 5, increNumber);
		displayMessage("Display array of double after using function increNumber");
		iter(doubleArray, 5, displayVar);
	}

	{
		std::cout << std::endl  << std::endl << GREEN << BOLD << "EX01 - TESTS STRING" << std::endl;
		std::string strArray[] = {"first", "second", "third", "four", "five"};

		displayMessage("Display array of string using function displayArray");
		iter(strArray, 5, displayVar);

		displayMessage("Display array of string after use of toUpper");
		iter(strArray, 5, toUpper);
		iter(strArray, 5, displayVar);
	}

	{
		std::cout << std::endl  << std::endl << GREEN << BOLD << "EX01 - TESTS CLASS" << std::endl;
		TestClass* testArray = new TestClass[5];

		displayMessage("Display array of TestClass using displayArray and class operator<<");
		iter(testArray, 5, displayVar);
		delete [] testArray;
	}

	{
		std::cout << std::endl  << std::endl << GREEN << BOLD << "EX01 - TESTS INT CONST" << std::endl;
		const int intArray[] = {5, 20, 3, 68, 7};

		displayMessage("Display array of int using function displayArray");
		iter(intArray, 5, displayVar<const int>);
	}
	return 0;
}
