#ifndef COMPRA_H
#define COMPRA_H
#include <vector>
#include <string>

using namespace std;

#include "Produto.h"

class Compra {
    vector<Produto*> itens;  // Itens da compra (polimorfismo)
    string data;             // Data da compra (opcional, simples)
    float valorTotal;        // Cache do valor total
public:
    Compra();
    ~Compra();

    void adicionarItem(Produto* p); // adiciona um ponteiro de Produto ao vetor
    void removerItem(int index);    // remove pelo índice

    float calcularTotal() const;        // soma de preços
    float calcularFreteTotal() const;   // soma de fretes

    bool vazia() const;

    // Exibe os itens e totais (para menu)
    void exibirResumoCompra() const;

    // Opcional: definir data se quiser usar
    void setData(const string &data1);
    string getData() const;

    // Persistência em CSV
    void salvarCSV(const string &nomeArquivo) const;
    void carregarCSV(const string &nomeArquivo);
};
#endif
