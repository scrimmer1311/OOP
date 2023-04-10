//============================================================================
// Name        : parallel.cpp
// Author      : Mullin G.D.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {
	const int Nx = 4;
	const int Ny = 4;
	const int K1 = 4;
	const int K2 = 3;
	const int dim = Nx * Ny;
	// int *EN_IA = new int [N.size + 2* D.size]
	int E[dim], D[dim], N[dim];
	vector<int> D, N;
	int I = 0;
	for (int i = 0; i < Nx; ++i) {
		for (int j = 0; j < Ny; ++j) {
			I = i + Nx * j;
			E[I] = I;
		}
	}
	I = 0;
	int local_I = 0;
	int i = 0;
	int j = 0;
	while (I <= E[Nx * Ny - 1]) {
		do {
			N[i] = E[I];
			i++;
			local_I++;
			I++;
		} while (local_I % K1 > 0);
		local_I = 0;
		do {
			D[j] = E[I];
			j++;
			local_I++;
			I++;
		} while (local_I % K2 > 0);
		local_I = 0;
	}
	cout << "Non-divided: ";
	for (int i = 0; i < dim; ++i) {
		cout << N[i] << " ";
	}
	cout << "\nDivided: ";
	for (int i = 0; i < dim; ++i) {
		cout << D[i] << " ";
	}
}
