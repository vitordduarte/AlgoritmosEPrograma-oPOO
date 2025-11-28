#include "Retangulo.h"

Retangulo::Retangulo(string nome) : FormaGeo(nome)
{
    cout << "Forma geometrica " << this->nome << "criado com construtor" << endl;
}

Retangulo::Retangulo(float Base, float Altura) //construtor personalizado
{
    this->Base = Base;
    this->Altura = Altura;
}

void Retangulo::calcularArea()
{
    float area;
    area = this->Base*this->Altura;
    cout << "Area " << area << endl;
}

void Retangulo::calcularPerimetro()
{
    float perimetro;
    perimetro = 2*(this->Base)+2*(this->Altura);
    cout << "Perimetro " << perimetro << endl;
}