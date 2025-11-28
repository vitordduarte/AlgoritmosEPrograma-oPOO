#ifndef MAGO_H
#define MAGO_H

#include <iostream>
#include <string>

using namespace std;

class Mago {
// Atributos
protected:
    string nome;
    int idade;
    int poder; // incluido
    string escolaDeMagia;
// Métodos
public:
    Mago(); //Construtor padrão
    Mago(string nome, int idade, int poder, string escolaDeMagia); //construtor personalizado
    ~Mago(); //Destrutor

    /*
    //Métodos setters
    void alterarNome(string nome);
    void alterarIdade(int idade);
    void alterarEscolaMagia(string escolaMagia);
    //Métodos getters
    int retornarIdade();
    string retornarNome();
    string retornarEscolaMagia();
    */

    // metodos gerais
    void andar();
    void falar(string msg);
    void invocarMagia();

};

#endif // MAGO_H
