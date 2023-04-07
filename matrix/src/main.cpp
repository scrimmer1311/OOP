/*
 * main.cpp
 *
 *  Created on: 27 мар. 2023 г.
 *      Author: george
 */
#include "Matrix.hpp"

int main (int argc, char** argv) {
	const char* inp = "{{7, 59},{55, 62}}";
	int rows, cols;
	EvaluateShape(inp, &rows, &cols);
	Matrix A(5), B(2), C(B);
	Matrix D(Matrix::identity(6));
	cout << cols << "a " << rows << endl;

	return 0;
}




