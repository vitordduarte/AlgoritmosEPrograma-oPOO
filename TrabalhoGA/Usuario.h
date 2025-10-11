#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Album.h"
using namespace std;

/*
    Classe Usuario
    ---------------
    - Mantém nome e senha.
  
*/
class Usuario {
private:
    string nome;
    string senha;
    Album album;

public:
    Usuario();
    Usuario(string nome, string senha);
    ~Usuario();

    string getNome();
    string getSenha();
    Album* getAlbum();
};

#endif
