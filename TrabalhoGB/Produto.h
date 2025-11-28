#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
using namespace std;

class Produto {
protected:
    string nome;
    float preco;
    int estoque;
    float peso;
public:
    Produto(const string &nome1 = "", float preco1 = 0.0, int estoque1 = 0, float peso1 = 0.0);
    virtual ~Produto();

    // Método puramente virtual para obrigar as classes filhas a implementarem o frete
    virtual float calcularFrete() const = 0;

    // Exibe informações básicas do produto
    virtual void exibirInfo() const;

    // Getters simples
    float getPreco() const;
    string getNome() const;
};
#endif
