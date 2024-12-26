/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:16:54 by msapin            #+#    #+#             */
/*   Updated: 2023/11/07 22:20:56 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _nbNumber(0) {
	this->_vectorNumber.reserve(0);
}

Span::Span(unsigned int n) : _nbNumber(n) {
	this->_vectorNumber.reserve(n);
}

Span::Span(Span const & copy) {
	*this = copy;
}

Span::~Span(void) {}

Span & Span::operator=(Span const & src) {

	if (this != &src)
	{
		this->_nbNumber = src._nbNumber;
		this->_vectorNumber = src._vectorNumber;
	}
	return *this;
}

void Span::addNumber(int toAdd) {

	if (this->_vectorNumber.size() == this->_nbNumber)
		throw CannotAddNumberException();
	else
		this->_vectorNumber.push_back(toAdd);
}

void Span::fillRange(std::vector<int>::iterator position, std::vector<int>::iterator start, std::vector<int>::iterator end) {

	if (std::distance(start, end) + this->_vectorNumber.size() > this->_nbNumber)
		throw CannotAddNumberException();
	this->_vectorNumber.insert(position, start, end);
}

void Span::fillSpan(void) {
	
	for (int i = 0; this->_vectorNumber.size() < this->_nbNumber; i++)
		this->_vectorNumber.push_back(i);
}

long	Span::shortestSpan(void) const {

	if (this->_vectorNumber.size() < 2)
		throw NotEnoughNumberException();
	std::vector<int> tmpVector = this->_vectorNumber;
	std::sort(tmpVector.begin(), tmpVector.end());
	long	shortest = static_cast<long>(tmpVector[1]) - static_cast<long>(tmpVector[0]);

	for (unsigned int i = 1; i + 1 < this->_vectorNumber.size(); i++)
	{
		long tmpShortest = static_cast<long>(tmpVector[i + 1]) - static_cast<long>(tmpVector[i]);
		
		if (tmpShortest < shortest)
			shortest = tmpShortest;
	}
	return shortest;
}

long	Span::longestSpan(void) const {

	if (this->_vectorNumber.size() < 2)
		throw NotEnoughNumberException();
	return static_cast<long>(*max_element(this->_vectorNumber.begin(), this->_vectorNumber.end())) - 
	static_cast<long>(*min_element(this->_vectorNumber.begin(), this->_vectorNumber.end()));
}

std::vector<int> & Span::getVector(void) {
	return this->_vectorNumber;
}

std::ostream & operator<<(std::ostream & o, Span & i) {
	std::vector<int>::iterator it;

	for (it = i.getVector().begin(); it != i.getVector().end(); it++)
		o << *it << std::endl;
	return o;
}
