/*
 * Matrix_exc.cpp
 *
 *  Created on: 21 апр. 2023 г.
 *      Author: george
 */
#include "Matrix_exc.hpp"

using std::cerr;
using std::endl;

ostream& operator<<(ostream &os, const MatrixException &me) {
	os << "Error in matrix! \n";
	os << "Code : " << (int)me.code << "\n";
	if (me.code == MatrixErrCodes::dyn_mem_err)
		os << "Something went wrong in memory alloc\n";
	else if (me.code == MatrixErrCodes::invalid_string)
		os << "Invalid input\n";
	return os;
}
ostream& operator<<(ostream &os, IndexException &ie) {
	os << static_cast<MatrixException&>(ie);
	os << "You trying to get access to element Matrix : " << ie.ind;
	os << ".\nBut the limit is : " << ie.valid;
	return os;
}
ostream& operator<<(ostream &os, IncompException &ice) {
	os << static_cast<MatrixException&>(ice);
	os << "Matrices dimensions must be equal\n";
	os << "When performing operation: " << ice.operation << '\n';
	switch (ice.category) {
	case 'r':
		os << "Rows of first: " << ice.first;
		os << " not equal to rows of second: " << ice.second;
		break;
	case 'c':
		os << "Columns of first: " << ice.first;
		os << " not equal to columns of second: " << ice.second;
		break;
	default:
		if (ice.operation == '*') {
			os << "Columns of first: " << ice.first;
			os << " not equal to rows of second: " << ice.second;
		}
	}
	return os;
}
ostream& operator<<(ostream& os, NonSquareException& nse) {
	os << static_cast<MatrixException&>(nse);
	os << "Matrix must be square\n";
	os << "When performing operation: " << nse.op << '\n';
	os << "First dim: " << nse.r << " not equal to second dim: " << nse.c;
	return os;
}

