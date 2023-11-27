/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:26:15 by msapin            #+#    #+#             */
/*   Updated: 2023/10/16 10:53:07 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	displayTitle(std::string title, int nbDash) {
	std::cout << std::endl << std::endl << "\033[1m\033[34m" << title << "  ";
	for (int i = 0; i <= nbDash; i++)
		std::cout << "-";
	std::cout << "\033[0m" << std::endl;
}

void	displayOperator(std::string sign) {
	std::cout << std::endl << "\033[1m\033[37m" << "Operator " << sign << "\033[0m" << std::endl;
}

void	displayComparison(Fixed const & numA, Fixed const & numB, std::string sentence) {
	std::cout << numA << " ( bits: " << numA.getRawBits() << " )" << sentence
	<< numB << " ( bits: " << numB.getRawBits() << " )" << std::endl;
}

void	compareIntFloat(Fixed const & aInt, Fixed const & bInt, Fixed const & aFloat, Fixed const & bFloat) {

	displayTitle("INT and FLOAT", 45);
	displayOperator(">");
	if (aFloat > bInt)
		displayComparison(aFloat, bInt, " is bigger than "); 
	displayOperator("<");
	if (bFloat < aInt)
		displayComparison(bFloat, aInt, " is smaller than ");
	displayOperator(">=");
	if (aFloat >= bInt)
		displayComparison(aFloat, bInt, " is bigger or equal than ");
	if (aFloat >= aInt)
		displayComparison(aFloat, aInt, " is bigger or equal than "); 
	displayOperator("<=");
	if (bInt <= aFloat)
		displayComparison(bFloat, aFloat, " is smaller or equal than ");
	if (bInt <= bFloat)
		displayComparison(bFloat, bFloat, " is smaller or equal than ");
	displayOperator("==");
	if (bFloat == bInt)
		displayComparison(bFloat, bInt, " equals ");
	else
		displayComparison(bFloat, bInt, " is not equal ");
	displayOperator("!=");
	if (aFloat != aInt)
		displayComparison(aFloat, aInt, " is not equal ");
}

void	compareInt(Fixed const & aInt, Fixed const & bInt) {

	displayTitle("INT", 55);
	displayOperator(">");
	if (aInt > bInt)
		displayComparison(aInt, bInt, " is bigger than ");
	displayOperator("<");
	if (bInt < aInt)
		displayComparison(bInt, aInt, " is smaller than ");
	displayOperator(">=");
	if (aInt >= bInt)
		displayComparison(aInt, bInt, " is bigger or equal than ");
	if (aInt >= aInt)
		displayComparison(aInt, aInt, " is bigger or equal than ");
	displayOperator("<=");
	if (bInt <= aInt)
		displayComparison(bInt, aInt, " is smaller or equal than ");
	if (bInt <= bInt)
		displayComparison(bInt, bInt, " is smaller or equal than ");
	displayOperator("==");
	if (bInt == bInt)
		displayComparison(bInt, bInt, " equals ");
	displayOperator("!=");
	if (aInt != bInt)
		displayComparison(aInt, bInt, " is not equal ");
}

void	compareFloat(Fixed const & aFloat, Fixed const & bFloat) {

	displayTitle("FLOAT", 53);
	displayOperator(">");
	if (aFloat > bFloat)
		displayComparison(aFloat, bFloat, " is bigger than ");
	displayOperator("<");
	if (bFloat < aFloat)
		displayComparison(bFloat, aFloat, " is smaller than ");
	displayOperator(">=");
	if (aFloat >= bFloat)
		displayComparison(aFloat, bFloat, " is bigger or equal than ");
	if (aFloat >= aFloat)
		displayComparison(aFloat, aFloat, " is bigger or equal than ");
	displayOperator("<=");
	if (bFloat <= aFloat)
		displayComparison(bFloat, aFloat, " is smaller or equal than ");
	if (bFloat <= bFloat)
		displayComparison(bFloat, bFloat, " is smaller or equal than ");
	displayOperator("==");
	if (bFloat == bFloat)
		displayComparison(bFloat, bFloat, " equals ");
	displayOperator("!=");
	if (aFloat != bFloat)
		displayComparison(aFloat, bFloat, " is not equal ");
}

void	arithmetic(Fixed const & aFixed, Fixed const & bFixed) {

	displayOperator("+");
	std::cout << aFixed << " + " << bFixed << " = " << aFixed + bFixed << "  |  bits: "
	<< aFixed.getRawBits() << " + " << bFixed.getRawBits() << " = "
	<< aFixed.getRawBits() + bFixed.getRawBits() << std::endl;
	std::cout << aFixed << " + " << bFixed << " + " << aFixed << " + " << bFixed
	<< " = " << aFixed + bFixed + aFixed + bFixed << std::endl;
	
	displayOperator("-");
	std::cout << aFixed << " - " << bFixed << " = " << aFixed - bFixed << "  |  bits: "
	<< aFixed.getRawBits() << " - " << bFixed.getRawBits() << " = "
	<< aFixed.getRawBits() - bFixed.getRawBits() << std::endl;
	std::cout << aFixed << " - " << bFixed << " - " << aFixed << " - " << bFixed
	<< " = " << aFixed - bFixed - aFixed - bFixed << std::endl;
	
	displayOperator("*");
	std::cout << aFixed << " * " << bFixed << " = " << aFixed * bFixed << "  |  bits: "
	<< aFixed.getRawBits() << " * " << bFixed.getRawBits() << " = "
	<< aFixed.getRawBits() * bFixed.getRawBits() << std::endl;
	std::cout << aFixed << " * " << bFixed << " * " << aFixed << " * " << bFixed
	<< " = " << aFixed * bFixed * aFixed * bFixed << std::endl;
	
	displayOperator("/");
	std::cout << aFixed << " / " << bFixed << " = " << aFixed / bFixed << "  |  bits: "
	<< aFixed.getRawBits() << " / " << bFixed.getRawBits() << " = "
	<< aFixed.getRawBits() / bFixed.getRawBits() << std::endl;
	std::cout << aFixed << " / " << bFixed << " / " << aFixed << " / " << bFixed
	<< " = " << aFixed / bFixed / aFixed / bFixed << std::endl;
}

void	increment(Fixed & aInt, Fixed & bInt, Fixed & aFloat, Fixed & bFloat) {
	
	displayTitle("INT", 55);
	displayOperator("++int");
	std::cout << "number before: " << aInt << std::endl << "pre increment: "
	<< ++aInt << std::endl << "after: " << aInt << std::endl;

	displayOperator("int++");
	std::cout << "number before: " << bInt << std::endl << "post increment: "
	<< bInt++ << std::endl << "after: " << bInt << std::endl;


	displayTitle("FLOAT", 55);
	displayOperator("++float");
	std::cout << "number before: " << aFloat << std::endl << "pre increment: "
	<< ++aFloat << std::endl << "after: " << aFloat << std::endl;

	displayOperator("float++");
	std::cout << "number before: " << bFloat << std::endl << "post increment: "
	<< bFloat++ << std::endl << "after: " << bFloat << std::endl;
}

void	decrement(Fixed & aInt, Fixed & bInt, Fixed & aFloat, Fixed & bFloat) {
	
	displayTitle("INT", 55);
	displayOperator("--int");
	std::cout << "number before: " << aInt << std::endl << "pre increment: "
	<< --aInt << std::endl << "after: " << aInt << std::endl;

	displayOperator("int--");
	std::cout << "number before: " << bInt << std::endl << "post increment: "
	<< bInt-- << std::endl << "after: " << bInt << std::endl;


	displayTitle("FLOAT", 55);
	displayOperator("--float");
	std::cout << "number before: " << aFloat << std::endl << "pre increment: "
	<< --aFloat << std::endl << "after: " << aFloat << std::endl;

	displayOperator("float--");
	std::cout << "number before: " << bFloat << std::endl << "post increment: "
	<< bFloat-- << std::endl << "after: " << bFloat << std::endl;
}

void	minMax(Fixed & aNum, Fixed & bNum, Fixed const & aNumConst, Fixed const & bNumConst) {
	
	std::cout << "non const: " << aNum << " vs " << bNum << "  -  min is "
	<< Fixed::min(aNum, bNum) << std::endl;
	std::cout << "const: " << aNumConst << " vs " << bNumConst << "  -  min is "
	<< Fixed::min(aNumConst, bNumConst) << std::endl;
	std::cout << "non const: " << aNum << " vs " << bNum << "  -  max is "
	<< Fixed::max(aNum, bNum) << std::endl;
	std::cout << "const: " << aNumConst << " vs " << bNumConst << "  -  max is "
	<< Fixed::max(aNumConst, bNumConst) << std::endl;
}

int main(void) {

	Fixed aInt(15);
	Fixed bInt(10);
	Fixed aFloat(15.5f);
	Fixed bFloat(10.5f);

	Fixed const aIntConst(15);
	Fixed const bIntConst(10);
	Fixed const aFloatConst(15.5f);
	Fixed const bFloatConst(10.5f);

	std::cout << "\033[1m\033[33m"
	<< "                --  COMPARISON OPERATORS  --" << "\033[0m";
	compareInt(aInt, bInt);
	compareFloat(aFloat, bFloat);
	compareIntFloat(aInt, bInt, aFloat, bFloat);

	std::cout << std::endl << std::endl << "\033[1m\033[33m"
	<< "                --  ARITHMETIC OPERATORS  --" << "\033[0m";
	displayTitle("INT", 55);
	arithmetic(aInt, bInt);
	displayTitle("FLOAT", 52);
	arithmetic(aFloat, bFloat);

	std::cout << std::endl << std::endl << "\033[1m\033[33m"
	<< "                --  INCRE/DECRE OPERATORS  --" << "\033[0m";
	increment(aInt, bInt, aFloat, bFloat);
	decrement(aInt, bInt, aFloat, bFloat);

	std::cout << std::endl << std::endl << "\033[1m\033[33m"
	<< "                  --  MIN/MAX FUNCTIONS  --" << "\033[0m";
	displayTitle("INT", 55);
	minMax(aInt, bInt, aIntConst, bIntConst);
	displayTitle("FLOAT", 52);
	minMax(aFloat, bFloat, aFloatConst, bFloatConst);


	std::cout << std::endl << std::endl << "\033[1m\033[33m"
	<< "                   --  TESTS SUBJECT  --" << "\033[0m" << std::endl << std::endl;
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
