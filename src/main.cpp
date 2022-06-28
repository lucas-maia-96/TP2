#include <getopt.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "organizador.h"

void to_low(string& a) {
  int i = 0;
  for (i = 0; i < (int)a.length(); i++) {
    if (a[i] >= 65 && a[i] <= 90) {
      a[i] += 32;
    }
  }
}

int main(int argc, char* const* argv) {
  int i = 0, j = 0, qtd = 1, k = 0, c, mediana, minimo;

  opterr = 0;

  fstream input_file;
  fstream output_file;
  string token;
  string ordem = "";
  string texto[100000];
  string texto_bruto;
  string input_name;
  string output_name;
  stringstream ss(texto_bruto);

  while ((c = getopt(argc, argv, "i:o:m:s:")) != EOF) {
    switch (c) {
      case 'i':
      case 'I':
        input_name = optarg;
        break;

      case 'o':
      case 'O':
        output_name = optarg;
        break;

      case 'm':
      case 'M':
        mediana = atoi(optarg);
        break;

      case 's':
      case 'S':
        minimo = atoi(optarg);
        break;

      default:
        break;
    }
  }

  input_file.open(input_name, fstream::in);

  if (!input_file.is_open()) {
    cout << "Erro no arquivo de entrada! " << endl;
    return 0;
  }

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
    ss.clear();
    texto_bruto.clear();
    getline(input_file, texto_bruto, '\n');
    ss << texto_bruto;
    while (getline(ss, token, ' ')) {
      to_low(token);
      for (k = 0; k < (int)token.length(); k++) {
        if (token[k] == '.' || token[k] == ',' || token[k] == '!' ||
            token[k] == '?' || token[k] == ':' || token[k] == ';' ||
            token[k] == '_')
          token.erase(k--, 1);
      }
      texto[i] = token;
      i++;
    }
  }

  QuickSort(texto, ordem, i, mediana, minimo);

  output_file.open(output_name, fstream::out);

  if (!output_file.is_open()) {
    cout << "Erro no arquivo de entrada! " << endl;
    return 0;
  }

  for (j = 0; j < i; j++) {
    if ((texto[j] != texto[j + 1])) {
      output_file << texto[j] << " " << qtd << endl;
      qtd = 1;
    } else
      qtd++;
  }

  output_file << "#FIM";

  input_file.close();

  output_file.close();

  return 0;
}
