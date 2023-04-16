/*
 * Circle.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "Figure.hpp"

class Circle: virtual Figure {
	Circle() = delete; //
	Circle(double);
	double r; // Radius [m]
public:
	double perimeter() override;
	double area() override;
};

#endif /* CIRCLE_HPP_ */
