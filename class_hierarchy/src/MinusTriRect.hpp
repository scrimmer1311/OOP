/*
 * MinusTriRect.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef MINUSTRIRECT_HPP_
#define MINUSTRIRECT_HPP_

#include "Rectangle.h"
#include "Circle.hpp"

class MinusTriRect: public Circle, public Rectangle {
	char base_figure;
public:
	MinusTriRect() = delete;
	MinusTriRect(Rectangle &r, Circle &c) : Rectangle(r), Circle(c), base_figure('r') {}
	MinusTriRect(Circle &c, Rectangle &r) : Circle(c), Rectangle(r), base_figure('c') {}
	double area() override {
		switch(base_figure) {
		case 'c':
			return 0;
			break;
		case 'r':
		}
	}
};

#endif /* MINUSTRIRECT_HPP_ */
