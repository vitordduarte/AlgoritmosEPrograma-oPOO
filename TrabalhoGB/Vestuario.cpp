#include "Vestuario.h"
#include <iostream>

using namespace std;

Vestuario::Vestuario(const string &nome1, float preco1, int estoque1, float peso1,
                     const string &tamanho1, const string &material1)
    : Produto(nome1, preco1, estoque1, peso1),
      tamanho(tamanho1),
      material(material1) {}

Vestuario::~Vestuario() {}

float Vestuario::calcularFrete() const {
    return 5.0f + peso * 2.0f;
}

void Vestuario::exibirInfo() const {
    Produto::exibirInfo();
    cout << "  (Vestuário) Tamanho: " << tamanho
         << ", Material: " << material << "\n";
}

string Vestuario::getTamanho() const {
    return tamanho;
}

string Vestuario::getMaterial() const {
    return material;
}
