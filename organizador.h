#ifndef ORGANIZA
#define ORGANIZA

#include <string>

using namespace std;

int get_idx(char a, string b);

bool comp(string& a, string& b, string ordem);

void Particao(int Esq, int Dir, int* i, int* j, string* A, string ordem);

void Ordena(int Esq, int Dir, string* A, string ordem);

void QuickSort(string* A, string ordem, int n);

#endif