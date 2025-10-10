#include "Figurinha.h"
#include <iostream>
using namespace std;

Figurinha::Figurinha() {
    this->numero = 0;
    this->nome = "";
    this->conteudo = "";
    this->status = 0;
    this->nroPagina = 0;
}

Figurinha::Figurinha(int numero, string nome, string conteudo, int nroPagina, int status) {
    this->numero = numero;
    this->nome = nome;
    this->conteudo = conteudo;
    this->status = status;
    this->nroPagina = nroPagina;
}

int Figurinha::getNumero() {
    return numero;
}

string Figurinha::getNome() {
    return nome;
}

string Figurinha::getConteudo() {
    return conteudo;
}

int Figurinha::getStatus() {
    return status;
}

int Figurinha::getNroPagina() {
    return nroPagina;
}

void Figurinha::setStatus(int novoStatus) {
    status = novoStatus;
}

void Figurinha::colar() {
    if (status == 0) {
        status = 1;
    }
}

void Figurinha::disponibilizarParaTroca() {
    if (status == 0) {
        status = 2;
    }
}

void Figurinha::resumo() {
    cout << "Figurinha " << numero << " - " << nome << " (";
    if (status == 1) {
        cout << "Colada";
    } else if (status == 2) {
        cout << "Disponível para troca";
    } else {
        cout << "Na coleção";
    }
    cout << ")" << "\n";
}
