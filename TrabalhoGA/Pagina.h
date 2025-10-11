#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include "Figurinha.h"
using namespace std;

/*
    Classe Pagina
    Guarda o título e a faixa de números (min..max) de figurinhas que compõem a página.
    A exibição consulta o array de figurinhas do Álbum para saber o status de cada número.
*/
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
    
    

    void mostrar(Figurinha* figurinhas, int totalFigurinhas);
};

#endif
