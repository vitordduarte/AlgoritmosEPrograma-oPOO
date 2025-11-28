#ifndef COMPRA_H
#define COMPRA_H
#include <vector>

using namespace std;

#include "Produto.h"

class Compra {
    vector<Produto*> itens;
public:
    Compra();
    ~Compra();

    void adicionarItem(Produto* p); // tipo produto* nome da var p
    void removerItem(int index); // index do item 
    float calcularTotal() const;
    float calcularFreteTotal() const;

    // void salvarCSV(const string& arquivos) const; // verificar quando incluir csv

    bool vazia() const;
};
#endif
