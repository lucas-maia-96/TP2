#include "organizador.h"

int get_idx(char a, string b) {
  int i = 0;
  for (i = 0; i < (int)(b.length()); i++) {
    if (a == b[i]) return 57 + i;
  }
  return a;
}

bool comp(string& a, string& b, string ordem) {
  int i = 0, ida = 0, idb = 0;
  for (i = 0; i < (int)min(a.length(), b.length()); i++) {
    if (a[i] != b[i]) {
      ida = get_idx(a[i], ordem);
      idb = get_idx(b[i], ordem);
      return ida < idb;
    };
  }

  return (a.length() < b.length());
}

void Selection_sort(string* V, int Esq, int Dir, int n, string ordem) {
  int i, j, min;
  for (i = Esq; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < Dir; j++) {
      if (comp(V[j], V[min], ordem)) min = j;
    }
    Troca(V[i], V[min]);
  }
}

string mediana_M(string* A, int i, int j, int M, string ordem) {
  string C[M];
  int new_i = 0;
  while (new_i < M) {
    C[new_i] = A[i + new_i];
    new_i++;
  }

  Selection_sort(C, 0, M - 1, M, ordem);
  return C[(M / 2)];
}

void Particao(int Esq, int Dir, int* i, int* j, string* A, string ordem, int M,
              int S) {
  string x, w;
  *i = Esq;
  *j = Dir;
  if (M <= (Dir - Esq))
    x = mediana_M(A, *i, *j, M, ordem);
  else
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

void Ordena(int Esq, int Dir, string* A, string ordem, int M, int S) {
  int i, j;
  if ((Dir - Esq) <= S) Selection_sort(A, Esq, Dir, (Dir - Esq), ordem);
  Particao(Esq, Dir, &i, &j, A, ordem, M, S);
  if (Esq < j) Ordena(Esq, j, A, ordem, M, S);
  if (i < Dir) Ordena(i, Dir, A, ordem, M, S);
}

void QuickSort(string* A, string ordem, int n, int M, int S) {
  Ordena(0, n - 1, A, ordem, M, S);
}
