/*
 * Matrix.hpp
 *
 *  Created on: Mar 21, 2023
 *      Author: root
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
	static double EPS = 1.e-6;
	// Методы надкласса
	Matrix();
	Matrix(const Matrix &other);
	virtual ~Matrix();
	// Подкласс и связанные с ним методы
	class Row {
		int cols;
		int *&rows;
	public:
		Row(int row, int cols, double **p) :
				rows(p[row - 1]) {
			this->cols = cols;
		}
		int& operator[](int i) {
			return rows[i - 1];
		}
	};

	Row operator[](int i) {
		return Row(i, cols, storage);
	}

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
	Matrix operator*(const double &mplier);
	Matrix& operator*=(const double &mplier);
	friend ostream& operator<<(ostream &s, const Matrix &M);
	Matrix operator+(Matrix &other); // TODO matrix + matrix ;
	// TODO matrix += matrix ;
	// TODO matrix - matrix ;
	// TODO matrix -= matrix
	Matrix operator*(const Matrix&) const;
	Matrix& operator*=(const Matrix&);
	Matrix& operator-(void); // unary minus
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;
	Matrix operator|(const Matrix&) const; //add to right
	Matrix operator/(const Matrix&) const; //add below
	void swap(int from, int to, const char); // swaps rows or cols;
	Matrix trim(const char, const int);
	Matrix& operator~(void); // обратная матрица;
	double determinant(); // определитель;
	Matrix solve(); //
};

#endif /* Matrix_HPP_ */
