/*
 * Rectangle.h
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Figure.hpp"

class Rectangle: Figure {
protected:
	double a; // Size of side [m]
public:
	inline double perimeter() override {
		return 4. * a;
	}
	inline double area() override {
		return a * a;
	}
};

#endif /* RECTANGLE_H_ */
