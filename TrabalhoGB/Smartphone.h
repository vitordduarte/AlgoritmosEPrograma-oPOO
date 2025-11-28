#ifndef SMARTPHONE_H
#define SMARTPHONE_H

using namespace std;

#include "Eletronico.h"

class Smartphone : public Eletronico {
    int armazenamento;
    string marca;
public:
    Smartphone(const string &nome1="", float preco1=0.0, int estoque1=0, float peso1=0.0, int tensao1=0, int garantiaMeses1=0, int armazenamento1=0, string &marca1="");
    virtual ~Smartphone();

    string getEspecificacoes() const;
    virtual void exibirInfo() const override;
};
#endif
