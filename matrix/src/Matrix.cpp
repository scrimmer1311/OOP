/*
 * Matrix.cpp
 *
 *  Created on: Mar 21, 2023
 *      Author: root
 */
#include <cstdio>
#include "Matrix.hpp"
using std::string;
using std::ostream;
const int dim = 1;
double Matrix::EPS = 1.e-6;

double** CreateTwoDimArray(int rows, int cols) {
	double **storage = new double*[rows];
	for (int i = 0; i < rows; i++) {
		storage[i] = new double[cols];
	}
	return storage;
}
void EvaluateRows(const char *input, int *rows) {
	int i = 0;
	int l_quotes, r_quotes;
	l_quotes = r_quotes = 0;
	while (input[i] != '\0') {
		switch (input[i]) {
		case '{':
			l_quotes++;
			break;
		case '}':
			r_quotes++;
			break;
		}
		i++;
	}
	if (r_quotes != l_quotes)
		cerr << "Invalid input" << endl;
	else if (l_quotes == 1 || r_quotes == 1)
		*rows = 1;
	else
		*rows = l_quotes - 1;
}

void EvaluateShape(const char *input, int *rows, int *cols) {
	EvaluateRows(input, rows);
	int commas = 0;
	int i = 0;
	while (input[i] != '\0') {
		if (input[i] == ',')
			commas++;
		i++;
	}
	if (*rows == 0)
		*cols = 0;
	else {
		if ((commas - *rows + 1) % (*rows) == 0)
			*cols = ((commas - *rows + 1) / (*rows)) + 1;
		else
			cerr << "Invalid input" << endl;
	}
}
double** FillTwoDimArray(double **stor, const char *inp) {
	int i = 0;
	string input(inp);
	input.erase(0, 1);
	input.erase(input.length() - 2, 1);
	string numba;
	int row_index, col_index;
	row_index = col_index = 0;
	while (input[i] != '\0') {
		if (input[i] == '{') {
			i++;
			do {
				if (input[i] != ',' || input[i] == '.' || input[i] == '-') {
					numba += input[i];
				} else {
					stor[row_index][col_index] = stod(numba);
					col_index++;
					numba.clear();
				}
				i++;
			} while (input[i] != '}');
			stor[row_index][col_index] = stod(numba);
			row_index++;
			col_index = 0;
			numba.clear();
		}
		i++;
	}
	return stor;
}
// КОНСТРУКТОРЫ
Matrix::Matrix::Matrix(int n, int m) :
		rows(n), cols(m) {
// выделим память
	storage = CreateTwoDimArray(rows, cols);

//заполним массив
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			storage[i][j] = 0.;
	}
}
Matrix::Matrix() :
		Matrix(1, 1) {

}
////// -fno-elide-consructors
Matrix::Matrix(double val) :
		Matrix() {
	storage[0][0] = val;
}
Matrix::Matrix(double *v_row, int m) :
		Matrix(1, m) {
	for (int j = 0; j < cols; ++j)
		storage[0][j] = v_row[j];
}

Matrix::Matrix(int n, double *v_col) :
		Matrix(n, 1) {
	for (int i = 0; i < rows; ++i)
		storage[i][0] = v_col[i];
}
Matrix::Matrix(const char *input) {
	EvaluateShape(input, &rows, &cols);
	storage = CreateTwoDimArray(rows, cols);
	storage = FillTwoDimArray(storage, input);

}
Matrix::Matrix::~Matrix() {
	if (storage != nullptr) {
		for (int i = 0; i < rows; i++) {
			delete[] storage[i];
		}
		delete[] storage;
		storage = nullptr;
	} else
		cerr << "This object have already been deleted" << endl;
}

Matrix::Matrix(const Matrix &other) {
	rows = other.rows;
	cols = other.cols;
	storage = CreateTwoDimArray(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			storage[i][j] = other.storage[i][j];
		}
	}
}
// ОПЕРАЦИИ
Matrix Matrix::identity(int n) {
	Matrix res(n, n);
	for (int i = 0; i < res.rows; i++) {
		for (int j = 0; j < res.cols; j++) {
			if (i == j)
				res.storage[i][j] = 1.;
		}
	}
	return res;
}
Matrix Matrix::diagonal(double *vals, int n) {
	Matrix res(n, n);
	for (int i = 0; i < res.rows; i++) {
		for (int j = 0; j < res.cols; j++) {
			if (i == j)
				res.storage[i][j] = vals[i];
		}
	}
	return res;
}
void Matrix::set(const int i, const int j, double val) {
	if (i > rows || j > cols) {
		cerr << "Given index is out of bounds!" << endl;
		return;
	}
	storage[i - 1][j - 1] = val;
}
Matrix& Matrix::operator =(const Matrix &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < rows; ++i)
		delete[] storage[i];
	delete[] storage;
	rows = other.rows;
	cols = other.cols;
	storage = CreateTwoDimArray(other.rows, other.cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			storage[i][j] = other.storage[i][j];
	}
	return *this;

}
Matrix Matrix::operator +(const Matrix &other) const {
	Matrix res(rows, cols);
	for (int i = 0; i < res.rows; i++) {
		for (int j = 0; j < res.cols; j++)
			res.storage[i][j] = storage[i][j] + other.storage[i][j];
	}
	return res;
}
Matrix& Matrix::operator +=(const Matrix &other) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			storage[i][j] += other.storage[i][j];
	}
	return *this;
}
Matrix Matrix::operator*(const double &mplier) {
	Matrix res(rows, cols);
	for (int i = 0; i < res.rows; i++) {
		for (int j = 0; j < res.cols; j++)
			res.storage[i][j] *= mplier;
	}
	return res;
}
Matrix& Matrix::operator *=(const double &mplier) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			storage[i][j] *= mplier;
	}
	return *this;
}

Matrix& Matrix::operator -() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			storage[i][j] -= 1.;
	}
	return *this;
}
bool Matrix::operator ==(const Matrix &other) const {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (storage[i][j] != other.storage[i][j])
				goto unequal;
		}
	}
	return true;
	unequal: return false;
}
bool Matrix::operator !=(const Matrix &other) const {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (abs(storage[i][j] - other.storage[i][j]) < EPS)
				goto unequal;
		}
	}
	return false;
	unequal: return true;
}
Matrix Matrix::operator|(const Matrix &other) const {
	Matrix result;
	if (rows != other.rows)
		cerr << "Matrices dimensions should be equal";
	else {
		Matrix res(rows, cols + other.cols);
		for (int i = 0; i < res.rows; ++i) {
			for (int j = 0; j < res.cols; ++j) {
				if (j < cols) {
					res.storage[i][j] = storage[i][j];
				} else
					res.storage[i][j] = other.storage[i][j - cols];
			}
		}
		result = res;
	}
	return result;
}
Matrix Matrix::operator /(const Matrix &other) const {
	Matrix result;
	if (cols != other.cols)
		cerr << "Matrices dimensions should be equal";
	else {
		Matrix res(rows + other.rows, cols);
		for (int i = 0; i < res.rows; ++i) {
			for (int j = 0; j < res.cols; ++j) {
				if (i < rows) {
					res.storage[i][j] = storage[i][j];
				} else
					res.storage[i][j] = other.storage[i - rows][j];
			}
		}
		result = res;
	}
	return result;
}
void Matrix::swap(int from, int to, const char which) {
	/*
	 * Parameters:
	 * int from: which line should be moved
	 * int to: place of the line
	 * const char which: selects types of line:
	 * 		'r' - row
	 * 		'c' - column
	 * 		Other variants incompatible.
	 */
	switch (which) {
	case 'r': {
		double *buf = new double[cols];
		for (int j = 0; j < cols; ++j) {
			buf[j] = storage[to][j];
			storage[to][j] = storage[from][j];
			storage[from][j] = buf[j];
		}
		delete[] buf;
		buf = nullptr;
	}
		break;
	case 'c': {
		double *buf = new double[rows];
		for (int i = 0; i < rows; ++i) {
			buf[i] = storage[to][i];
			storage[to][i] = storage[from][i];
			storage[from][i] = buf[i];
		}
		delete[] buf;
		buf = nullptr;
	}
		break;
	}
}
Matrix Matrix::trim(const char which, const int trim_ind) {
	Matrix result;
	switch (which) {
	case 'r':
		if (trim_ind >= rows)
			cerr << "Too high index";
		else if (trim_ind < 0)
			cerr << "Trim index must be positive";
		else {
			Matrix res(rows - trim_ind, cols);
			for (int i = 0; i < res.rows; ++i) {
				for (int j = 0; j < res.cols; ++j)
					res.storage[i][j] = storage[trim_ind + i][j];
			}
			result = res;
		}
		break;
	case 'c':
		if (trim_ind >=cols)
			cerr << "Too high index";
		else if (trim_ind < 0)
			cerr << "Trim index must be positive";
		else {
			Matrix res(rows, cols- trim_ind);
			for (int i = 0; i < res.rows; ++i) {
				for (int j = 0; j < res.cols; ++j)
					res.storage[i][j] = storage[i][trim_ind + j];
			}
			result = res;
		}
		break;
	default:
		cerr << "invalid trim identifier";
		break;
	}
	return result;
}

Matrix& Matrix::operator~() {
	if (rows != cols)
		cerr << "Reverse matrix couldn't be got with unequal dimensions";
	else {
		int n = rows;
		Matrix res = Matrix::identity(n);
		Matrix big(n, 2 * n);
		big = *this | res;
		// Прямой ход
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < 2 * n; i++)
				big.storage[k][i] /= storage[k][k];
			for (int i = k + 1; i < n; i++) {
				double K = big.storage[i][k] / big.storage[k][k];
				for (int j = 0; j < 2 * n; j++)
					big.storage[i][j] -= big.storage[k][j] * K;
			}
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					storage[i][j] = big.storage[i][j];
		}
		// Обратный ход
		for (int k = n - 1; k > -1; k--) {
			for (int i = 2 * n - 1; i > -1; i--)
				big.storage[k][i] = big.storage[k][i] / storage[k][k];
			for (int i = k - 1; i > -1; i--) {
				double K = big.storage[i][k] / big.storage[k][k];
				for (int j = 2 * n - 1; j > -1; j--)
					big.storage[i][j] = big.storage[i][j]
							- big.storage[k][j] * K;
			}
		}
		res = big.trim('c', n);
		*this = res;
	}
	return *this;
}
ostream& operator<<(ostream &s, const Matrix &m) {
	s << std::setprecision(6);
	for (int i = 0; i < m.rows; ++i) {
		s << "|";
		for (int j = 0; j < m.cols; ++j)
			s << ' ' << std::setw(6) << m.storage[i][j];
		s << " |" << endl;
	}
	return s;
}

