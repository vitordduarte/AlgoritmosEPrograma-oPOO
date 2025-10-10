#ifndef SMARTHOUSE_H
#define SMARTHOUSE_H

#include <string>
using namespace std;

class SmartHouse {
private:
    bool luzesLigadas;
    double temperaturaDesejada;
    bool alarmeAtivo;
    bool portaTrancada;
    string modo;

public:
    SmartHouse();
    SmartHouse(bool luz, double temp, bool alarme, bool porta, string m);

    void ligarLuzes();
    void desligarLuzes();

    void setTemperaturaDesejada(double temp);
    double getTemperaturaDesejada();

    void ativarAlarme();
    void desativarAlarme();

    void trancarPorta();
    void destrancarPorta();

    void setModo(string m);
    string getModo();

    string status();
    void aplicarCena(string cena);
};

#endif
