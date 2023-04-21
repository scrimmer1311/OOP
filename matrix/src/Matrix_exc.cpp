/*
 * Matrix_exc.cpp
 *
 *  Created on: 21 апр. 2023 г.
 *      Author: george
 */
#include "Matrix_exc.hpp"
using std::cerr;
using std::endl;
ostream& operator<< (ostream &os, const MatrixException &me) {
	os << "Error in matrix! \n";
	os << "Code : " << me.code;
	if (me.code == MatrixErrCodes::dyn_mem_err)
		cerr << "Something went wrong in memory alloc" << endl;
	else if (me.code == MatrixErrCodes::invalid_string)
		cerr << "Invalid input" << endl;
	else if (me.code )
	return os;
}
ostream& operator<< (ostream &os, const IndexException &me) {
	os << "Error in matrix! \n";
		os << "Code : " << me.code;
}
ostream& operator<< (ostream &os, const IncompException &me) {

}
