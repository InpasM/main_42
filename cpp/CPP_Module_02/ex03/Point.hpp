/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:41:17 by msapin            #+#    #+#             */
/*   Updated: 2023/10/16 10:50:24 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

#define X 1
#define Y 2

class	Point {

	public:
		Point(void);
		Point(float const x, float const y);
		Point(Point const & toCopy);
		~Point(void);

		Point &	operator=(Point const & rhs);

		int	getRawX(void) const;
		int	getRawY(void) const;
		
		float	getFloatX(void) const;
		float	getFloatY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

std::ostream &	operator<<(std::ostream & o, Point const & i);

bool	bsp(Point const a, Point const b, Point const c, Point const point);
