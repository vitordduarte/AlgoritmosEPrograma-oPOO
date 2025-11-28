#ifndef MAGO_BRANCO_H
#define MAGO_BRANCO_H

#include "Mago.h"

class MagoBranco: public Mago { //magobranco 'é um' Mago (herança publica)
public:
//construtor do mago branco
    MagoBranco(string nome, int idade, int poder, string escolaDeMagia);
    //metodo especifico desta classe
    void lancarCura();

protected:
    int poderCura;

};

#endif