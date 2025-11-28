m#include "Produto.h"
#include <iostream>

using namespace std;

Produto::Produto(const string &nome1, float preco1, int estoque1, float peso1)
    : nome(nome1), preco(preco1), estoque(estoque1), peso(peso1) {}

Produto::~Produto() {}

float Produto::getPreco() const {
  return preco;
}
string Produto::getNome() const
{ return nome;
}

void Produto::exibirInfo() const {
    cout << nome << " | R$ " << preco << " | Estoque: " << estoque << " | Peso: " << peso << "kg\n";
}
