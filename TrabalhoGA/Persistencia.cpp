#include "Persistencia.h"
#include <fstream>
#include <sstream>
using namespace std;

//dividirCSV: separa uma linha por vírgulas em até maxColunas.
int dividirCSV(const string& linha, string colunas[], int maxColunas) {
    int quantidade = 0;
    string item;
    stringstream ss(linha); //permite ler “como se fosse” um stream.
    while (quantidade < maxColunas && getline(ss, item, ',')) //lê até a próxima vírgula.
    {
        colunas[quantidade] = item; // Para cada campo lido, guarda em coluna
        quantidade = quantidade + 1; // incrementa em quantidade
    }
    return quantidade; // Retorna quantidade, ou seja, quantos campos foram de fato lidos
}

/*
    carregarCatalogoFigurinhas: lê figurinhas.csv, ignora cabeçalho, preenche CatalogoFig[].
    Retorna true se abriu o arquivo e leu o cabeçalho.
*/
bool carregarCatalogoFigurinhas(string caminho, CatalogoFig outCatalogo[], int maxItens, int& outQuantidade) {
    ifstream arquivo(caminho.c_str());
   
    // Se falhar em abrir, retorna false
    if (!arquivo.is_open()) {
        outQuantidade = 0;
        return false;
    }

    string linha;
    outQuantidade = 0;
    //O código tenta ler a primeira linha (cabeçalho) do arquivo. 
    //Se não consegue, ele considera o arquivo inválido e retorna
    if (!getline(arquivo, linha)) {
        arquivo.close();
        return false;
    }


    while (getline(arquivo, linha)) {
        if ((int)linha.size() == 0) {
            continue; // pula linha em branco
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

        outCatalogo[outQuantidade] = cf;// copia struct para o array
        outQuantidade = outQuantidade + 1;
    }
    arquivo.close();
    return true;
}

/*
    carregarUsuarios: lê usuarios.csv, ignora cabeçalho, preenche UsuarioCsv[].
    mesme lógica que o anterior, mas espera duas colunas
*/
bool carregarUsuarios(string caminho, UsuarioCsv outUsuarios[], int maxItens, int& outQuantidade) {
    
    ifstream arquivo(caminho.c_str());//devolve um ponteiro para uma string
    
    if (!arquivo.is_open()) {
        outQuantidade = 0;
        return false;
    }

    string linha;
    outQuantidade = 0;

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

/*
    carregarTrocas: lê trocas.csv, ignora cabeçalho, preenche LinhaTroca[].
*/
bool carregarTrocas(string caminho, LinhaTroca outTrocas[], int maxItens, int& outQuantidade) {
   
    ifstream arquivo(caminho.c_str());
   
    if (!arquivo.is_open()) {
        outQuantidade = 0;
        return false;
    }

    string linha;
    outQuantidade = 0;

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

/*
    salvarUsuarios: sobrescreve usuarios.csv com cabeçalho + linhas.
    Usa ios::trunc + flush + close para garantir persistência.
*/
bool salvarUsuarios(string caminho, UsuarioCsv usuarios[], int quantidade) {
    
    ofstream arquivo(caminho.c_str(), ios::out | ios::trunc);
   
    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "username,senha\n";
    for (int i = 0; i < quantidade; i = i + 1) {
        arquivo << usuarios[i].username << "," << usuarios[i].senha << "\n";
    }

    arquivo.flush();
    arquivo.close();
    return true;
}

/*
    salvarTrocas: sobrescreve trocas.csv com cabeçalho + linhas.
*/
bool salvarTrocas(string caminho, LinhaTroca trocas[], int quantidade) {
    ofstream arquivo(caminho.c_str(), ios::out | ios::trunc);
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
    arquivo.flush();
    arquivo.close();
    return true;
}
