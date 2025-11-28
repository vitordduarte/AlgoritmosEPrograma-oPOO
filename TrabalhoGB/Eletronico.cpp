#include "Eletronico.h"
#include <iostream>


using namespace std;

Eletronico::Eletronico(const string &nome1, float preco1, int estoque1, float peso1, int tensao1, int garantiaMeses1)
    : Produto(nome1,preco1,estoque1,peso1), tensao(tensao1), garantiaMeses(garantiaMeses1) {}

Eletronico::~Eletronico() {}

float Eletronico::calcularFrete() const {
    return 10.0 + peso * 2; // retornando 10 reais + o peso multiplicado por 2, assim da p mudar o frete conforme o tipo do produto
}

void Eletronico::exibirInfo() const {
    Produto::exibirInfo();
    cout << "  (Eletrônico) Tensao: " << tensao << "V, Garantia: " << garantiaMeses << " meses\n";
}

int Eletronico::getTensao() const {
    return tensao;
}
int Eletronico::getGarantia() const {
    return garantiaMeses;
}
