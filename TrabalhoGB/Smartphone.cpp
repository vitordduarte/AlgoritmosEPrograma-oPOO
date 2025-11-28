#include "Smartphone.h"
#include <iostream>


using namespace std;

Smartphone::Smartphone(const string &nome1, float preco1, int estoque1, float peso1, int tensao1, int garantiaMeses1, int armazenamento1, string &marca1) // aqui ele herda de eletronico que herda de produto
    : Eletronico(nome1,preco1,estoque1,peso1,tensao1,garantiaMeses1), armazenamento(armazenamento1), marca(marca1) {}

Smartphone::~Smartphone() {}

string Smartphone::getEspecificacoes() const {
    return to_string(armazenamento) + "GB, " + string(marca) + "é a marca";
}

void Smartphone::exibirInfo() const {
    Eletronico::exibirInfo();
    cout << "  (Smartphone) " << getEspecificacoes() << "\n";
}
