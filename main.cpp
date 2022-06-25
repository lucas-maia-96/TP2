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

  input_file.open("1.tst.i", fstream::in);

  string ordem = "Q A Z W S X E D C R F V T G B Y H N M U J I K O L P";
  to_low(ordem);
  string texto_bruto =
      "Sofisticado, o Te..nis Adidas Top Ten Low Sleek W e o tipo de calcado "
      "que "
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

  input_file.close();

  return 0;
}
