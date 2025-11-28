#ifndef MAGO_CINZA_H
#define MAGO_CINZA_H

#include "Mago.h"

class MagoCinza: public Mago { //magocinza 'é um' Mago (herança publica)
public:
//construtor do mago cinza
    MagoCinza(string nome, int idade, int poder, string escolaDeMagia);
    //metodo especifico desta classe
    void falarComAnimais();

protected:
    int numeroAnimais;

};

#endif