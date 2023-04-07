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

class Matrix_exception {
	Matr_exc_codes c;
public:
	Matrix_exception();
	friend std::ostream& operator<< (std::ostream& s, const Matrix_exception& e);
};

#endif /* MATRIX_EXC_HPP_ */
