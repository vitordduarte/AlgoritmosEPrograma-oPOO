#include <iostream>
#include <string>

using namespace std;

class Troca{

    //Atributos - privado
    private:
        string nomeProponente;
        int figurinhaRequerida;
        int figurinhaDisponivel;
        int status;

    public:

        // construto padrão
        Troca();

        //personalizado
        Troca
        (
            string nomeProponente,
            int figurinhaRequerida,
            int figurinhaDisponivel
        );

        //Destrutor
        ~Troca();

        bool aceitar();
};
