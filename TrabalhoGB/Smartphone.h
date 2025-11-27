#include "Smartphone.h"
#include <iostream>


using namespace std;

Smartphone::Smartphone(const string &n, float p, int e, float w, int v, int g, int ar, int mar) // aqui ele herda de eletronico que herda de produto
    : Eletronico(n,p,e,w,v,g), armazenamento(ar), marca(cam) {}

Smartphone::~Smartphone() {}

std::string Smartphone::getEspecificacoes() const {
    return std::to_string(armazenamento) + "GB, " + std::to_string(camera) + "MP";
}

void Smartphone::exibirInfo() const {
    Eletronico::exibirInfo();
    std::cout << "  (Smartphone) " << getEspecificacoes() << "\n";
}
