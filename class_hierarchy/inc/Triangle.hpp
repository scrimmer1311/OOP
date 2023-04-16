/*
 * Traingle.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "Figure.hpp"

<<<<<<< Upstream, based on branch 'master' of https://github.com/scrimmer1311/OOP.git
class Triangle: virtual Figure {

=======
class Triangle: virtual public Figure {
	double a,b,c; // Sides [m]
public:
	Triangle() = delete; //
	Triangle(double, double, double);
	double GetSide(int);
	double perimeter() override;
	double area() override;
>>>>>>> be98e17 Class ier.: final
};

#endif /* TRIANGLE_HPP_ */
