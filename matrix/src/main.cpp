/*
 * main.cpp
 *
 *  Created on: 27 мар. 2023 г.
 *      Author: george
 */
#include "Matrix.hpp"

int main (int argc, char** argv) {
	const char* inp1 = "{{7, 59},{55, 62}}";
	const char* inp2 = "{{7, 6},{55, 4}}";

	Matrix A(inp1), B(inp2), C(Matrix::identity(2));
	Matrix D = A + B;
	C += B;
	C = A /B;
	cout << C << endl;


	return 0;
}




