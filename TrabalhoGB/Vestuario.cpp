#include "Vestuario.h"
#include <iostream>

using namespace std;

Vestuario::Vestuario(const string &n, float p, int e, float w, const string &t, const string &m)
    : Produto(n,p,e,w), tamanho(t), material(m) {}

Vestuario::~Vestuario() {}

double Vestuario::calcularFrete() const {
    return 5.0 + peso * 2.0;
}

void Vestuario::exibirInfo() const {
    Produto::exibirInfo();
    cout << "  (Vestuário) Tamanho: " << tamanho << ", Material: " << material << "\n";
}

string Vestuario::getTamanho() const {
  return tamanho;
}
string Vestuario::getMaterial() const {
  return material;
}
