#include <iostream>
#include <string>

using namespace std;

bool comp(string& a, string& b) {
  int i = 0;
  for (i = 0; i < min(a.length(), b.length()); i++) {
    if (a[i] != b[i]) return a[i] < b[i];
  }

  return (a.length() < b.length());
}

void Particao(int Esq, int Dir, int* i, int* j, string* A) {
  string x, w;
  *i = Esq;
  *j = Dir;
  x = A[(*i + *j) / 2];
  do {
    while (x > A[*i]) (*i)++;
    while (x < A[*j]) (*j)--;
    if (*i <= *j) {
      w = A[*i];
      A[*i] = A[*j];
      A[*j] = w;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

void Ordena(int Esq, int Dir, string* A) {
  int i, j;
  Particao(Esq, Dir, &i, &j, A);
  if (Esq < j) Ordena(Esq, j, A);
  if (i < Dir) Ordena(i, Dir, A);
}

void QuickSort(string* A, int n) { Ordena(0, n - 1, A); }

int main(int argc, char const* argv[]) {
  int i = 0;
  string ordem = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
  string texto[] = {"Era", "uma", "vez", "UMA", "gata", "xadrez"};
  QuickSort(texto, 6);
  for (int i = 0; i < 6; i++) {
    cout << texto[i] << endl;
  }

  return 0;
}
