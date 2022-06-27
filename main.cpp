#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "organizador.h"

void to_low(string& a) {
  int i = 0;
  for (i = 0; i < a.length(); i++) {
    if (a[i] >= 65 && a[i] <= 90) {
      a[i] += 32;
    }
  }
}

int main(int argc, char const* argv[]) {
  int i = 0, j = 0, qtd = 1, k = 0;

  fstream input_file;
  fstream outpu_file;
  string token;
  string ordem = "";
  string texto[10000];
  string texto_bruto;
  stringstream ss(texto_bruto);

  input_file.open("1.tst.i", fstream::in);

  getline(input_file, token);
  getline(input_file, texto_bruto);

  ss << texto_bruto;

  while (getline(ss, token, ' ')) {
    to_low(token);
    ordem.append(token);
  }

  to_low(ordem);

  getline(input_file, token);

  while (!input_file.eof()) {
    getline(input_file, token, ' ');
    to_low(token);
    for (k = 0; k < token.length(); k++) {
      if (token[k] == '.' || token[k] == ',' || token[k] == '\n')
        token.erase(k--, 1);
    }
    texto[i] = token;
    i++;
  }

  QuickSort(texto, ordem, i);

  outpu_file.open("output_file.txt", fstream::out);

  for (int j = 0; j < i; j++) {
    if ((texto[j] != texto[j + 1])) {
      outpu_file << texto[j] << " " << qtd << endl;
      qtd = 1;
    } else
      qtd++;
  }

  outpu_file << "#FIM";

  input_file.close();

  outpu_file.close();

  return 0;
}
