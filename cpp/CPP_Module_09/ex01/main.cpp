/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:56:45 by msapin            #+#    #+#             */
/*   Updated: 2023/11/15 10:02:57 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void displayError(int index) {

	std::string error[] = {
		"function call. Expect:  ./RPN \"1 + 2 3 - + 4\"",
		"too many argument. Expect:  ./RPN \"1 + 2 3 - + 4\"",
		"missing number. Need at least two number and one operator.",
		"missing operator. Need at least two number and one operator.",
		"not enough number for that many operator.",
		"not enough operator for that many number.",
		"invalid character.",
		"invalid number. 0 -> 9 accepted.",
	};
	std::cout << RED << BOLD << "Error: " << RESET << error[index] << std::endl;
}

bool isDigit(char elem) {
	return (elem >= '0' && elem <= '9');
}

bool isOperator(char elem) {
	return (elem == '+' || elem == '-' || elem == '/' || elem == '*');
}

bool isArgValid(std::string const & arg) {

	for (unsigned int i = 0; i < arg.size(); i++)
	{
		if (!(arg[i] == ' ' || isDigit(arg[i]) || isOperator(arg[i])))
			return displayError(6), false;
		if (arg[i + 1] && isDigit(arg[i]) && isDigit(arg[i + 1]))
			return displayError(7), false;
	}
	return true;
}

int main(int argc, char * argv[]) {

	if (argc == 1)
		return displayError(0), -1;
	else if (argc > 2)
		return displayError(1), -1;
	std::string tmpArg = argv[1];
	std::string reverseArg(tmpArg.rbegin(), tmpArg.rend());

	if (isArgValid(reverseArg))
	{
		RPN polishNumber(reverseArg);
		
		if (polishNumber.isValid())
			polishNumber.displayResult();
	}
	return 0;
}
