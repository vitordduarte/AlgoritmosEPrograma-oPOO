#ifndef ASSISTENTEVIRTUAL_H
#define ASSISTENTEVIRTUAL_H

#include <string>
using namespace std;

class AssistenteVirtual {
private:
    string nome;
    string idioma;
    string versao;
    int volume;
    bool microfoneAtivo;

public:
    AssistenteVirtual();
    AssistenteVirtual(string n, string i, string v, int vol, bool mic);

    void dizerOla();
    void executarComando(string cmd);
    void definirIdioma(string i);
    void atualizarVersao(string v);

    void setVolume(int vol);
    int getVolume();

    void setMicrofoneAtivo(bool ativo);
    bool getMicrofoneAtivo();

    void registrarLembrete(string lembrete);
    string resumoStatus();
};

#endif
