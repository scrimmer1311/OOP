/*
 * TriOnRect.cpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#include "../inc/TriOnRect.hpp"

double TriOnRect::perimeter() {
		return Triangle::perimeter() + Rectangle::perimeter() - Rectangle::GetSide();
}
double TriOnRect::area() {
	return 0;
}
