#include "Camiseta.h"
#include <iostream>

using namespace std;

Camiseta::Camiseta(const string &nome1, float preco1, int estoque1, float peso1,
                   const string &tamanho1, const string &material1, const string &estampa1)
    : Vestuario(nome1, preco1, estoque1, peso1, tamanho1, material1),
      estampa(estampa1) {}

Camiseta::~Camiseta() {}

string Camiseta::getEstampa() const {
    return estampa;
}

void Camiseta::exibirInfo() const {
    Vestuario::exibirInfo();
    cout << "  (Camiseta) Estampa: " << estampa << "\n";
}
