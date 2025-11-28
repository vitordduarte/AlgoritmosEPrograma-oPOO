#ifndef CACHORRO_H
#define CACHORRO_H

#include "Animal.h"

class Cachorro : public Animal{
    public:
    Cachorro(string nome, string Som_bicho);
    virtual void fazerSom();
};

#endif