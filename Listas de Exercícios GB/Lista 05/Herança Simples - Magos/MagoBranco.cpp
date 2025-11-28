#include "MagoBranco.h"

MagoBranco::MagoBranco(string nome, int idade, int poder, string escolaDeMagia) : Mago(nome,idade,poder,escolaDeMagia)
{
    poderCura = 0;
    cout << "Mago Branco " << nome << " foi criado!" << endl;
}

void MagoBranco::lancarCura()
{
    cout << "Estou curando você!" << endl;
}
