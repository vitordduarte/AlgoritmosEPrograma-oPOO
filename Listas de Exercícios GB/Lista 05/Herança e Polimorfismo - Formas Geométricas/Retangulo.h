#ifndef RETANGULO_H
#define RETANGULO_H

#include "FormaGeo.h"

class Retangulo : public FormaGeo{
    public:
    //Atributos
    float Base;
    float Altura;

    //Metodos
    Retangulo(float Base, float Altura);
    Retangulo(string nome);
    virtual void calcularArea();
    virtual void calcularPerimetro();

};

#endif