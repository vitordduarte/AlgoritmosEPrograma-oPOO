#ifndef ELETRONICO_H
#define ELETRONICO_H
#include "Produto.h"

using namespace std;

class Eletronico : public Produto {
protected:
    int tensao;
    int garantiaMeses;
public:
    Eletronico(const string &n="", float p=0.0, int e=0, float w=0.0, int t=0, int g=0); //incluindo as 4 var de produto + 2 do eletronico
    virtual ~Eletronico();
    virtual float calcularFrete() const override;
    virtual void exibirInfo() const override;
    int gettensao() const;
    int getGarantia() const;
};
#endif
