#include "MagoBranco.h"
#include "MagoCinza.h"
#include "MagoRoxo.h"

int main()
{
    MagoBranco magoBranco("Gandalf",2019, 25, "Istari");     // instanciando objeto da classe magoBranco


    magoBranco.falar("Olá!"); //invocando método da superclasse
    magoBranco.lancarCura();


    MagoCinza magoCinza("Harry",2000, 50, "Hogwarts");     // instanciando objeto da classe magoBranco


    magoCinza.andar(); //invocando método da superclasse Mago
    magoCinza.falarComAnimais();



    MagoRoxo magoRoxo ("Merlim",1800, 100, "Idade Media");     // instanciando objeto da classe magoBranco


    magoRoxo.invocarMagia(); //invocando método da superclasse Mago
    magoRoxo.bolaDeFogo();


    return 0;
}