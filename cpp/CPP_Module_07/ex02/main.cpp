/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:14:21 by msapin            #+#    #+#             */
/*   Updated: 2023/11/22 18:49:38 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void	displayValue(Array<T> & array, int index) {

	try
	{
		std::cout << "array(" << index << "): " << array[index] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

template<typename T>
void	displayValue(Array<T> const & array, int index) {

	try
	{
		std::cout << "array(" << index << "): " << array[index] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	displayValue(int * & array, int index) {

	try
	{
		std::cout << "array(" << index << "): " << array[index] << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

template<typename T>
void displayMultipleIndex(Array<T> & array) {
	
	int  arrayIndex[7] = {0, 100, 34, 87, 18, 91, 50};

	for (int i = 0; i < 7; i++)
		displayValue(array, arrayIndex[i]);
}

template<typename T>
void displayMultipleIndex(Array<T> const & array) {

	int  arrayIndex[7] = {0, 100, 34, 87, 18, 91, 50};

	for (int i = 0; i < 7; i++)
		displayValue(array, arrayIndex[i]);
}

void displayMessage(std::string msg) {
	std::cout << std::endl << std::endl << YELLOW << BOLD << msg << RESET << std::endl << std::endl;
}

class TestClass {

	public:
		TestClass(void) : _name("NameTest") {};
		std::string const & getName(void) const {return this->_name;};

	private:
		std::string _name;
};

std::ostream & operator<<(std::ostream & o, TestClass const & i) {
	o << i.getName();
	return o;
}

void	displayTest(void);

int	main(void) {

	// {
	// 	std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY INT" << RESET;
	// 	displayMessage("Create empty int array using template and display some index");
	// 	Array<int> arrayIntTemplate;

	// 	displayMultipleIndex(arrayIntTemplate);

	// 	displayMessage("Create empty int array using standard new and display index 0");
	// 	int * arrayIntNew = new int();

	// 	displayValue(arrayIntNew, 0);
	// 	// displayValue(arrayIntNew, 1); // other index will create invalid read error with valgrind
	// 	delete arrayIntNew;

	// 	displayMessage("Create int array full and display some index");
	// 	Array<int> arrayIntFull(101);

	// 	for (int i = 0; i <= 100; i++)
	// 		arrayIntFull[i] = i;
	// 	displayMultipleIndex(arrayIntFull);

	// 	displayMessage("Create int array by copy of arrayIntFull and display index");
	// 	Array<int> arrayIntCopy(arrayIntFull);
	// 	displayMultipleIndex(arrayIntCopy);

	// 	displayMessage("Create int array init a zero than use assignment operator");
	// 	Array<int> arrayIntZero(101);
	// 	for (int i = 0; i <= 100; i++)
	// 		arrayIntZero[i] = 0;
	// 	std::cout << BLACK << "arrayIntZero: before assignment" << RESET << std::endl;
	// 	displayMultipleIndex(arrayIntZero);
	// 	arrayIntZero = arrayIntFull;

	// 	std::cout << std::endl << BLACK << "arrayIntZero: after assignment" << RESET << std::endl;
	// 	displayMultipleIndex(arrayIntZero);

	// 	displayMessage("Set all var of arrayIntFull to 42 than display arrayIntCopy and arrayIntZero");
	// 	for (int i = 0; i <= 100; i++)
	// 		arrayIntFull[i] = 42;

	// 	std::cout << BLACK << "arrayIntFull:" << RESET << std::endl;
	// 	displayMultipleIndex(arrayIntFull);
	// 	std::cout << std::endl << BLACK << "arrayIntCopy:" << RESET << std::endl;
	// 	displayMultipleIndex(arrayIntCopy);
	// 	std::cout << std::endl << BLACK << "arrayIntZero:" << RESET << std::endl;
	// 	displayMultipleIndex(arrayIntZero);

	// 	displayMessage("Trigger invalid index");
	// 	displayValue(arrayIntFull, -1);
	// 	displayValue(arrayIntFull, 1000);
	// }

	// {
	// 	std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY DOUBLE" << RESET;
	// 	displayMessage("Create double array using template and display some index");

	// 	Array<double> arrayDoubleTemplate(101);
	// 	double tmpNum = 0.35;
	// 	for (int i = 0; i <= 100; i++)
	// 	{
	// 		arrayDoubleTemplate[i] = tmpNum;
	// 		tmpNum++;
	// 	}
	// 	displayMultipleIndex(arrayDoubleTemplate);

	// 	displayMessage("Trigger invalid index");
	// 	displayValue(arrayDoubleTemplate, -1);
	// 	displayValue(arrayDoubleTemplate, 1000);
	// }

	// {
	// 	std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY STRING" << RESET;
	// 	displayMessage("Create string array using template and display some index");

	// 	Array<std::string> arrayStringTemplate(101);
	// 	for (int i = 0; i <= 100; i++)
	// 	{
	// 		std::ostringstream oss;
	// 		oss << i;

	// 		std::string tmpString = "Sentence " + oss.str();
	// 		arrayStringTemplate[i] = tmpString;
	// 	}
	// 	displayMultipleIndex(arrayStringTemplate);

	// 	displayMessage("Trigger invalid index");
	// 	displayValue(arrayStringTemplate, -1);
	// 	displayValue(arrayStringTemplate, 1000);
	// }

	// {
	// 	std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY TestClass" << RESET;
	// 	displayMessage("Create TestClass array using template and display some index");

	// 	Array<TestClass> arrayClassTemplate(101);

	// 	displayMultipleIndex(arrayClassTemplate);

	// 	displayMessage("Trigger invalid index");
	// 	displayValue(arrayClassTemplate, -1);
	// 	displayValue(arrayClassTemplate, 1000);
	// }

	// {
	// 	std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY CONST TestClass" << RESET;
	// 	displayMessage("Create const class array using template and display some index");

	// 	const Array<TestClass> arrayConstClass(101);

	// 	displayMultipleIndex(arrayConstClass);

	// 	displayMessage("Trigger invalid index");
	// 	displayValue(arrayConstClass, -1);
	// 	displayValue(arrayConstClass, 1000);
	// }

	// {
	// 	std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY using UNSIGNED INT" << RESET;
	// 	displayMessage("Create int array using template unsigned int and display last element");

	// 	unsigned int unsignedIndex = 2147483648;
	// 	try
	// 	{
	// 		Array<int> arrayUnsigned(unsignedIndex);

	// 		arrayUnsigned[unsignedIndex - 1] = 45;
	// 		std::cout << arrayUnsigned[unsignedIndex - 1] << std::endl;	
	// 	}
	// 	catch (std::exception & e)
	// 	{
	// 		std::cout << RED << BOLD << "Error: " << RESET << e.what() << std::endl;
	// 	}
	// }

	{
		std::cout << std::endl << std::endl << GREEN << BOLD << "TESTS - ARRAY using negative N" << RESET;
		displayMessage("Trying create int array using invalid N");

		Array<int> arrayUnsigned(-1);
		// try
		// {
		// 	Array<int> arrayUnsigned(-1);
		// }
		// catch (std::exception & e)
		// {
		// 	std::cout << RED << BOLD << "Error: " << RESET << e.what() << std::endl;
		// }
	}
	return 0;
}
