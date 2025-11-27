#include "Produto.h"
#include <iostream>

using namespace std;

Produto::Produto(const std::string &n, float p, int e, float w)
    : nome(n), preco(p), estoque(e), peso(w) {}

Produto::~Produto() {}

float Produto::getPreco() const {
  return preco;
}
string Produto::getNome() const
{ return nome; }

void Produto::exibirInfo() const {
    std::cout << nome << " | R$ " << preco << " | Estoque: " << estoque << " | Peso: " << peso << "kg\n";
}
