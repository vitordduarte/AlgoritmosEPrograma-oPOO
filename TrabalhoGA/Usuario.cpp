#include "Usuario.h"

Usuario::Usuario() {
    this->nome = "";
    this->senha = "";
}

Usuario::Usuario(string nome, string senha) {
    this->nome = nome;
    this->senha = senha;
}

Usuario::~Usuario() {
    // nada a liberar (sem new/delete)
}

string Usuario::getNome() {
    return nome;
}

string Usuario::getSenha() {
    return senha;
}

Album* Usuario::getAlbum() {
    return &album;
}
