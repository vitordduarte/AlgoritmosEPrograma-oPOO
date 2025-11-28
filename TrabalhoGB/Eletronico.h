#ifndef ELETRONICO_H
#define ELETRONICO_H
#include "Produto.h"

using namespace std;

class Eletronico : public Produto {
protected:
    int tensao;
    int garantiaMeses;
public:
    // Inclui dados de Produto + tensão + garantia
    Eletronico(const string &nome1 = "", float preco1 = 0.0, int estoque1 = 0, float peso1 = 0.0,
               int tensao1 = 0, int garantiaMeses1 = 0);
    virtual ~Eletronico();

    virtual float calcularFrete() const override;
    virtual void exibirInfo() const override;

    int getTensao() const;
    int getGarantia() const;
};
#endif
