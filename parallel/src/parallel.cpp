//============================================================================
// Name        : parallel.cpp
// Author      : Mullin G.D.
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <set>
#include <array>
using std::string;
using std::set;
using std::vector;
using std::array;

using std::cout;
using std::cerr;
using std::endl;
using std::stoi;

#define isDiv(I, K1, K2) ((I % (K1 + K2) >= K1) ? 1 : 0)

//inline bool isDivided(int I, int K1, int K2) {
//	bool res = false;
//	int residue = I % (K1 + K2);
//	if (residue >= K1)
//		res = true;
//	return res;
//}
template<typename T>
std::ostream& operator<<(std::ostream &os, const vector<T> &vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		os << vec[i] << " ";
		if ((i + 1) % 30 == 0)
			os << "\n";
	}
	os << "\n---------------\n";
	return os;
}
void TopologyOutput(array<vector<int>*, 6> &tops, array<string, 6> &names,
		const char *filename = "output.txt") {
	std::ofstream of(filename);
	if (of.is_open()) {
		for (size_t top = 0; top < tops.size(); top++) {
			of << names[top] << ": \n";
			of << *(tops[top]);
		}
	} else
		cerr << "File hasn't open yet";
}
void IncidenceEN(vector<int> &EN_IA, // Пустой
		vector<int> &EN_JA, // Пустой
		int Nx, int Ny, int K1, int K2, int V) {
	EN_IA.push_back(0);
	for (int j = 0; j < Ny; j++) {
		for (int i = 0; i < Nx; i++) {
			int I = i + Nx * j;
			int lu = I + j;
			if (!isDiv(I, K1, K2)) {
				EN_IA.push_back(4 + EN_IA.back());
				EN_JA.push_back(lu);
				EN_JA.push_back(lu + 1);
				EN_JA.push_back(lu + Nx + 1);
				EN_JA.push_back(lu + Nx + 2);
			} else {
				EN_IA.push_back(3 + EN_IA.back());
				EN_IA.push_back(3 + EN_IA.back());
				if (V == 1) {
					EN_JA.push_back(lu);
					EN_JA.push_back(lu + 1);
					EN_JA.push_back(lu + Nx + 1);
					//
					EN_JA.push_back(lu + 1);
					EN_JA.push_back(lu + Nx + 1);
					EN_JA.push_back(lu + Nx + 2);
				} else if (V == 2) {
					EN_JA.push_back(lu);
					EN_JA.push_back(lu + Nx + 1);
					EN_JA.push_back(lu + Nx + 2);
					//
					EN_JA.push_back(lu);
					EN_JA.push_back(lu + 1);
					EN_JA.push_back(lu + Nx + 2);
				}
			}
		}
	}
}
void IncidenceENtoNE(vector<int> &NE_IA, vector<int> &NE_JA, // Здесь вектора непустые
		const vector<int> &EN_IA, const vector<int> &EN_JA, int Ne, int Np) {
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

void AdjacencyNN(vector<int> &NN_IA, vector<int> &NN_JA,
		const vector<int> &EN_IA, const vector<int> &EN_JA,
		const vector<int> &NE_IA, const vector<int> &NE_JA) {
	NN_IA.push_back(0); // В начале всегда нуль
	for (size_t in_fix = 0; in_fix < NE_IA.size() - 1; ++in_fix) { // Ходим по всем узлам сетки, такие узлы считаем фиксированными
		NN_IA.push_back(NN_IA.back()); // Закидываем число смежных узлов с прошлого фиксированного узла
		set<int> its_adj_vals; // создаём множество для записи в него смежных узлов фиксированному узлу
		for (int ie_fix = NE_IA[in_fix]; ie_fix < NE_IA[in_fix + 1]; ++ie_fix) { // ходим по инцидентным ему элементам
			int e_fix = NE_JA[ie_fix]; // Элемент который инцидетен ввыбранному узлу
			for (int in = EN_IA[e_fix]; in < EN_IA[e_fix + 1]; ++in) { // ходим по другим узлом, которые инцидентны элементам для фиксированного узла
				for (int ie = NE_IA[EN_JA[in]]; ie < NE_IA[EN_JA[in] + 1]; // смотрим в элементы выбранного узла
						++ie) {
					if (NE_JA[ie] == NE_JA[ie_fix]) { // если в инцидентных двум узлам есть одинаковые элементы, то такие узлы смежны
						size_t s = its_adj_vals.size(); // запоминаем прошлый размер массива
						its_adj_vals.insert(EN_JA[in]); // закидываем в множество узел, если его ещё там не было
						if (its_adj_vals.size() != s)
							++NN_IA.back(); // если узел добавился в множество, то прибавляем количество смежных
						break;
					}
				}
			}
		}
		// используем итераторы для вставки множества в вектор
		NN_JA.insert(NN_JA.end(), its_adj_vals.begin(), its_adj_vals.end());
	}
}

int main(int argc, char **argv) {
	int Nx, Ny, V, K1, K2;
	int *input[5] = { &Nx, &Ny, &V, &K1, &K2 };
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
		string num;
		std::ifstream f(argv[1]);
		if (f.is_open()) {
			int n = 0;
			try {
				while (getline(f, num, ' ')) {
					++n;
					switch (n) {
					case 1:
						Nx = stoi(num);
						break;
					case 2:
						Ny = stoi(num);
						break;
					case 3:
						V = stoi(num);
						break;
					case 4:
						K1 = stoi(num);
						break;
					case 5:
						K2 = stoi(num);
						break;
					default:
						throw std::invalid_argument { "Too many arguments" };
					}
				}
				if (n < 3)
					throw std::invalid_argument { "Not enough arguments" };
				else if (n == 3) {
					K1 = 1;
					K2 = 1;
					cout << "By default, K1 and K2 equal 1." << endl;
				} else if (n == 4) {
					K2 = 1;
					cout << "By default, K2 equal 1." << endl;
				}
				for (int val = 0; val < 5; ++val) {
					cout << input_names[val] << " : " << *input[val] << endl;
					if (*input[val] < 0) {
						string err_mes = "Value" + input_names[val]
								+ "should be greater than 0";
						throw std::invalid_argument { err_mes };
					}
				}
				if (V != 1 && V != 2)
					throw std::invalid_argument {
							"Variant should be equal to 1 or 2" };
			} catch (const std::invalid_argument &ex) {
				cerr << "Invalid arguments. " << ex.what() << endl;
				return -3;

			}
		} else {
			cerr << "Wrong filename!" << endl;
			return -2;
		}
		f.close();
	}
		break;
	case 4: {
		try {
			cout << "Three values has been parsed" << endl;
			Nx = stoi(string(argv[1]));
			Ny = stoi(string(argv[2]));
			V = stoi(string(argv[3]));
			for (int val = 0; val < argc - 1; ++val) {
				cout << input_names[val] << " : " << *input[val] << endl;
				if (*input[val] < 0) {
					string err_mes = "Value" + input_names[val]
							+ "should be greater than 0";
					throw std::invalid_argument { err_mes };
				}
			}
			if (V != 1 && V != 2)
				throw std::invalid_argument {
						"Variant should be equal to 1 or 2" };

		} catch (const std::invalid_argument &ex) {
			cerr << "Invalid arguments " << ex.what() << endl;
			return -3;
		}
	}
		break;
	case 6: {
		try {
			cout << "Five values has been parsed" << endl;
			Nx = stoi(string(argv[1]));
			Ny = stoi(string(argv[2]));
			V = stoi(string(argv[3]));
			K1 = stoi(string(argv[4]));
			K2 = stoi(string(argv[5]));
			for (int val = 0; val < argc - 1; ++val) {
				cout << input_names[val] << " : " << *input[val] << endl;
				if (*input[val] < 0) {
					string err_mes = "Value" + input_names[val]
							+ "should be greater than 0";
					throw std::invalid_argument { err_mes };
				}
			}
			if (V != 1 && V != 2)
				throw std::invalid_argument {
						"Variant should be equal to 1 or 2" };

		} catch (const std::invalid_argument &ex) {
			cerr << "Invalid arguments " << ex.what() << endl;
			return -3;
		}
	}
		break;
	default:
		cerr << "Invalid quantity of arguments";
		return -4;
	}
	double start = clock();
	vector<int> en_ia, en_ja, nn_ja, nn_ia;
	IncidenceEN(en_ia, en_ja, Nx, Ny, K1, K2, V);
	int nN = (Nx + 1) * (Ny + 1);
	int nE = en_ia.size() - 1;
	vector<int> ne_ia(nN + 1), ne_ja(en_ja.size());
	IncidenceENtoNE(ne_ia, ne_ja, en_ia, en_ja, nE, nN);
	AdjacencyNN(nn_ia, nn_ja, en_ia, en_ja, ne_ia, ne_ja);
	double stop = clock();
	cout << "Elapsed time: " << (stop - start) / CLOCKS_PER_SEC << " s."
			<< endl;
	array<string, 6> out_names = { "EN_IA", "EN_JA", "NE_IA", "NE_JA", "NN_IA",
			"NN_JA" };
	array<vector<int>*, 6> outs = { &en_ia, &en_ja, &ne_ia, &ne_ja, &nn_ia,
			&nn_ja };
	TopologyOutput(outs, out_names);
	return 0;
}

