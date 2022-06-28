#ifndef ORGANIZA
#define ORGANIZA
#include <iostream>
#include <string>

#define Troca(A, B) \
  {                 \
    string C = A;   \
    A = B;          \
    B = C;          \
  }

using namespace std;

int get_idx(char a, string b);

bool comp(string& a, string& b, string ordem);

void Selection_sort(string* V, int n, string ordem);

string mediana_M(string* B, int M, string ordem);

void Particao(int Esq, int Dir, int* i, int* j, string* A, string ordem, int M,
              int S);

void Ordena(int Esq, int Dir, string* A, string ordem, int M, int S);

void QuickSort(string* A, string ordem, int n, int M, int S);

#endif