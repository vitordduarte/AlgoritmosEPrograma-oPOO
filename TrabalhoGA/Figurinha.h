#ifndef FIGURINHA_H
#define FIGURINHA_H

#include <string>
using namespace std;

/*
    Representa uma figurinha do álbum.
    status: -1 = faltando, 0 = na coleção (não colada), 1 = colada, 2 = disponível para troca.
*/
class Figurinha {
private:
    int numero;
    string nome;
    string conteudo;
    int status;
    int nroPagina;

public:
      
     //Construtores padrão: zera campos e define status -1 (faltando) para deixar claro
     //que um usuário novo começa SEM nenhuma figurinha.
    Figurinha();
    Figurinha(int numero, string nome, string conteudo, int nroPagina, int status);

    // Getters simples
    int getNumero();
    string getNome();
    string getConteudo();
    int getStatus();
    int getNroPagina();

    // Setter de status (permite mudar livremente quando necessário)
    void setStatus(int novoStatus);

    
    //colar(): se estiver na coleção (0), cola (1).
    //disponibilizarParaTroca(): se estiver na coleção (0), vira disponível (2).
    // resumo(): imprime linha amigável para depuração/listagem.
    void colar();
    void disponibilizarParaTroca();
    void resumo();
};

#endif
