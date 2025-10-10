#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Album.h"
using namespace std;

class Usuario {
private:
    string nome;
    string senha;
    Album album; // membro direto (sem ponteiro)

public:
    Usuario();
    Usuario(string nome, string senha);
    ~Usuario();

    string getNome();
    string getSenha();
    Album* getAlbum();
};

#endif
