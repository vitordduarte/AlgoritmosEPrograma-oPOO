#include "Album.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Album::Album() {
    totalFigurinhas = 0;
    totalPaginas = 0;
    totalTrocasRecebidas = 0;

    // Mantém aleatoriedade do "abrirPacote"
    // srand inicializa a semente do gerador de números aleatórios com a hora atual.
    // Isso faz com que os pacotes sejam diferentes entre execuções.
    srand((unsigned)time(0));
}

Album::~Album() {
    // Não há alocação dinâmica aqui; nada para liberar manualmente.
}

void Album::carregarCatalogo(CatalogoFig catalogo[], int quantidadeCatalogo) {
    // Zera contadores
    totalFigurinhas = 0;
    totalPaginas = 0;

    if (quantidadeCatalogo <= 0) {
        return;
    }

    // Descobrir maior número de figurinha e maior página
    int maiorNumero = 0;
    int maiorPagina = 0;
    for (int i = 0; i < quantidadeCatalogo; i = i + 1) {
        if (catalogo[i].numero > maiorNumero) {
            maiorNumero = catalogo[i].numero;
        }
        if (catalogo[i].pagina > maiorPagina) {
            maiorPagina = catalogo[i].pagina;
        }
    }
    if (maiorNumero > MAX_FIGURINHAS) {
        maiorNumero = MAX_FIGURINHAS;
    }
    if (maiorPagina > MAX_PAGINAS - 1) {
        maiorPagina = MAX_PAGINAS - 1; // páginas 1..N (0 é capa)
    }

    // Preenche figurinhas por número (1..maiorNumero)
    for (int n = 1; n <= maiorNumero; n = n + 1) {
        // procurar entrada n no catálogo
        string nome = "Fig " + to_string(n);
        string conteudo = "";
        int pagina = 1;
        for (int i = 0; i < quantidadeCatalogo; i = i + 1) {
            if (catalogo[i].numero == n) {
                nome = catalogo[i].nome;
                conteudo = catalogo[i].descricao; // mapeia "descricao" -> Figurinha.conteudo
                pagina = catalogo[i].pagina;
                break;
            }
        }
        figurinhas[n - 1] = Figurinha(n, nome, conteudo, pagina, 0);
    }
    totalFigurinhas = maiorNumero;

    // Criar páginas 1..maiorPagina (página 0 é capa e tratada fora)
    // Para exibição, precisamos da faixa [min,max] por página
    for (int p = 1; p <= maiorPagina; p = p + 1) {
        int minN = 0;
        int maxN = 0;
        for (int i = 0; i < quantidadeCatalogo; i = i + 1) {
            if (catalogo[i].pagina == p) {
                if (minN == 0 || catalogo[i].numero < minN) {
                    minN = catalogo[i].numero;
                }
                if (maxN == 0 || catalogo[i].numero > maxN) {
                    maxN = catalogo[i].numero;
                }
            }
        }
        if (minN != 0 && maxN != 0) {
            paginas[totalPaginas] = Pagina("Página " + to_string(p), minN, maxN);
            totalPaginas = totalPaginas + 1;
        }
    }
}

void Album::mostrarPagina(int numeroPagina) {
    if (numeroPagina < 1 || numeroPagina > totalPaginas) {
        cout << "Página inválida.\n";
        return;
    }
    paginas[numeroPagina - 1].mostrar(figurinhas, totalFigurinhas);
}

void Album::listarColecao() {
    cout << "\n=== Suas Figurinhas (não coladas) ===\n";
    bool tem = false;
    for (int i = 0; i < totalFigurinhas; i = i + 1) {
        int st = figurinhas[i].getStatus();
        if (st == 0 || st == 2) {
            tem = true;
            figurinhas[i].resumo();
        }
    }
    if (!tem) {
        cout << "Você não possui figurinhas na coleção.\n";
    }
}

void Album::abrirPacote() {
    if (totalFigurinhas <= 0) {
        return;
    }
    cout << "\nAbrindo pacote...\n";
    // Escolhe 3 figurinhas aleatórias
    for (int i = 0; i < 3; i = i + 1) {
        int indice = rand() % totalFigurinhas; // 0..total-1
        Figurinha& f = figurinhas[indice];
        cout << "Você ganhou a figurinha " << f.getNumero() << " - " << f.getNome() << "!\n";
    }
}

bool Album::colarFigurinha(int numero) {
    if (numero < 1 || numero > totalFigurinhas) {
        return false;
    }
    Figurinha& f = figurinhas[numero - 1];
    if (f.getStatus() == 0) {
        f.colar();
        return true;
    }
    return false;
}

bool Album::disponibilizarParaTroca(int numero) {
    if (numero < 1 || numero > totalFigurinhas) {
        return false;
    }
    Figurinha& f = figurinhas[numero - 1];
    if (f.getStatus() == 0) {
        f.disponibilizarParaTroca();
        return true;
    }
    return false;
}

void Album::adicionarTroca(Troca t) {
    if (totalTrocasRecebidas < MAX_TROCAS) {
        trocasRecebidas[totalTrocasRecebidas] = t;
        totalTrocasRecebidas = totalTrocasRecebidas + 1;
    }
}

Troca* Album::getTrocasRecebidasArray() {
    return trocasRecebidas;
}

int Album::getQtdTrocasRecebidas() {
    return totalTrocasRecebidas;
}

int Album::getTotalFigurinhas() {
    return totalFigurinhas;
}

Figurinha* Album::getFigurinhasPtr() {
    return figurinhas;
}

int Album::getTotalPaginas() {
    return totalPaginas;
}
