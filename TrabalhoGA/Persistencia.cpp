#include "Persistencia.h"
#include <fstream>
#include <sstream>
using namespace std;

// Parser CSV simples usando stringstream e getline
// Não trata aspas; separa colunas por vírgula.
static int dividirCSV(const string& linha, string colunas[], int maxColunas) {
    int quantidade = 0;
    string item;
    stringstream ss(linha);
    while (quantidade < maxColunas && getline(ss, item, ',')) {
        colunas[quantidade] = item;
        quantidade = quantidade + 1;
    }
    return quantidade;
}

bool carregarCatalogoFigurinhas(string caminho, CatalogoFig outCatalogo[], int maxItens, int& outQuantidade) {
    ifstream arquivo(caminho.c_str());
    if (!arquivo.is_open()) {
        outQuantidade = 0;
        return false;
    }

    string linha;
    outQuantidade = 0;

    // descartar cabeçalho
    if (!getline(arquivo, linha)) {
        arquivo.close();
        return false;
    }

    while (getline(arquivo, linha)) {
        if ((int)linha.size() == 0) {
            continue;
        }
        if (outQuantidade >= maxItens) {
            break;
        }

        string colunas[4];
        int lidas = dividirCSV(linha, colunas, 4);
        if (lidas < 4) {
            continue;
        }

        CatalogoFig cf;
        cf.numero = atoi(colunas[0].c_str());
        cf.nome = colunas[1];
        cf.descricao = colunas[2]; // mapeado para Figurinha.conteudo
        cf.pagina = atoi(colunas[3].c_str());

        outCatalogo[outQuantidade] = cf;
        outQuantidade = outQuantidade + 1;
    }
    arquivo.close();
    return true;
}

bool carregarUsuarios(string caminho, UsuarioCsv outUsuarios[], int maxItens, int& outQuantidade) {
    ifstream arquivo(caminho.c_str());
    if (!arquivo.is_open()) {
        outQuantidade = 0;
        return false;
    }

    string linha;
    outQuantidade = 0;

    // cabeçalho
    if (!getline(arquivo, linha)) {
        arquivo.close();
        return false;
    }

    while (getline(arquivo, linha)) {
        if ((int)linha.size() == 0) {
            continue;
        }
        if (outQuantidade >= maxItens) {
            break;
        }

        string colunas[2];
        int lidas = dividirCSV(linha, colunas, 2);
        if (lidas < 2) {
            continue;
        }

        UsuarioCsv uc;
        uc.username = colunas[0];
        uc.senha = colunas[1];

        outUsuarios[outQuantidade] = uc;
        outQuantidade = outQuantidade + 1;
    }
    arquivo.close();
    return true;
}

bool carregarTrocas(string caminho, LinhaTroca outTrocas[], int maxItens, int& outQuantidade) {
    ifstream arquivo(caminho.c_str());
    if (!arquivo.is_open()) {
        outQuantidade = 0;
        return false;
    }

    string linha;
    outQuantidade = 0;

    // cabeçalho
    if (!getline(arquivo, linha)) {
        arquivo.close();
        return false;
    }

    while (getline(arquivo, linha)) {
        if ((int)linha.size() == 0) {
            continue;
        }
        if (outQuantidade >= maxItens) {
            break;
        }

        string colunas[5];
        int lidas = dividirCSV(linha, colunas, 5);
        if (lidas < 5) {
            continue;
        }

        LinhaTroca lt;
        lt.proponente = colunas[0];
        lt.destinatario = colunas[1];
        lt.figurinha_oferecida = atoi(colunas[2].c_str());
        lt.figurinha_requerida = atoi(colunas[3].c_str());
        lt.status = atoi(colunas[4].c_str());

        outTrocas[outQuantidade] = lt;
        outQuantidade = outQuantidade + 1;
    }
    arquivo.close();
    return true;
}

bool salvarUsuarios(string caminho, UsuarioCsv usuarios[], int quantidade) {
    ofstream arquivo(caminho.c_str());
    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "username,senha\n";
    for (int i = 0; i < quantidade; i = i + 1) {
        arquivo << usuarios[i].username << "," << usuarios[i].senha << "\n";
    }
    arquivo.close();
    return true;
}

bool salvarTrocas(string caminho, LinhaTroca trocas[], int quantidade) {
    ofstream arquivo(caminho.c_str());
    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "proponente,destinatario,figurinha_oferecida,figurinha_requerida,status\n";
    for (int i = 0; i < quantidade; i = i + 1) {
        arquivo << trocas[i].proponente << ","
                << trocas[i].destinatario << ","
                << trocas[i].figurinha_oferecida << ","
                << trocas[i].figurinha_requerida << ","
                << trocas[i].status << "\n";
    }
    arquivo.close();
    return true;
}
