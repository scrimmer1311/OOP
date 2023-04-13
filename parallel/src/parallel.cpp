//============================================================================
// Name        : parallel.cpp
// Author      : Mullin G.D.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stoi;

bool isDivided(int Nx, int Ny);

int main(int argc, char **argv) {
	int Nx, Ny, V, K1, K2;
	int* input[5] = {&Nx, &Ny, &V, &K1, &K2};\
	string input_names[5] = { "Nx", "Ny", "V", "K1", "K2" };


	switch (argc) {
	case 1: {
		string line;
		std::ifstream fhelp("help.txt");
		if (fhelp.is_open()) {
			while (getline(fhelp, line)) {
				cout << line << endl;
			}
		}
		fhelp.close();
	}
		return 1;
	case 2: {
		string line;
		std::ifstream f(argv[1]);
		if (f.is_open()) {
			try {
				if (f >> Nx >> Ny >> V >> K1 >> K2;)
				for (int val = 0; val < )
			}
			catch
		} else {
			cerr << "Wrong filename!";
			return -2;
		}
		f.close();
	}
		break;
	case 4: {
		try {
			Nx = stoi(string(argv[1]));
			Ny = stoi(string(argv[2]));
			V = stoi(string(argv[3]));
			string input_names[5] = { "Nx", "Ny", "V" };
			int input[5] = { Nx, Ny, V };
			for (int val = 0; val < sizeof(input) / sizeof(int); ++val)
				if (val < 0) {
					string err_mes = "Value" + input_names[val]
							+ "should be greater than 0";
					throw std::invalid_argument { err_mes };
				}
			if (V != 1 || V != 2)
				throw std::invalid_argument {
						"Variant should be equal to 1 or 2" };

		} catch (const std::invalid_argument &ex) {
			cerr << "Invalid arguments" << ex.what() << endl;
			return -3;
		}
	}
		break;
	case 6: {
			try {
				Nx = stoi(string(argv[1]));
				Ny = stoi(string(argv[2]));
				V = stoi(string(argv[3]));
				K1 = stoi(string(argv[4]));
				K2 = stoi(string(argv[5]));
				string input_names[5] = { "Nx", "Ny", "V", "K1", "K2" };
				int input[5] = { Nx, Ny, V, K1, K2 };
				for (int val = 0; val < sizeof(input); ++val)
					if (val < 0) {
						string err_mes = "Value" + input_names[val]
								+ "should be greater than 0";
						throw std::invalid_argument { err_mes };
					}
				if (V != 1 || V != 2)
					throw std::invalid_argument {
							"Variant should be equal to 1 or 2" };

			} catch (const std::invalid_argument &ex) {
				cerr << "Invalid arguments" << ex.what() << endl;
				return -3;
			}
		}
			break;
	default:
		cerr << "Invalid quantity of arguments";
		return -4;
	}
	return 0;
}
/*
 void Step1(vector<int> &E, vector<int> &D, vector<int> &N, int Nx, int Ny,
 int K1, int K2) {
 int dim = Nx * Ny;
 E.resize(dim);
 //D.resize(dim);
 //N.resize(dim);
 int I = 0;
 int I_max = Nx * Ny - 1;
 for (int i = 0; i < Nx; ++i) {
 for (int j = 0; j < Ny; ++j) {
 I = i + Nx * j;
 //E.push_back(I);
 E[I] = I;
 }
 }
 I = 0;
 int local_I = 0;
 int i = 0;
 int j = 0;
 while (I <= I_max) {
 do {
 N.push_back(E[I]);
 //N[i] = E[I];
 i++;
 local_I++;
 I++;
 } while (local_I % K1 > 0);
 local_I = 0;
 do {
 D.push_back(E[I]);
 //D[j] = E[I];
 j++;
 local_I++;
 I++;
 } while (local_I % K2 > 0);
 local_I = 0;
 }
 cout << "Non-divided: ";
 for (int i = 0; i < N.size(); ++i) {
 cout << N[i] << " ";
 }
 cout << "\nDivided: ";
 for (int i = 0; i < D.size(); ++i) {
 cout << D[i] << " ";
 }
 cout << endl;
 }
 bool FindIn(int I, vector<int> N, vector<int> D) {

 for (int i = 0; i < N.size(); i++) {
 if (I == N[i])
 return false;
 }
 for (int i = 0; i < N.size(); i++) {
 if (I == D[i])
 return true;
 }
 }
 void PrintVector(vector<int> V) {
 cout << "Print Vector\n";
 for (int i = 0; i < V.size(); i++)
 cout << V[i] << " ";
 cout << endl;
 cout << "---------------\n";
 }
 vector<int> Fill_EN_IA(vector<int> N, vector<int> D, int I_max) {
 vector<int> EN_IA;
 EN_IA.push_back(0);
 //PrintVector(EN_IA);
 int i = 1;
 for (int I = 0; I <= I_max; I++) {
 if (!FindIn(I, N, D)) {
 EN_IA.push_back(4 + EN_IA[i - 1]);
 //PrintVector(EN_IA);
 ++i;
 } else {
 EN_IA.push_back(3 + EN_IA[i - 1]);
 ++i;
 EN_IA.push_back(3 + EN_IA[i - 1]);
 ++i;
 //PrintVector(EN_IA);
 }
 }
 return EN_IA;
 }
 vector<int> Fill_EN_JA(vector<int> N, vector<int> D, int I_max) {
 vector<int> EN_JA;
 for (int I = 0; I <= I_max; ++I) {
 int row = I / Nx;
 int col = I - Nx * row;
 if (!FindIn(I, N, D)) {
 int lu = I + row;
 EN_JA.push_back(lu);
 EN_JA.push_back(lu + 1);
 EN_JA.push_back(lu + Nx + 1);
 EN_JA.push_back(lu + Nx + 2);
 } else {
 // Справа-налево
 int lu = I + row;
 EN_JA.push_back(lu);
 EN_JA.push_back(lu + 1);
 EN_JA.push_back(lu + Nx + 1);
 //
 EN_JA.push_back(lu + 1);
 EN_JA.push_back(lu + Nx + 1);
 EN_JA.push_back(lu + Nx + 2);
 }
 }
 return EN_JA;
 }
 void EN_TO_NE(vector<int> &NE_IA, vector<int> &NE_JA, const vector<int> &EN_IA,
 const vector<int> &EN_JA) {
 int Ne = EN_IA.size() - 1;
 int Np = (Nx + 1) * (Ny + 1);
 for (int i = 0; i < EN_IA[Ne]; ++i) {
 NE_IA[EN_JA[i] + 1]++;
 }

 for (int in = 1; in <= Np; ++in) {
 NE_IA[in] += NE_IA[in - 1];
 }
 for (int in = 0; in < Np; ++in)
 NE_JA[NE_IA[in + 1] - 1] = 0;

 for (int ie = 0; ie <= Ne - 1; ++ie) {
 for (int j = EN_IA[ie]; j < EN_IA[ie + 1]; ++j) {
 int jn = EN_JA[j];
 NE_JA[NE_IA[jn] + NE_JA[(NE_IA[jn + 1] - 1)]++] = ie;
 }
 }
 }
 void Step3(vector<int> &NN_IA, vector<int> &NN_JA, const vector<int> &NE_IA,
 const vector<int> &NE_JA) {
 int size_nnja = 0;
 for (int in_fix = 0; in_fix < NE_IA.size() - 1; ++in_fix) {
 //берем один узел
 int pos_fix = 0;
 NN_IA[in_fix + 1] += NN_IA[in_fix]; // прибавляем количество прошлых узлов
 NN_IA[in_fix + 1]++; // прибавляем свой собственный узел
 NN_JA[NN_IA[in_fix] + pos_fix] += in_fix;
 pos_fix++;
 size_nnja++;
 for (int in = 0; in < NE_IA.size() - 1; ++in) {
 if (in_fix != in) {
 for (int ie_fix = NE_IA[in_fix]; ie_fix < NE_IA[in_fix + 1];
 ++ie_fix) {
 for (int ie = NE_IA[in]; ie < NE_IA[in + 1]; ++ie) {
 if (NE_JA[ie_fix] == NE_JA[ie]) {
 NN_IA[in_fix + 1]++; // прибавляем смежный узел в количество смежных для фиксированного
 NN_JA[NN_IA[in_fix] + pos_fix] += in;
 pos_fix++;
 size_nnja++;
 goto adj_found;
 }
 }
 }
 }
 adj_found: {
 }
 }
 }
 }
 /*int main() {
 const int dim = Nx * Ny;
 int I_max = Nx * Ny - 1;
 // int *EN_IA = new int [N.size + 2* D.size]
 //int E[dim], D[dim], N[dim];
 vector<int> E, D, N;
 Step1(E, D, N, Nx, Ny, K1, K2);
 bool flag = FindIn(0, N, D);
 cout << flag << endl;
 vector<int> EN_IA = Fill_EN_IA(N, D, I_max);
 PrintVector(EN_IA);
 vector<int> EN_JA = Fill_EN_JA(N, D, I_max);
 PrintVector(EN_JA);
 vector<int> NN_IA((Nx + 1) * (Ny + 1) + 1), NN_JA(
 pow((Nx + 1) * (Ny + 1), 2));
 vector<int> NE_IA((Nx + 1) * (Ny + 1) + 1), NE_JA(EN_JA.size());
 EN_TO_NE(NE_IA, NE_JA, EN_IA, EN_JA);
 PrintVector(NE_IA);
 PrintVector(NE_JA);
 Step3(NN_IA, NN_JA, NE_IA, NE_JA);
 PrintVector(NN_IA);
 PrintVector(NN_JA);

 }*/

