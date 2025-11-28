#ifndef VESTUARIO_H
#define VESTUARIO_H
#include "Produto.h"

using namespace std;

class Vestuario : public Produto {
protected:
    string tamanho;
    string material;
public:
    Vestuario(const string &nome1="", float preco1=0.0, int estoque1=0, float peso1=0.0, const string &tamanho1="", const string &material1="");
    virtual ~Vestuario();

    virtual float calcularFrete() const override;
    virtual void exibirInfo() const override;

    string getTamanho() const;
    string getMaterial() const;
};
#endif
