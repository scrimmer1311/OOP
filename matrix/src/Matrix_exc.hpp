/*
 * Matrix_exc.hpp
 *
 *  Created on: 5 апр. 2023 г.
 *      Author: george
 */

#ifndef MATRIX_EXC_HPP_
#define MATRIX_EXC_HPP_

#include <iostream>
using std::ostream;

enum class MatrixErrCodes {
	dyn_mem_err,
	index_out_bounds,
	invalid_string,
	incomp_sizes,
	incorrect_matrix_size,
	was_del_matrix,
	unknown
};

class MatrixException {
	MatrixErrCodes code;
public:
	MatrixException(MatrixErrCodes c = MatrixErrCodes::unknown) {
		code = c;
	}
	friend ostream& operator<<(ostream &s, const MatrixException &e);
};

//Invalid index exception subclass
class IndexException: public MatrixException {
	int ind, valid;
public:
	IndexException(int i = -1, int v = -1) :
			MatrixException(MatrixErrCodes::index_out_bounds) {
		ind = i;
		valid = v;
	}
	friend ostream& operator<<(ostream &s, const IndexException &e);
};

//Incompatible matrices exception subclass
class IncompException: public MatrixException {
	char operation; //'+' / '-' / '*'
	char category; //'r' for rows, 'c' for columns, 'm' for multiplication
	int first, second;
public:
	IncompException(char oper = '\0', char cat = '\0', int fst = -1, int snd =
			-1) :
			MatrixException(MatrixErrCodes::incomp_sizes) {
		operation = oper;
		category = cat;
		first = fst;
		second = snd;
	}
	friend ostream& operator<<(ostream &s, const IncompException &e);
};

#endif /* MATRIX_EXC_HPP_ */
