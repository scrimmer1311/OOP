/*
 * MinusTriRect.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef MINUSTRIRECT_HPP_
#define MINUSTRIRECT_HPP_

<<<<<<< Upstream, based on branch 'master' of https://github.com/scrimmer1311/OOP.git
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
=======
#include "Circle.hpp"
#include "Rectangle.hpp"

class MinusTriRect: public Circle, public Rectangle {
	char base_figure;
public:
	MinusTriRect() = delete;
	MinusTriRect(Rectangle &r, Circle &c);
	MinusTriRect(Circle &c, Rectangle &r);
	double perimeter() override;
	double area() override;
>>>>>>> be98e17 Class ier.: final
};

#endif /* MINUSTRIRECT_HPP_ */
