/*
 * main.cpp
 *
 *  Created on: 27 мар. 2023 г.
 *      Author: george
 */
#include "Matrix.hpp"
#include "Matrix_exc.hpp"

int main(int argc, char **argv) {
	try {
//		const char *inp1 = "{{7, 59},{55, 62}}";
//		const char *inp2 = "{{7, 6},{55, 4}}";
//
//		Matrix A(inp1), B(inp2), C(Matrix::identity(2));
//		Matrix D;
//		D = A * 5.;
//		C += B;
//		C = (A / B);
//		Matrix E = A * B;
//		E = ~A;
//		cout << E[1][1] << endl;
		Matrix A(3, 5), B(2, 6), C;
		~A;
	} catch (NonSquareException &ex) {
		cerr << ex;
	} catch (IndexException &ex) {
		cerr << ex;
	} catch (IncompException &ex) {
		cerr << ex;
	} catch (MatrixException &ex) {
		cerr << ex;
	}
	return 0;
}

