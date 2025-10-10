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

string Pagina::getTitulo() {
    return titulo;
}

int Pagina::getMinNro() {
    return minNro;
}

int Pagina::getMaxNro() {
    return maxNro;
}

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
            } else {
                cout << "DISPONÍVEL PARA TROCA\n";
            }
        }
    }
    cout << "=====================================\n";
}
