#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

// Classe simples para representar o cliente
class Cliente {
    string nomeUsuario;
public:
    Cliente(const string &nomeUsuario1 = "");
    ~Cliente();

    string getNomeUsuario() const;
};
#endif
