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
using std::string;

enum class MatrixErrCodes {
	dyn_mem_err,
	index_out_bounds,
	invalid_string,
	incomp_sizes,
	incorrect_matrix_size,
	non_square_matrix,
	unknown
};

class MatrixException {
	MatrixErrCodes code;
public:
	MatrixException(MatrixErrCodes c = MatrixErrCodes::unknown) {
		code = c;
	}
	friend ostream& operator<<(ostream&, const MatrixException&);
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
	friend ostream& operator<<(ostream&, IndexException&);
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
	friend ostream& operator<<(ostream&, IncompException&);
};
class NonSquareException : public MatrixException {
	string op; // -1 (inverse), solve
	int r, c;
public:
	NonSquareException(string oper = "\0", int row = -1, int col = -1) :
		MatrixException(MatrixErrCodes::incomp_sizes) {
		op = oper;
		r = row;
		c = col;
	}
	friend ostream& operator<<(ostream&, NonSquareException&);
};


#endif /* MATRIX_EXC_HPP_ */
