#ifndef ALBUM_H
#define ALBUM_H

#include <string>
#include "Figurinha.h"
#include "Troca.h"
#include "Pagina.h"
#include "Persistencia.h"
using namespace std;

// Limites globais do projeto (arrays estáticos)
#define MAX_FIGURINHAS 100
#define MAX_PAGINAS    100
#define MAX_TROCAS     100
#define MAX_USUARIOS   100

class Album {
private:
    Figurinha figurinhas[MAX_FIGURINHAS]; // array de objetos
    int totalFigurinhas;

    Pagina paginas[MAX_PAGINAS];
    int totalPaginas;

    Troca trocasRecebidas[MAX_TROCAS];
    int totalTrocasRecebidas;

public:
    Album();
    ~Album();

    // constrói a partir do catálogo carregado do CSV
    void carregarCatalogo(CatalogoFig catalogo[], int quantidadeCatalogo);

    void mostrarPagina(int numeroPagina); // 1..totalPaginas (página 0 é a CAPA e é tratada fora)
    void listarColecao();
    void abrirPacote();

    bool colarFigurinha(int numero);
    bool disponibilizarParaTroca(int numero);

    // Trocas recebidas
    void adicionarTroca(Troca t);
    Troca* getTrocasRecebidasArray();
    int getQtdTrocasRecebidas();

    // Acesso utilitário
    int getTotalFigurinhas();
    Figurinha* getFigurinhasPtr();
    int getTotalPaginas();
};

#endif
