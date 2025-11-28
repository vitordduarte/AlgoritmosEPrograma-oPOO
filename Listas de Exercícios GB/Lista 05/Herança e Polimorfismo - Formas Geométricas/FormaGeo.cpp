#include "FormaGeo.h"

FormaGeo::FormaGeo()
{
    //Inicialização dentro do bloco de código
    nome="";
    cout << "Forma Geometrica criada com construtor padrão!" << endl;
}

FormaGeo::FormaGeo(string nome)
{
   // this->nome = nome;
    cout << "Forma Geometrica " << this->nome << " foi criada!" << endl;
}

FormaGeo:: ~FormaGeo()
{
    cout << "Deixou de existir!" << endl;
}