#include "Pagina.h"
#include <iostream>
using namespace std;

Pagina::Pagina() {
    this->titulo = "";
    this->minNro = 1;
    this->maxNro = 10;
}

Pagina::Pagina(string titulo, int minNro, int maxNro) {
    this->titulo = titulo;
    this->minNro = minNro;
    this->maxNro = maxNro;
}

string Pagina::getTitulo() 
{
    return titulo;
}
int Pagina::getMinNro() 
{
    return minNro;
}
int Pagina::getMaxNro() 
{
    return maxNro;
}


    /*
        Verifica o status de cada figurinha e dá um retorno
        - Percorre os números da faixa [min..max].
        - Para cada número:
            1 -> imprime "COLADA" e o nome
            0 -> imprime "COLAR (você tem, mas não colada)"
            2 -> imprime "DISPONÍVEL PARA TROCA"
           <0 -> imprime "FALTANDO"
    */
void Pagina::mostrar(Figurinha* figurinhas, int totalFigurinhas) {
    cout << "=== Página: " << titulo << " (" << minNro << " a " << maxNro << ") ===\n";
    for (int n = minNro; n <= maxNro; n = n + 1) {
        if (n >= 1 && n <= totalFigurinhas) {
            Figurinha& f = figurinhas[n - 1];
            int status = f.getStatus();
            cout << n << " - ";
            if (status == 1) {
                cout << f.getNome() << " (COLADA)\n";
            } else if (status == 0) {
                cout << "COLAR (você tem, mas não colada)\n";
            } else if (status == 2) {
                cout << "DISPONÍVEL PARA TROCA\n";
            } else {
                cout << "FALTANDO\n";
            }
        }
    }
    cout << "=====================================\n";
}
