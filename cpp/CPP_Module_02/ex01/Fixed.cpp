/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:26:19 by msapin            #+#    #+#             */
/*   Updated: 2023/09/18 13:28:18 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(void) : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const numInt) {

	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(numInt << Fixed::_fractBits);
}

Fixed::Fixed(float const numFloat) {

	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(numFloat * (1 << Fixed::_fractBits)));
}

Fixed::Fixed(Fixed const & src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const {
	return (float)this->getRawBits() / (1 << Fixed::_fractBits);
}

int	Fixed::toInt(void) const {
	return this->getRawBits() >> Fixed::_fractBits;
}

int Fixed::getRawBits(void) const {
	return this->_rawBits;
}

void    Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
}

std::ostream &  operator<<(std::ostream & o, Fixed const & i) {

	o << i.toFloat();
	return o;
}
