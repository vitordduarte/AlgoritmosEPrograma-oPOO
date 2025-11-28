#include "Cachorro.h"

Cachorro::Cachorro(string nome, string Som_bicho) : Animal(nome,Som_bicho)
{
    cout << "Cachorro " << this->nome << " foi criado!" << endl;
}

void Cachorro::fazerSom()
{
    cout << "Au au!!" << endl;
}


