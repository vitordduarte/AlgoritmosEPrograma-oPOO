#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <string>
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

    // Getters
    string getNomeDeUsuario();
    Album getAlbum();

    cadastrar (string, string);
    bool verificarLogin (string, string);
};
#endif
