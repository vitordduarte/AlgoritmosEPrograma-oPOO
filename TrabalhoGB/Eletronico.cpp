#include "Eletronico.h"
#include <iostream>


using namespace std;

Eletronico::Eletronico(const string &n, float p, int e, float w, int t, int g)
    : Produto(n,p,e,w), tensao(t), garantiaMeses(g) {}

Eletronico::~Eletronico() {}

float Eletronico::calcularFrete() const {
    return 10.0 + peso * 2; // retornando 10 reais + o peso multiplicado por 2
}

void Eletronico::exibirInfo() const {
    Produto::exibirInfo();
    cout << "  (Eletrônico) Tensao: " << tensao << "V, Garantia: " << garantiaMeses << " meses\n";
}

int Eletronico::getTensao() const { return tensao; }
int Eletronico::getGarantia() const { return garantiaMeses; }
