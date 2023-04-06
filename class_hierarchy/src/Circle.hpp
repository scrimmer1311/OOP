/*
 * Circle.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "Figure.hpp"

class Circle: Figure {
protected:
	double r; // Radius [m]
public:
	inline double perimeter() override {
		return 2 * M_PI * r;
	}
	inline double area() override {
		return M_PI * r * r;
	}
};

#endif /* CIRCLE_HPP_ */
