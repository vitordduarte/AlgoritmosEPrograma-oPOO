#ifndef VESTUARIO_H
#define VESTUARIO_H
#include "Produto.h"

using namespace std;

class Vestuario : public Produto {
protected:
    string tamanho;
    string material;
public:
    Vestuario(const std::string &n="", float p=0.0, int e=0, float w=0.0, const string &t="", const string &m="");
    virtual ~Vestuario();

    virtual float calcularFrete() const override;
    virtual void exibirInfo() const override;

    string getTamanho() const;
    string getMaterial() const;
};
#endif
