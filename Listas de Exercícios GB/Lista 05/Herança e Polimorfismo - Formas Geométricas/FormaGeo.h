#ifndef FORMAGEO_H
#define FORMAGEO_H

#include <iostream>
#include <string>

using namespace std;

class FormaGeo{
    //atributos
    protected:
        string nome;

    public:
        //metodos
        FormaGeo(); //construtor padrao
        FormaGeo(string nome); //   construtor personalizado

        //metodos virtuais
        virtual void calcularArea() = 0;
        virtual void calcularPerimetro() = 0;

        virtual ~FormaGeo(); // É boa prática ter um destrutor virtual na classe base
};

#endif
