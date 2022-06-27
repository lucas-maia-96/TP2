#include "organizador.h"

int get_idx(char a, string b) {
  int i = 0;
  for (i = 0; i < b.length(); i++) {
    if (a == b[i]) return 57 + i;
  }
  return a;
}

bool comp(string& a, string& b, string ordem) {
  int i = 0, j = 0, ida = 0, idb = 0;
  for (i = 0; i < min(a.length(), b.length()); i++) {
    if (a[i] != b[i]) {
      ida = get_idx(a[i], ordem);
      idb = get_idx(b[i], ordem);
      return ida < idb;
    };
  }

  return (a.length() < b.length());
}

void Particao(int Esq, int Dir, int* i, int* j, string* A, string ordem) {
  string x, w;
  *i = Esq;
  *j = Dir;
  x = A[(*i + *j) / 2];
  do {
    while (comp(A[*i], x, ordem)) (*i)++;
    while (comp(x, A[*j], ordem)) (*j)--;
    if (*i <= *j) {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int Esq, int Dir, string* A, string ordem) {
  int i, j;
  Particao(Esq, Dir, &i, &j, A, ordem);
  if (Esq < j) Ordena(Esq, j, A, ordem);
  if (i < Dir) Ordena(i, Dir, A, ordem);
}

void QuickSort(string* A, string ordem, int n) { Ordena(0, n - 1, A, ordem); }
