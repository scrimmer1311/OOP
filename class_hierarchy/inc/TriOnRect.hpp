/*
 * TriOnRect.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef TRIONRECT_HPP_
#define TRIONRECT_HPP_

#include "Rectangle.h"
#include "Triangle.hpp"

class TriOnRect: public Triangle, public Rectangle {
public:
	TriOnRect() = delete;
	TriOnRect(const Triangle &a, const Rectangle &r): Triangle(a), Rectangle(r) {}
	double perimeter() override{
		return Triangle::perimeter() + Rectangle::perimeter() - Rectangle::a;
	}
};

#endif /* TRIONRECT_HPP_ */
