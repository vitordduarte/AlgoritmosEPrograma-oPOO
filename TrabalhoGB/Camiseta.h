#ifndef CAMISETA_H
#define CAMISETA_H
#include "Vestuario.h"
using namespace std

class Camiseta : public Vestuario {
    string estampa;
public:
    Camiseta(const string &nome1="", float preco1=0.0, int estoque1=0, float peso1=0.0, const string &tamanho1="", const string &material1="", const string &estampa1="");
    virtual ~Camiseta();
    std::string getEstampa() const;
    virtual void exibirInfo() const override;
};
#endif
