#ifndef SMARTPHONE_H
#define SMARTPHONE_H

using namespace std;

#include "Eletronico.h"

class Smartphone : public Eletronico {
    int armazenamento;
    string marca;
public:
    Smartphone(const string &n="", float p=0.0, int e=0, float w=0.0, int t=0, int g=0, int armaz=0, int &marca="");
    virtual ~Smartphone();
    string getEspecificacoes() const;
    virtual void exibirInfo() const override;
};
#endif
