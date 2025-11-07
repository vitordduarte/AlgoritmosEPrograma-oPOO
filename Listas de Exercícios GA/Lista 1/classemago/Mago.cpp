#include "Mago.h"

Mago::Mago()
:nome(""),idade(0),escolaDeMagia("") //inicialização junto 'a assinatura do método
{
    //Inicialização dentro do bloco de código (só precisa uma das formas)
    nome="";
    idade=0;
    escolaDeMagia="";
    obraDeOrigem="";
    altura=200;
    cout << "Mago criado com construtor padrão!" << endl;
}

Mago::Mago(string nome, int idade, string escolaDeMagia, string obraOrigem, int altura)
{
    this->nome = nome;
    this->idade = idade;
    this->escolaDeMagia = escolaDeMagia;
}

Mago::~Mago()
{
    cout << "Deixou de existir!" << endl;
}

void Mago::alterarNome(string nome)
{
    this->nome = nome;
}

void Mago::alterarIdade(int idade)
{
    this->idade = idade;
}

void Mago::alterarAltura(int altura)
{
    this->altura = altura;
}

int Mago::retornarIdade()
{
    return idade;
}

string Mago::retornarNome()
{
    return nome;
}

int Mago::retornarAltura()
{
    return altura;
}

void Mago::andar()
{ 
    cout << "Estou andando!" << endl;
}

void Mago::falar(string msg)
{
    cout << "Meu nome é " << this->nome << endl;
    cout << msg << endl;
}

void Mago::invocarMagia()
{
    cout << "Invocando magia!" << endl;
}

void Mago::lutar()
{
    cout <<"lutando!" << endl;
}
