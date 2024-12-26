/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:49:53 by msapin            #+#    #+#             */
/*   Updated: 2023/11/15 15:19:45 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool    isDigit(char arg) {
	return (arg >= '0' && arg <= '9');
}

bool	isValidInt(char * arg) {

	int	i = -1;
	
	if (arg[0] == '-')
		return displayError(1, arg), false;
	while (arg[++i])
		if (!isDigit(arg[i]))
			return displayError(2, arg), false;
	if (i > 10)
		return displayError(3, arg), false;
	else if (i == 10)
	{
		std::string tmpString(arg);

		if (tmpString > "2147483647")
			return displayError(3, arg), false;
	}
	return true;
}

PmergeMe::PmergeMe(char * argv[]) : _validity(true) {

	for (int i = 1; argv[i]; i++)
	{
		if (isValidInt(argv[i]))
		{
			std::stringstream tmpStream(argv[i]);
			int tmpNumber;

			tmpStream >> tmpNumber;
			this->_intVector.push_back(tmpNumber);
			this->_intList.push_back(tmpNumber);
			// std::cout << "check: " << argv[i] << " tmpNumber: " << tmpNumber  << std::endl;
		}
		else
		{
			// std::cout << "Invalid: " << argv[i] << std::endl;
			this->_validity = false;
			break ;
		}
	}
}

PmergeMe::PmergeMe(PmergeMe const & copy) {
	*this = copy;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
	if (this != &src)
	{
		this->_intVector = src._intVector;
		this->_intList = src._intList;
		this->_validity = src._validity;
	}
	return *this;
}

std::ostream &	PmergeMe::displaySequence(std::ostream & o) const {
	
	std::vector<int>::const_iterator it;

	for (it = this->_intVector.begin(); it != this->_intVector.end(); it++)
		o<< " " << *it;
	return o;
}

std::ostream & operator<<(std::ostream & o, PmergeMe const & i) {
	return i.displaySequence(o);
}

bool PmergeMe::getValidity(void) const {
	return this->_validity;
}

#include <unistd.h>

void	PmergeMe::sortAll(void) {

	time_t start, end;

	time(&start);
	// clock_t timeBefore = std::clock();
	int timeBefore = std::clock();

	std::cout << "sorting..." << std::endl;
	// sleep(1);
	time(&end);

	// clock_t timeEnd = std::clock();
	int timeEnd = std::clock();
	// double time_taken = double(end - start); 
    // std::cout << "Time taken by program is : " << time_taken << std::endl; 

	// double tmp = (timeEnd - timeBefore) / double(CLOCKS_PER_SEC) * 1000;
	double tmp = (timeEnd - timeBefore) / double(CLOCKS_PER_SEC) * 1000000;
	// double tmp = (((float)timeBefore));
	// double tmp = ((float)timeBefore);
	// std::cout << "number click: " << time_taken << ".";	
	// if (tmp < 100)
	// 	std::cout << 0;
	std::cout << tmp << std::endl;	
}
