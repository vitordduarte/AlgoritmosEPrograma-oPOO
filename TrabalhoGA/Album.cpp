#include "Album.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

Album::Album() {
    totalFigurinhas = 0;
    totalPaginas = 0;
    totalTrocasRecebidas = 0;
    srand((unsigned)time(0)); // semente para aleatoriedade (abrirPacote)
}

Album::~Album() {}

void Album::carregarCatalogo(CatalogoFig catalogo[], int quantidadeCatalogo) {
    totalFigurinhas = 0;
    totalPaginas = 0;

    if (quantidadeCatalogo <= 0) {
        return;
    }

    // Descobre os limites do catálogo
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
        maiorPagina = MAX_PAGINAS - 1;
    }

    // Inicializa TODAS as figurinhas como FALTANDO (-1) para este usuário
    for (int n = 1; n <= maiorNumero; n = n + 1) {
        string nome = "Fig " + to_string(n);
        string conteudo = "";
        int pagina = 1;
        for (int i = 0; i < quantidadeCatalogo; i = i + 1) {
            if (catalogo[i].numero == n) {
                nome = catalogo[i].nome;
                conteudo = catalogo[i].descricao;
                pagina = catalogo[i].pagina;
                break;
            }
        }
        figurinhas[n - 1] = Figurinha(n, nome, conteudo, pagina, -1); // começa faltando
    }
    totalFigurinhas = maiorNumero;

    // Cria as páginas a partir do catálogo (min/max por página)
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
    /*
        Lista todas as figurinhas que o usuário possui mas ainda não colou
        (status 0) e também as disponíveis (2). Ajuda para operações manuais.
    */
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
    /*
        Simula a abertura de um pacote com 3 figurinhas sorteadas uniformemente.
        - Se a figurinha estava faltando (-1), passa a 0 (ganha).
        - Se já possuía (0/1/2), informa que é duplicata (sem alterar status).
        Observação: aleatoriedade com srand() no construtor do Álbum.
    */
    if (totalFigurinhas <= 0) {
        return;
    }
    cout << "\nAbrindo pacote...\n";
    for (int i = 0; i < 3; i = i + 1) {
        int indice = rand() % totalFigurinhas;
        Figurinha& f = figurinhas[indice];
        cout << "Você ganhou a figurinha " << f.getNumero() << " - " << f.getNome() << "!\n";
        if (f.getStatus() < 0) {
            f.setStatus(0); // faltando -> passa a possuir (não colada)
            cout << "Nova figurinha adicionada à sua coleção.\n";
        } else {
            cout << "Você já possuía essa figurinha.\n";
        }
    }
}

bool Album::colarFigurinha(int numero) {
    // Cola apenas se o usuário possui a figurinha e ela ainda não foi colada
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
    // Marca como disponível para troca se possui e não está colada
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

bool Album::possuiNaoColada(int numero) {
    // Útil para validar uma troca: só pode ceder se a figurinha está 0/2 (não colada)
    if (numero < 1 || numero > totalFigurinhas) {
        return false;
    }
    int st = figurinhas[numero - 1].getStatus();
    if (st == 0 || st == 2) {
        return true;
    }
    return false;
}

bool Album::perderNaoColada(int numero) {
    // Aplica a "saída" de uma figurinha numa troca: 0/2 -> -1 (faltando)
    if (numero < 1 || numero > totalFigurinhas) {
        return false;
    }
    int st = figurinhas[numero - 1].getStatus();
    if (st == 0 || st == 2) {
        figurinhas[numero - 1].setStatus(-1);
        return true;
    }
    return false;
}

void Album::ganharOuManter(int numero) {
    // Aplica a "entrada" de uma figurinha numa troca: se faltava (<0), vira 0; caso contrário, mantém
    if (numero < 1 || numero > totalFigurinhas) {
        return;
    }
    int st = figurinhas[numero - 1].getStatus();
    if (st < 0) {
        figurinhas[numero - 1].setStatus(0);
    }
}

void Album::mostrarColecaoMatrizPorPagina(int indicePagina1Base) {
    /*
        Exibe apenas figurinhas não coladas (0 ou 2) em forma de "matriz" por página.
        - Puxa a faixa min..max da página e imprime os números que o usuário possui e ainda não colou.
        - 10 colunas por linha para visualização.
    */
    if (indicePagina1Base < 1 || indicePagina1Base > totalPaginas) {
        cout << "(Página inválida)\n";
        return;
    }
    int minN = paginas[indicePagina1Base - 1].getMinNro();
    int maxN = paginas[indicePagina1Base - 1].getMaxNro();
    cout << "---- Coleção (não coladas) - Página " << indicePagina1Base << " ----\n";

    int colunas = 10;
    int contadorNaLinha = 0;
    bool algum = false;

    for (int n = minN; n <= maxN; n = n + 1) {
        if (n >= 1 && n <= totalFigurinhas) {
            int st = figurinhas[n - 1].getStatus();
            if (st == 0 || st == 2) {
                algum = true;
                cout << setw(3) << n << " ";
                contadorNaLinha = contadorNaLinha + 1;
                if (contadorNaLinha >= colunas) {
                    cout << "\n";
                    contadorNaLinha = 0;
                }
            }
        }
    }
    if (!algum) {
        cout << "(sem figurinhas não coladas nesta página)\n";
    } else if (contadorNaLinha != 0) {
        cout << "\n";
    }
    cout << "----------------------------------------\n";
}

void Album::adicionarTroca(Troca t) {
    // Armazena a solicitação recebida. Não há remoção aqui; o status controla exibição/efeito.
    if (totalTrocasRecebidas < MAX_TROCAS) {
        trocasRecebidas[totalTrocasRecebidas] = t;
        totalTrocasRecebidas = totalTrocasRecebidas + 1;
    }
}

Troca* Album::getTrocasRecebidasArray() { return trocasRecebidas; }
int Album::getQtdTrocasRecebidas() { return totalTrocasRecebidas; }
int Album::getTotalFigurinhas() { return totalFigurinhas; }
Figurinha* Album::getFigurinhasPtr() { return figurinhas; }
int Album::getTotalPaginas() { return totalPaginas; }

int Album::getPaginaMinNro(int indicePagina1Base) {
    if (indicePagina1Base < 1 || indicePagina1Base > totalPaginas) { return 0; }
    return paginas[indicePagina1Base - 1].getMinNro();
}
int Album::getPaginaMaxNro(int indicePagina1Base) {
    if (indicePagina1Base < 1 || indicePagina1Base > totalPaginas) { return 0; }
    return paginas[indicePagina1Base - 1].getMaxNro();
}
