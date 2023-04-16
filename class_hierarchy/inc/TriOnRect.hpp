/*
 * TriOnRect.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef TRIONRECT_HPP_
#define TRIONRECT_HPP_

<<<<<<< Upstream, based on branch 'master' of https://github.com/scrimmer1311/OOP.git
#include "Rectangle.h"
#include "Triangle.hpp"

class TriOnRect: public Triangle, public Rectangle {
public:
	TriOnRect() = delete;
	TriOnRect(const Triangle &a, const Rectangle &r): Triangle(a), Rectangle(r) {}
	double perimeter() override{
		return Triangle::perimeter() + Rectangle::perimeter() - Rectangle::a;
	}
=======
#include "Rectangle.hpp"
#include "Triangle.hpp"

class TriOnRect: public Triangle, public Rectangle {
public:
	TriOnRect() = delete;
	TriOnRect(const Triangle &a, const Rectangle &r): Triangle(a), Rectangle(r) {}
	double perimeter() override;
	double area() override;
>>>>>>> be98e17 Class ier.: final
};

#endif /* TRIONRECT_HPP_ */
