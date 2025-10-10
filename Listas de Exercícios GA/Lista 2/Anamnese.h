//Crie a definição da classe Anamnese (arquivo Anamnese.h), representando um pequeno cadastro clínico.
// • Atributos: nome, idade, pesoKg, alturaM, alergias, doencasPreExistentes, medicamentosEmUso.
// • Métodos: construtor padrão, construtor com todos os campos, getters e setters para cada atributo.
//Inclua protótipos de métodos para calcular IMC e gerar resumo. 

#include <iostream> // Para usar cout e endl
#include <string> // para usar string

using namespace std; // para n precisar usar std::

class Anamnese {
// atributos
private:
    string nome;
    int idade;
    float pesokg;
    float alturaM;
    string alergias;
    string doencasPreExistentes;
    string medicamentosEmUso;

// metodos    
public:
    Anamnese(); // construtor padrao
    Anamnese(string nome, int idade, float pesokg, float alturaM, string alergias, string doencasPreExistentes, string medicamentosEmUso);
    ~Anamnese(); // destrutor padrao
    
    // Métodos setters (alteram atributos)
    void alterarNome(string nome);
    void alterarIdade(int idade);
    void alterarPeso(float pesokg);

    // Métodos getters (retornam atributos)
    int retornarIdade();
    string retornarNome();
    float retornarPeso();

    //prototipos
    void calculoIMC();
    void resumo();
};