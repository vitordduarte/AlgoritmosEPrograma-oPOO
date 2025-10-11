#include "Troca.h"

Troca::Troca() {
    this->proponente = "";
    this->destinatario = "";
    this->figRequerida = 0;
    this->figOferecida = 0;
    this->status = 0; // aguardando por padrão
}

Troca::Troca(string prop, string dest, int req, int of) {
    this->proponente = prop;
    this->destinatario = dest;
    this->figRequerida = req;
    this->figOferecida = of;
    this->status = 0;
}
string Troca::getProponente()
{
    return proponente;
}
string Troca::getDestinatario()
{
    return destinatario;
}
int Troca::getFigRequerida()
{
    return figRequerida;
}
int Troca::getFigOferecida() 
{
    return figOferecida;
}
int Troca::getStatus()
{
    return status;
}

// aceitar(): marca como 1; setStatus(): força 0/1/2 conforme regras do chamador
void Troca::aceitar() 
{
    status = 1;
}
void Troca::setStatus(int novoStatus)
{
    status = novoStatus;
}
