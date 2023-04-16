#include "Triangle.hpp"

Triangle::Triangle(double a = 1, double b = 1, double c = 1) :
		a { a }, b { b }, c { c } {
}
double Triangle::GetSide(int which = 1) {
	switch(which) {
	case 1:
		return a;
	case 2:
		return b;
	case 3:
		return c;
	default:
		return 0;
	}
}
double Triangle::perimeter() {
	return a + b + c;
}
double Triangle::area() {
	double p = perimeter();
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

