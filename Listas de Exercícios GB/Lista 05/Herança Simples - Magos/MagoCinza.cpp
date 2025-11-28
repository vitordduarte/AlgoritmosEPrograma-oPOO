#include "MagoCinza.h"

MagoCinza::MagoCinza(string nome, int idade, int poder, string escolaDeMagia) : Mago(nome,idade,poder,escolaDeMagia)
{
    numeroAnimais = 20;
    cout << "Mago Cinza " << nome << " foi criado!" << endl;
}

void MagoCinza::falarComAnimais()
{
    cout << "Olá! falando com animais" << endl;

}
