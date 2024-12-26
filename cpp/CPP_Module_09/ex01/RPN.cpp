/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:56:46 by msapin            #+#    #+#             */
/*   Updated: 2023/11/14 21:59:42 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	whichOperator(char elem) {
	
	char operators[] = {'+', '-', '/', '*'};

	for (int i = 0; i < 4; i++)
		if (elem == operators[i])
			return i;
	return -1;
}

RPN::RPN(std::string const & arg) {

	for (unsigned int i = 0; i < arg.size(); i ++)
	{
		if (arg[i] && isDigit(arg[i]))
			this->_numberStack.push(arg[i] - 48);
		else if (arg[i] && isOperator(arg[i]))
			this->_operatorStack.push(whichOperator(arg[i]));
	}
}

RPN::RPN(RPN const & copy) {
	*this = copy;
}

RPN::~RPN(void) {}

RPN & RPN::operator=(RPN const & src) {

	if (this != &src)
	{
		this->_numberStack = src._numberStack;
		this->_operatorStack = src._operatorStack;
	}
	return *this;
}

bool RPN::isValid(void) const {

	if (this->_numberStack.size() < 2)
		return displayError(2), false;
	else if (this->_operatorStack.size() < 1)
		return displayError(3), false;
	else if (this->_numberStack.size() < this->_operatorStack.size() + 1)
		return displayError(4), false;
	else if (this->_numberStack.size() > this->_operatorStack.size() + 1)
		return displayError(5), false;
	return true;
}

static long long addition(long long result, int number) {
	return result + number;
}

static long long subtraction(long long result, int number) {
	return result - number;
}

static long long division(long long result, int number) {
	return result / number;
}

static long long multiplication(long long result, int number) {
	return result * number;
}

void	RPN::displayResult(void) {

	long long (*func[4])(long long result, int number) = 
		{addition, subtraction, division, multiplication};
	long long result = this->_numberStack.top();

	while (this->_operatorStack.size() > 0)
	{
		this->_numberStack.pop();
		result = (*func[this->_operatorStack.top()])(result, this->_numberStack.top());
		this->_operatorStack.pop();
	}
	std::cout << "result: " << result << std::endl;
}
