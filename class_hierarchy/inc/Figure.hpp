/*
 * Figure.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef FIGURE_HPP_
#define FIGURE_HPP_
#include <cmath>

class Figure {
	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual ~Figure();
};

#endif /* FIGURE_HPP_ */
