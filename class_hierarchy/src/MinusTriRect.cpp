/*
 * MinusTriRect.cpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#include "MinusTriRect.hpp"
MinusTriRect::MinusTriRect(Rectangle &r, Circle &c) :
		Circle(c), Rectangle(r), base_figure('r') {
}
MinusTriRect::MinusTriRect(Circle &c, Rectangle &r) :
		Circle(c), Rectangle(r), base_figure('c') {
}
double MinusTriRect::perimeter() {
	return Rectangle::perimeter() + Circle::perimeter();
}
double MinusTriRect::area() {
	switch (base_figure) {
	case 'c':
		return Circle::area() - Rectangle::area();
	case 'r':
		return Rectangle::area() - Circle::area();
	default:
		return 0;
	}
}

