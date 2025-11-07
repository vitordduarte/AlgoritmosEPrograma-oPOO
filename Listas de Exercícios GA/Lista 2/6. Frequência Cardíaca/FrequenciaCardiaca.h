/* 6. Frequência Cardíaca
• Classe: FrequenciaCardiaca (arquivo FrequenciaCardiaca.h /.cpp). OK
• Atributos (privados): primeiroNome (string), sobrenome (string), diaNasc (int), mesNasc (int), anoNasc (int). OK
• Construtores: padrão; parametrizado com todos os campos. OK
• Set/Get: para todos os atributos (validar datas simples: 1≤dia≤31, 1≤mes≤12, ano>1900).
• Métodos:
    o int obterIdade(int diaAtual, int mesAtual, int anoAtual);
    o int obterFrequenciaMaxima(int idade);   // 220 - idade
    o void obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo);  // 50% a 85% da máxima
    • main.cpp: ler dados do usuário, instanciar o objeto, exibir nome completo, data de nascimento, idade, freq. máxima e faixa ideal. 
*/

//FrequenciaCardiaca.h

#include <iostream>   // Para usar cout e endl
#include <string>     // Para usar string

using namespace std;  // Para não precisar escrever std:: antes de string, cout, etc.

class FreqCardiaca {
private:
    string primeiroNome;
    string sobrenome;
    int diaNasc;
    int mesNasc;
    int anoNasc;

public:
    FreqCardiaca();
    FreqCardiaca(string primeiroNome, string sobrenome, int diaNasc, int mesNasc, int anoNasc);

    // Métodos setters (alteram atributos)
    void alterarPNome(string primeiroNome);
    void alterarSobrenome(string sobrenome);
    void alterarDia(int diaNasc);
    void alterarMes(int mesNasc);
    void alterarAno(int anoNasc);

    // Métodos getters (retornam atributos)
    string retornarPNome();
    string retornarSobrenome();
    int retornarDia();
    int retornarMes();
    int retornarAno();


    // outros metodos
    int obterIdade(int diaAtual, int mesAtual, int anoAtual);
    int obterFrequenciaMaxima(int idade);   // 220 - idade
    void obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo);  // 50% a 85% da máxima
};
