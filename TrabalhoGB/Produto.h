#ifndef PRODUTO_H
#define PRODUTO_H
#include <string>
using namespace std;

class Produto {
protected:
    std::string nome;
    float preco;
    int estoque;
    float peso;
public:
    Produto(const string &n="", float p=0.0, int e=0, float w=0.0);
    virtual ~Produto();
    virtual float calcularFrete() const = 0;
    virtual void exibirInfo() const;
    float getPreco() const;
};
#endif
