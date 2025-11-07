#ifndef CORPOCELESTE_H
#define CORPOCELESTE_H

#include <string>
using namespace std;

enum TipoCorpo { Estrela, Planeta, Lua, Asteroide, Cometa, Outro };

class CorpoCeleste {
private:
    string nome;
    TipoCorpo tipo;
    double massaKg;
    double raioKm;

public:
    CorpoCeleste();
    CorpoCeleste(string n, TipoCorpo t, double m, double r);

    string getNome();
    void setNome(string n);

    // (outros getters e setters)

    double calcularDensidade();
    double gravidadeSuperficial();
    string descricao();
};

#endif
