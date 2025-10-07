//Vítor fazendo
#include "Item.h"
#include <iostream>
using namespace std;

Album::Album() {
    nome = "";
    tipo = "";
    valor = 0;
    cout << "criado com construtor padrão!" << endl;
}

Item::Item(string nome, string tipo, int valor) {
    this->nome = nome;
    this->tipo = tipo;
    this->valor = valor;
}

string Item::getNome() {
    return nome; }
string Item::getTipo() {
    return tipo; }
int Item::getValor() {
    return valor; }

void Item::exibirItem() {
    cout << "Item: " << nome << " | Tipo: " << tipo << " | ";
    if (tipo == "Poção") {
        cout << "Cura: " << valor << " PV";
    } else if (tipo == "Arma") {
        cout << "Dano: " << valor;
    } else if (tipo == "Armadura") {
        cout << "Defesa: " << valor;
    }
    cout << endl;
}

