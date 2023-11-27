/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:26:15 by msapin            #+#    #+#             */
/*   Updated: 2023/10/13 17:29:02 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	displayMessage(std::string sentence) {
	std::cout << std::endl << "\033[1m\033[33m" << sentence << "\033[0m" << std::endl;
}

void	testTriangle(float aX, float aY, float bX, float bY, float cX, float cY, float pX, float pY) {

	Point const	a(aX, aY);
	Point const	b(bX, bY);
	Point const	c(cX, cY);
	Point const	point(pX, pY);

	if (bsp(a, b, c, point))
		std::cout << "The point (" << point.getFloatX() << ", " << point.getFloatY()
		<< ") is locate on the triangle "
		<< "A ("	<< a.getFloatX() << ", " << a.getFloatY() << ")  "
		<< "B (" << b.getFloatX() << ", " << b.getFloatY() << ")  "
		<< "C (" << c.getFloatX() << ", " << c.getFloatY() << ")" << std::endl;
	else
		std::cout << "The point (" << point.getFloatX() << ", " << point.getFloatY()
		<< ") is not locate on the triangle "
		<< "A ("	<< a.getFloatX() << ", " << a.getFloatY() << ")  "
		<< "B (" << b.getFloatX() << ", " << b.getFloatY() << ")  "
		<< "C (" << c.getFloatX() << ", " << c.getFloatY() << ")" << std::endl;
}

int main(void) {

	displayMessage("Point on triangle");
	testTriangle(1.0f, 1.0f, 3, 4, 4, 2, 3, 3);

	displayMessage("Point not on triangle");
	testTriangle(1.0f, 1.0f, 3, 4, 4, 2, 30, 3);

	displayMessage("Point on angle A");
	testTriangle(1.0f, 1.0f, 3, 4, 4, 2, 1, 1);

	displayMessage("Point on angle B");
	testTriangle(1.0f, 1.0f, 3, 4, 4, 2, 3, 4);

	displayMessage("Point on angle C");
	testTriangle(1.0f, 1.0f, 3, 4, 4, 2, 4, 2);

	displayMessage("Point on triangle but in float");
	testTriangle(1.0f, 1.0f, 3, 4, 4, 2, 3.1f, 3.2f);

	return 0;
}
