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
    Produto(const string &nome1="", float preco1=0.0, int estoque1=0, float peso1=0.0);
    virtual ~Produto();
    virtual float calcularFrete() const = 0;
    virtual void exibirInfo() const;
    float getPreco() const;
};
#endif
