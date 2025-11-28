#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

using namespace std;

class Animal {
    //atributos
    protected:
        string nome;
        string Som_bicho;

    public:
        //metodos
        Animal(); //construtor padrao
        Animal(string nome, string Som_bicho); //   construtor personalizado
      //  ~Animal(); //destrutor

        //metodo virtual
        virtual void fazerSom() = 0;
        virtual ~Animal(); // É boa prática ter um destrutor virtual na classe base
};

#endif
