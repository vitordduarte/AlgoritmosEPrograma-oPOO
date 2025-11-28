#include "Cachorro.h"

int main()
{
    //demonstando que nao pode instanciar animal
    //Animal animal ("A", "B");


    Cachorro cachorro("Totoro", "auau"); // instanciando objeto da classe cachorro

    cachorro.fazerSom();

    return 0;
}
