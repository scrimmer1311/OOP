#include <Rectangle.hpp>

Rectangle::Rectangle(double a = 1.) :
		a { a } {
}
double Rectangle::GetSide() {
	return a;
}
double Rectangle::perimeter() {
	return 4. * a;
}
double Rectangle::area() {
	return a * a;
}
