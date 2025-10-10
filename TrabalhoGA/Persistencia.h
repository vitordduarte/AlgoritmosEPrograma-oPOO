#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <string>
using namespace std;

// Representa uma linha do catalogo de figurinhas.csv
struct CatalogoFig {
    int numero;
    string nome;
    string descricao; // no objeto Figurinha o campo equivalente chama "conteudo"
    int pagina;
};

// Representa uma linha de trocas.csv
struct LinhaTroca {
    string proponente;
    string destinatario;
    int figurinha_oferecida;
    int figurinha_requerida;
    int status; // 0 aguardando, 1 aceito, outros valores tratados como recusado (2)
};

// Representa uma linha de usuarios.csv
struct UsuarioCsv {
    string username;
    string senha;
};

// Carregar arquivos CSV (preenche arrays fixos e devolve a quantidade lida em outQuantidade)
bool carregarCatalogoFigurinhas(string caminho, CatalogoFig outCatalogo[], int maxItens, int& outQuantidade);
bool carregarUsuarios(string caminho, UsuarioCsv outUsuarios[], int maxItens, int& outQuantidade);
bool carregarTrocas(string caminho, LinhaTroca outTrocas[], int maxItens, int& outQuantidade);

// Salvar arquivos CSV (grava até "quantidade" itens)
bool salvarUsuarios(string caminho, UsuarioCsv usuarios[], int quantidade);
bool salvarTrocas(string caminho, LinhaTroca trocas[], int quantidade);

#endif
