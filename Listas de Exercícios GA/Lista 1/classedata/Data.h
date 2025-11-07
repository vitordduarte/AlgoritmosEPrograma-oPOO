// Crie uma classe Data, com os seguintes atributos: dia, mês e ano. Essa classe deve ter também dois métodos:
// imprimirData, que não recebe parâmetro, e imprimirDataPorExtenso, que recebe o nome de uma cidade por parâmetro.
// Ambos os métodos não retornam dados. 

#include <iostream> // Para usar cout e endl
#include <string> // para usar string

using namespace std; // para n precisar usar std::

class Data {
// atributos
private:
    int dia;
    int mes;
    int ano;

// metodos    
public:
    Data(); // construtor padrao
    ~Data(); // destrutor padrao
    
    void imprimirData();
    void imprimirDataPorExtenso(string cidade);

};
