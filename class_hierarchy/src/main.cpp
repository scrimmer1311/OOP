//============================================================================
// Name        : class_hierarchy.cpp
// Author      : Mullin G.D.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TriOnRect.hpp"
#include "MinusTriRect.hpp"

using namespace std;
int main() {
	Rectangle r(2.);
	Triangle t(3. ,2, 1);
	TriOnRect tr(t, r);
	cout << tr.perimeter() << endl;
	Circle c(5);
	MinusTriRect cr(c, r);
	cout << cr.area() << endl;
	return 0;
}
