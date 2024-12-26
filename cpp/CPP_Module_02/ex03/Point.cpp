/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:41:12 by msapin            #+#    #+#             */
/*   Updated: 2023/09/01 19:03:23 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Point const & toCopy) : _x(toCopy.getFloatX()), _y(toCopy.getFloatY()) {}

Point::~Point(void) {}

Point &	Point::operator=(Point const & rhs) {
	
	if (this != &rhs)
		*this = rhs;
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Point const & i) {

	o << "x: " << i.getFloatX() << ", y: " << i.getFloatY();
	return o;
}

int	Point::getRawX(void) const {
	return this->_x.getRawBits();
}

float	Point::getFloatX(void) const {
	return this->_x.toFloat();
}

int	Point::getRawY(void) const {
	return this->_y.getRawBits();
}

float	Point::getFloatY(void) const {
	return this->_y.toFloat();
}
