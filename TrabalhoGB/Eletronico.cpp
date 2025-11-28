#include "Eletronico.h"
#include <iostream>

using namespace std;

Eletronico::Eletronico(const string &nome1, float preco1, int estoque1, float peso1,
                       int tensao1, int garantiaMeses1)
    : Produto(nome1, preco1, estoque1, peso1),
      tensao(tensao1),
      garantiaMeses(garantiaMeses1) {}

Eletronico::~Eletronico() {}

float Eletronico::calcularFrete() const {
    // Exemplo: frete maior para eletrônicos
    return 10.0f + peso * 2.0f; // 10 reais + o peso multiplicado por 2
}

void Eletronico::exibirInfo() const {
    Produto::exibirInfo();
    cout << "  (Eletrônico) Tensão: " << tensao
         << "V, Garantia: " << garantiaMeses << " meses\n";
}

int Eletronico::getTensao() const {
    return tensao;
}

int Eletronico::getGarantia() const {
    return garantiaMeses;
}
