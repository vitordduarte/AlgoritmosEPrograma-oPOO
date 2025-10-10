#ifndef FIGURINHA_H
#define FIGURINHA_H

#include <string>
using namespace std;

// A classe representa uma figurinha do álbum.
// status: 0 = na coleção (ainda não colada), 1 = colada, 2 = disponível para troca.
// O campo "conteudo" corresponde ao campo "descricao" do CSV.
class Figurinha {
private:
    int numero;      // número identificador da figurinha
    string nome;     // nome exibido
    string conteudo; // descrição da figurinha (no CSV: "descricao")
    int status;      // 0 na coleção, 1 colada, 2 disponível para troca
    int nroPagina;   // página em que a figurinha pertence

public:
    Figurinha();
    Figurinha(int numero, string nome, string conteudo, int nroPagina, int status);

    // Getters (sem const por preferência do projeto)
    int getNumero();
    string getNome();
    string getConteudo();
    int getStatus();
    int getNroPagina();

    // Setters
    void setStatus(int novoStatus);

    // Ações
    void colar();
    void disponibilizarParaTroca();

    // Utilitário: apenas imprime no console (sem retornar string)
    void resumo();
};

#endif
