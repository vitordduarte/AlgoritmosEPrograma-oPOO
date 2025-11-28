#include "Animal.h"

Animal::Animal()
{
    //Inicialização dentro do bloco de código (só precisa uma das formas)
    nome="";
    Som_bicho="";
    cout << "Animal criado com construtor padrão!" << endl;
}

Animal::Animal(string nome, string Som_bicho)
{
    this->nome = nome;
    this->Som_bicho = Som_bicho;
}

Animal:: ~Animal()
{
    cout << "Deixou de existir!" << endl;
    //Encerrar e desalocar tudo o que é de cachorro aqui
}

/*
virtual void Animal::fazerSom()
{ 
    cout << "Som!" << endl;
}
*/