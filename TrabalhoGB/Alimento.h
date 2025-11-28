#ifndef ALIMENTO_H
#define ALIMENTO_H
#include "Produto.h"


using namespace std;

class Alimento : public Produto {
protected:
    string dataValidade;
    string tipoAlimento;
public:
    Alimento(const string &nome1="", float preco1=0.0, int estoque1=0, float peso1=0.0, const string &dataValidade1="", const string &tipoAlimento1="");
    virtual ~Alimento();

    virtual float calcularFrete() const override;
    virtual void exibirInfo() const override;

    string getDataValidade() const;
};
#endif
