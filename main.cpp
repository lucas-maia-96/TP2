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

int get_idx(char a, string b) {
  int i = 0;
  for (i = 0; i < b.length(); i++) {
    if (a == b[i]) return i;
  }
  return 0;
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

int main(int argc, char const* argv[]) {
  int i = 0, j = 0, qtd = 1, k = 0;
  string ordem = "Q A Z W S X E D C R F V T G B Y H N M U J I K O L P";
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
  string texto[200000];
  while (getline(ss, token, ' ')) {
    to_low(token);
    for (k = 0; k < token.length(); k++) {
      if (token[k] == '.' || token[k] == ',') token.erase(k--, 1);
    }
    texto[i] = token;
    i++;
  }

  QuickSort(texto, ordem, i);
  for (int j = 0; j < i; j++) {
    if ((texto[j] != texto[j + 1])) {
      cout << texto[j] << " " << qtd << endl;
      qtd = 1;
    } else
      qtd++;
  }

  return 0;
}
