#include <iostream>
#include <string>

using namespace std;

class Mago {
// Atributos
private:
    string nome;
    int idade;
    string escolaDeMagia;
    string obraDeOrigem;
    int altura;
// Métodos
public:
    Mago(); //Construtor padrão
    Mago(string nome, int idade, string escolaDeMagia, string obraOrigem, int altura); //construtor personalizado
    ~Mago(); //Destrutor
    //Métodos setters
    void alterarNome(string nome);
    void alterarIdade(int idade);
    void alterarAltura(int altura);
    //Métodos getters
    int retornarIdade();
    string retornarNome();
    int retornarAltura();

    void andar();
    void falar(string msg);
    void invocarMagia();
    void lutar();

};