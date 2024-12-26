/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:26:19 by msapin            #+#    #+#             */
/*   Updated: 2023/09/18 13:38:10 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(int const numInt) {
	this->setRawBits(numInt << Fixed::_fractBits);
}

Fixed::Fixed(float const numFloat) {
	this->setRawBits(roundf(numFloat * (1 << Fixed::_fractBits)));
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

Fixed::~Fixed(void) {}

Fixed & Fixed::operator=(Fixed const & rhs) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const & rhs) const{

	Fixed result(this->toFloat() + rhs.toFloat());
	return result;
}

Fixed	Fixed::operator-(Fixed const & rhs) const{

	Fixed result(this->toFloat() - rhs.toFloat());
	return result;
}

Fixed	Fixed::operator*(Fixed const & rhs) const{

	Fixed result(this->toFloat() * rhs.toFloat());
	return result;
}

Fixed	Fixed::operator/(Fixed const & rhs) const{

	Fixed result(this->toFloat() / rhs.toFloat());
	return result;
}

Fixed &	Fixed::operator++(void) {

	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int) {

	Fixed	tmp(this->toFloat());
	++*this;
	return tmp;
}

Fixed &	Fixed::operator--(void) {

	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int) {

	Fixed	tmp(this->toFloat());
	--*this;
	return tmp;
}

Fixed & Fixed::min(Fixed & lfs, Fixed & rfs) {

	if (lfs < rfs)
		return (lfs);
	else
		return (rfs);
}

Fixed const & Fixed::min(Fixed const & lfs, Fixed const & rfs) {
	
	if (lfs < rfs)
		return (lfs);
	else
		return (rfs);
}

Fixed & Fixed::max(Fixed & lfs, Fixed & rfs) {
	
	if (lfs > rfs)
		return (lfs);
	else
		return (rfs);
}

Fixed const & Fixed::max(Fixed const & lfs, Fixed const & rfs) {
	
	if (lfs > rfs)
		return (lfs);
	else
		return (rfs);
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
