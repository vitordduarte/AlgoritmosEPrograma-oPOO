#include "MagoRoxo.h"

MagoRoxo::MagoRoxo(string nome, int idade, int poder, string escolaDeMagia) : Mago(nome,idade,poder,escolaDeMagia)
{
    poderFogo = 100;
    cout << "Mago Roxo " << nome << " foi criado!" << endl;
}

void MagoRoxo :: bolaDeFogo()
{
    cout << "bola de fogo lançada" << endl;
}