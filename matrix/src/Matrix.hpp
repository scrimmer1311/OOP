/*
 * Matrix.hpp
 *
 *  Created on: Mar 21, 2023
 *      Author: george
 */

#ifndef Matrix_HPP_
#define Matrix_HPP_

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include "Matrix_exc.hpp"

using std::ostream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

// Misc functions

double** CreateTwoDimArray(int rows, int cols);
void EvaluateRows(const char *input, int *rows);
void EvaluateShape(const char *input, int *rows, int *cols);
double** FillTwoDimArray(double **stor, const char *input);

class Matrix {
	int rows; // количество строк
	int cols; // количество столбцов
	double **storage; // динамический массив для элементов матрицы
public:
	// Variant 1
	static double EPS;
	Matrix();
	Matrix(const Matrix &other);
	virtual ~Matrix();
	Matrix(int n, int m);	//n m Matrix constructor
	Matrix(double); //1*1 Matrix constructor
	Matrix(double*, int m);	// row vector
	Matrix(int n, double*);	// column vector
	Matrix(const char*);		// construction from symbol strings
	static Matrix identity(int n);
	static Matrix diagonal(double *vals, int n);
	int row() const {
		return rows;
	}
	int columns() const {
		return cols;
	}
	void set(const int i, const int j, double val);
	Matrix& operator=(const Matrix&);
	Matrix operator*(const double &mplier);
	Matrix& operator*=(const double &mplier);
	friend ostream& operator<<(ostream &s, const Matrix &M);
	// Variant 2
	Matrix operator+(const Matrix &other) const;
	Matrix& operator+=(const Matrix &other);
	Matrix operator-(const Matrix &other) const;
	Matrix& operator-=(const Matrix &other);
	Matrix operator*(const Matrix&) const;
	Matrix& operator*=(const Matrix&);
	Matrix& operator-(void); // unary minus
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;
	Matrix operator|(const Matrix&) const; //add to right
	Matrix operator/(const Matrix&) const; //add below
	// Variant 3
	void swap(int from, int to, const char); // Misc. - swaps rows or cols;
	Matrix trim(const char, const int); // Misc. - trims matrix
	Matrix& operator~(void); // Inverse matrix
	double determinant();
	Matrix solve(const Matrix &f); // Solve linear system with predifined right side
	class Row {
		int cols;
		double *&rows;
	public:
		Row(int row, int cols, double **p) :
				rows(p[row - 1]) {
			this->cols = cols;
		}
		double& operator[](int i) {
			return rows[i - 1];
		}
	};

	inline Row operator[](int i) {
		return Row(i, cols, storage);
	}

};

#endif /* Matrix_HPP_ */
