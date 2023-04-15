/*
 * Circle.cpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#include "Circle.hpp"

Circle::Circle(double r = 1) :
		r { r } {
}
double Circle::perimeter() {
	return 2 * M_PI * r;
}
double Circle::area() {
	return M_PI * r * r;
}

