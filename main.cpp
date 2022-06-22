#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void to_low(string& a) {
  int i = 0;
  for (i = 0; i < a.length(); i++) {
    if (a[i] >= 65 && a[i] <= 90) {
      a[i] += 32;
    }
  }
}

bool comp(string& a, string& b, string ordem) {
  int i = 0, j = 0, ida = 0, idb = 0;
  for (i = 0; i < min(a.length(), b.length()); i++) {
    if (a[i] != b[i]) {
      for (j = 0; j < ordem.length(); j++) {
        if (a[i] == ordem[j])
          return true;
        else if (b[i] == ordem[j])
          return false;
      }
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

int main(int argc, char const* argv[]) {
  int i = 0;
  string ordem = "QAZWSXEDCRFVTGBYHNMUJIKOLP";
  to_low(ordem);
  string texto_bruto =
      "Sofisticado, o Tenis Adidas Top Ten Low Sleek W e o tipo de calcado que "
      "faz uma baita diferenca no look da mulher moderna. Confeccionada em "
      "Couro predominante, sua parte superior promove um calce suave por "
      "longas horas. Alem disso, tem solado em Borracha para excelente tracao "
      "em superficies escorregadias. Mude os rumos de sua casualidade, va de "
      "Originals e faca efeito em diversas ocasioes.";

  to_low(texto_bruto);

  stringstream ss(texto_bruto);
  string token;
  string texto[texto_bruto.length()];
  while (getline(ss, token, ' ')) {
    texto[i] = token;
    i++;
  }
  for (string& a : texto) to_low(a);
  QuickSort(texto, ordem, 6);
  for (int j = 0; j < i; j++) {
    cout << texto[j] << endl;
  }

  return 0;
}
