#include "Alimento.h"
#include <iostream>

using namespace std;

Alimento::Alimento(const string &n, float p, int e, float w, const string &d, const string &t)
    : Produto(n,p,e,w), dataValidade(d), tipoAlimento(t) {}

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
