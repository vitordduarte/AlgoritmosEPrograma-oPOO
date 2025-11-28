#ifndef MAGO_ROXO_H
#define MAGO_ROXO_H

#include "Mago.h"

class MagoRoxo: public Mago { //magoroxo 'é um' Mago (herança publica)
public:
//construtor do mago roxo
    MagoRoxo(string nome, int idade, int poder, string escolaDeMagia);
    //metodo especifico desta classe
    void bolaDeFogo();

protected:
    int poderFogo;

};

#endif