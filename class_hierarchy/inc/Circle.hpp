/*
 * Circle.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "Figure.hpp"

<<<<<<< Upstream, based on branch 'master' of https://github.com/scrimmer1311/OOP.git
class Circle: virtual Figure {
	Circle() = delete; //
	Circle(double);
	double r; // Radius [m]
public:
=======
class Circle: virtual public Figure {
	double r; // Radius [m]
public:
	Circle() = delete; // не можем сделать пустой круг
	Circle(double);
	double GetRadius();
>>>>>>> be98e17 Class ier.: final
	double perimeter() override;
	double area() override;
};

#endif /* CIRCLE_HPP_ */
