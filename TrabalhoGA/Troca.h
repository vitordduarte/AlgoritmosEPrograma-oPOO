#ifndef TROCA_H
#define TROCA_H

#include <string>
using namespace std;

/*
    Classe Troca
    -------------
    Representa uma solicitação de troca entre dois usuários.
    status: 0 = aguardando, 1 = aceito, qualquer outro = recusado (2).
*/
class Troca {
private:
    string proponente;
    string destinatario;
    int figRequerida;
    int figOferecida;
    int status;

public:
    Troca();
    Troca(string prop, string dest, int req, int of);

    string getProponente();
    string getDestinatario();
    int getFigRequerida();
    int getFigOferecida();
    int getStatus();


    void aceitar();
    void setStatus(int novoStatus);
};

#endif
