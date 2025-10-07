#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include "Album.h"

using namespace std;

class Usuario {
    // Atributos
private:
    string nomeDeUsuario;
    string senha;
    Album album;

    // Métodos
public:
    Usuario(); // construtor padrão

    Usuario
    (
        string nomeDeUsuario,
        string senha,
        Album album
    );

    // Getters
    string getNomeDeUsuario();
    Album getAlbum();

    void cadastrar (string nomeDeUsuario, string senha);
    bool verificarLogin (string, string);
};
#endif
