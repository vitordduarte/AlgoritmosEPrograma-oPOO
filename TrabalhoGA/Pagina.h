#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include "Figurinha.h"
using namespace std;

class Pagina {
private:
    string titulo;
    int minNro;
    int maxNro; // inclusive

public:
    Pagina();
    Pagina(string titulo, int minNro, int maxNro);

    string getTitulo();
    int getMinNro();
    int getMaxNro();

    // Mostra a página consultando o array de figurinhas do álbum (ponteiro simples)
    void mostrar(Figurinha* figurinhas, int totalFigurinhas);
};

#endif
