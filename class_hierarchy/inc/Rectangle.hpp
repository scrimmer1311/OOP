/*
 * Rectangle.h
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Figure.hpp"

<<<<<<< Upstream, based on branch 'master' of https://github.com/scrimmer1311/OOP.git
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
=======
class Rectangle: virtual public Figure {
	double a; // Size of side [m]
public:
	Rectangle() = delete;
	Rectangle(double);
	double GetSide();
	double perimeter() override;
	double area() override;
>>>>>>> be98e17 Class ier.: final
};

#endif /* RECTANGLE_H_ */
