/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:41:21 by msapin            #+#    #+#             */
/*   Updated: 2023/09/18 18:46:24 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	subtract(Point const & first, Point const & second, int axle) {

	if (axle == X)
		return first.getFloatX() - second.getFloatX();
	else
		return first.getFloatY() - second.getFloatY();
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	
	float	side_1 = subtract(point, b, X) * subtract(a, b, Y) - subtract(a, b, X) * subtract(point, b, Y);
	float	side_2 = subtract(point, c, X) * subtract(b, c, Y) - subtract(b, c, X) * subtract(point, c, Y);
	float	side_3 = subtract(point, a, X) * subtract(c, a, Y) - subtract(c, a, X) * subtract(point, a, Y);

	if ((side_1 < 0.0 && side_2 < 0.0 && side_3 < 0.0) ||
	(side_1 > 0.0 && side_2 > 0.0 && side_3 > 0.0))
		return true;
	else
		return false;
}
