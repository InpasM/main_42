/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:34:01 by msapin            #+#    #+#             */
/*   Updated: 2023/11/20 12:41:19 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const & copy) {
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {

	if (this != &src)
		*this = src;
	return *this;
}

void ScalarConverter::convert(std::string const & literal) {
	
	toChar(literal);
	toInt(literal);
	toFloat(literal);
	toDouble(literal);
}

static bool isImpossible(std::string const & literal) {

	int numberDot = 0;

	for (size_t i = 0; i < literal.size(); i++)
	{
		if (literal[i] == '.')
			numberDot++;
		else if (!std::isdigit(literal[i]) && i > 0 && !(i == literal.size() - 1 && literal[i] == 'f'))
			return true;
	}
	if (numberDot > 1)
		return true;
	return false;
}

bool ScalarConverter::isSpecial(std::string const & literal, int type) {

	std::string specialCases[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++)
	{
		if (literal == specialCases[i])
		{
			if (type == CHAR || type == INT)
				return std::cout << "impossible" << std::endl, true;
			else if (i < 3 && type == DOUBLE)
			{
				std::string cutLiteral = literal;
				return std::cout << cutLiteral.erase(literal.size() - 1, 1) << std::endl, true;
			}
			else if (i > 2 && type == FLOAT)
				return std::cout << literal << "f" << std::endl, true;
			return std::cout << literal << std::endl, true;
		}
	}
	if (isImpossible(literal))
		return std::cout << "impossible" << std::endl, true;
	return false;
}

void ScalarConverter::toChar(std::string const & literal) {

	std::cout << "char: ";
	if (isSpecial(literal, CHAR))
		return ;
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		std::cout << "'" << static_cast<char>(literal[0]) << "'";
	else
	{
		std::istringstream iss(literal);
		int c;

		iss >> c;
		if (c < 32 || c > 126)
		{
			if ((c == 0 && literal.size() > 1) || c > 127)
				std::cout << "impossible";
			else
				std::cout << "Non displayable";
		}
		else
			std::cout << "'" << static_cast<char>(c) << "'";
	}
	std::cout << std::endl;
}

void ScalarConverter::toInt(std::string const & literal) {
	
	std::cout << "int: ";
	if (isSpecial(literal, INT))
		return ;
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		std::cout << static_cast<int>(literal[0]) << std::endl;
	else
	{
		std::istringstream iss(literal);
		long long number;

		iss >> number;
		if (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(number) << std::endl;
	}
}

void ScalarConverter::toFloat(std::string const & literal) {

	std::cout << "float: ";
	if (isSpecial(literal, FLOAT))
		return ;
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		std::cout << static_cast<int>(literal[0]) << ".0f" << std::endl;
	else
	{
		std::istringstream iss(literal);
		long double number;

		iss >> number;
		if (number < -std::numeric_limits<float>::max() || number > std::numeric_limits<float>::max())
			std::cout << "impossible" << std::endl;
		else if (static_cast<double>(number) - static_cast<int>(number) == 0.0)
			std::cout << static_cast<double>(number) << ".0f" << std::endl;
		else
			std::cout << static_cast<double>(number) << "f" << std::endl;
	}
}

void ScalarConverter::toDouble(std::string const & literal) {

	std::cout << "double: ";
	if (isSpecial(literal, DOUBLE))
		return ;
	if (literal.size() == 1 && !std::isdigit(literal[0]))
		std::cout << static_cast<int>(literal[0]) << ".0" << std::endl;
	else
	{
		std::istringstream iss(literal);
		long double number;

		iss >> number;
		if (number < -std::numeric_limits<double>::max() || number > std::numeric_limits<double>::max())
			std::cout << "impossible" << std::endl;
		else if (static_cast<double>(number) - static_cast<int>(number) == 0.0)
			std::cout << static_cast<double>(number) << ".0" << std::endl;
		else
			std::cout << static_cast<double>(number) << std::endl;
	}
}
