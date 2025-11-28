#include "Cliente.h"

Cliente::Cliente(const string &nomeUsuario1)
    : nomeUsuario(nomeUsuario1) {}

Cliente::~Cliente() {}

string Cliente::getNomeUsuario() const {
    return nomeUsuario;
}
