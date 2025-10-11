#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Figurinha.h"
#include "Troca.h"
#include "Pagina.h"
#include "Persistencia.h"
using namespace std;

/*
    Constantes de limites de arrays estáticos (sem arquivo limites.h separado).
*/
#define MAX_FIGURINHAS 100
#define MAX_PAGINAS    100
#define MAX_TROCAS     100
#define MAX_USUARIOS   100

/*
    Classe Album
    -------------
    Cada usuário possui **um** Album como membro (não é ponteiro).
    O álbum guarda:
    - um array de Figurinhas;
    - um array de Páginas (faixas numéricas do catálogo);
    - um array de Trocas **recebidas** (solicitações endereçadas ao dono deste álbum).
*/
class Album {
private:
    Figurinha figurinhas[MAX_FIGURINHAS];
    int totalFigurinhas;

    Pagina paginas[MAX_PAGINAS];
    int totalPaginas;

    Troca trocasRecebidas[MAX_TROCAS];
    int totalTrocasRecebidas;

public:
    Album();
    ~Album();

    /*
        carregarCatalogo(catalogo[], qtd):
        - Lê o catálogo em memória e monta o álbum do usuário:
           * Inicializa **todas** as figurinhas como FALTANDO (-1).
           * Popula título/faixas das páginas.
           * Define totalFigurinhas e totalPaginas.
        - Cada usuário tem seu próprio álbum; todos partem faltando tudo.
    */
    void carregarCatalogo(CatalogoFig catalogo[], int quantidadeCatalogo);

    // Exibições | ações básicas
    void mostrarPagina(int numeroPagina);
    void listarColecao();
    void abrirPacote(); // aleatório: sorteia 3 números e adiciona se faltando

    bool colarFigurinha(int numero);
    bool disponibilizarParaTroca(int numero);

    // Funções usadas no aceite de trocas (garantindo consistência dos dois álbuns)
    bool possuiNaoColada(int numero);
    bool perderNaoColada(int numero);
    void ganharOuManter(int numero);

    // Visualização em matriz por página (apenas não coladas)
    void mostrarColecaoMatrizPorPagina(int indicePagina1Base);

    // Trocas recebidas
    void adicionarTroca(Troca t);
    Troca* getTrocasRecebidasArray();
    int getQtdTrocasRecebidas();

    // Acesso geral
    int getTotalFigurinhas();
    Figurinha* getFigurinhasPtr();
    int getTotalPaginas();

    // Acesso às faixas de uma página (1..N) - útil para a matriz
    int getPaginaMinNro(int indicePagina1Base);
    int getPaginaMaxNro(int indicePagina1Base);
};

#endif
