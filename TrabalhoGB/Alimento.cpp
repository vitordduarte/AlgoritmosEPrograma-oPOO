#include "Alimento.h"
#include <iostream>

using namespace std;

Alimento::Alimento(const string &nome1, float preco1, int estoque1, float peso1, const string &dataValidade1, const string &tipoAlimento1)
    : Produto(nome1,preco1,estoque1,peso1), dataValidade(dataValidade1), tipoAlimento(tipoAlimento1) {}

Alimento::~Alimento() {}

float Alimento::calcularFrete() const {
    return 3.0 + peso * 2.0;
}

void Alimento::exibirInfo() const {
    Produto::exibirInfo();
    cout << "  (Alimento) Validade: " << dataValidade << ", Tipo Alimento: " << tipoAlimento << "C\n";
}

string Alimento::getDataValidade() const {
  return dataValidade;
}
