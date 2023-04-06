/*
 * Matrix_exc.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef MATRIX_EXC_HPP_
#define MATRIX_EXC_HPP_

#include "Matrix.hpp"
enum class Matr_exc_codes {

};
class Matrix_exception: public Matrix {
	Matr_exc_codes c;
public:
	Matrix_exception();
	friend ostream& operator<< (ostream& s, const Matrix_exception& e);
};

#endif /* MATRIX_EXC_HPP_ */
