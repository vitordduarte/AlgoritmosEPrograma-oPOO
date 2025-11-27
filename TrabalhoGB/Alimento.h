#ifndef ALIMENTO_H
#define ALIMENTO_H
#include "Produto.h"


using namespace std;

class Alimento : public Produto {
protected:
    string dataValidade;
    string tipoAlimento;
public:
    Alimento(const string &n="", float p=0.0, int e=0, float w=0.0, const string &d="", const string &t="");
    virtual ~Alimento();

    virtual float calcularFrete() const override;
    virtual void exibirInfo() const override;

    std::string getDataValidade() const;
};
#endif
