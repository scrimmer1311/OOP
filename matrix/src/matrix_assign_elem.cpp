#include <iostream>
#define N 3

//Пример реализации присваивания элементу матрицы NxN, N>0

using namespace std;

class matrix {
	int rows;
	int cols;
	int **m;
public:
	matrix() {
		m = new int*[N];
		for (int i = 1; i <= N; i++) {
			m[i - 1] = new int[N];
			for (int j = 1; j <= N; j++)
				m[i - 1][j - 1] = i + j;
		}
	}

	~matrix() {
		for (int i = 1; i <= N; i++) {
			delete[] m[i - 1];
		}
		delete[] m;
	}

	class Row {
		int cols;
		int *&r;
	public:
		Row(int row, int cols, int **p) :
				r(p[row - 1]) {
			this->cols = cols;
		}
		int& operator[](int i) {
			return r[i - 1];
		}
	};

	Row operator[](int i) {
		return Row(i, cols, m);
	}

	friend ostream& operator<<(ostream &s, matrix &M) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				cout << M.m[i - 1][j - 1] << " ";
			cout << endl;
		}
		return s;
	}
};
//
//int main()
//{  matrix M;
//
//    cout<<M;
//    M[1][1]=0;
//    cout <<endl;
//    cout<<M;
//    return 0;
//}
