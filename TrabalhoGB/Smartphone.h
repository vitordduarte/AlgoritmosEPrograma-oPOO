#include "Smartphone.h"
#include <iostream>


using namespace std;

Smartphone::Smartphone(const string &n, float p, int e, float w, int v, int g, int armaz, string marca) // aqui ele herda de eletronico que herda de produto
    : Eletronico(n,p,e,w,t,g), armazenamento(armaz), marca(marca) {}

Smartphone::~Smartphone() {}

string Smartphone::getEspecificacoes() const {
    return to_string(armazenamento) + "GB, " + string(marca) + "é a marca";
}

void Smartphone::exibirInfo() const {
    Eletronico::exibirInfo();
    cout << "  (Smartphone) " << getEspecificacoes() << "\n";
}
