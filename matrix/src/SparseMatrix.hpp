/*
 * SparseMatrix.h
 *
 *  Created on: 16 апр. 2023 г.
 *      Author: george
 */

#ifndef SPARSEMATRIX_HPP_
#define SPARSEMATRIX_HPP_
#include <vector>
using std::vector;
// Compressed sparsed row format used
class SparseMatrix final {
	int rows;
	int cols;
	vector<double> vals;
	vector<int> ia;
	vector<int> ja;
public:
	SparseMatrix() = delete; // Объявление пустой разреженной матрицы бессмысленно
	SparseMatrix(
			vector<double> vals,
			vector<int> ia,
			vector<int> ja);	// empty n m Matrix constructor
	void smdv(const crsm *A, Matrix *b, const double *v) // b += Av
	{
		for(int row = 0; row < n; ++row)
			for(int i = A->airow[row]; i < A->airow[row+1]; ++i)
				b[row] += A->aval[i] * v[A->aicol[i]];
	}
	virtual ~SparseMatrix();
	SparseMatrix(const SparseMatrix &other);


};

#endif /* SPARSEMATRIX_HPP_ */
