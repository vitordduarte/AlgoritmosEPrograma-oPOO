//FrequenciaCardiaca.cpp

#include "FrequenciaCardiaca.h"

FreqCardiaca::FreqCardiaca()
{
    primeiroNome = "";
    sobrenome = "";
    diaNasc = 01;
    mesNasc = 10;
    anoNasc = 2024;
}

FreqCardiaca::FreqCardiaca(string primeiroNome, string sobrenome, int diaNasc, int mesNasc, int anoNasc)
{
    this->primeiroNome = primeiroNome;
    this->sobrenome = sobrenome;
    this->diaNasc = diaNasc;
    this->mesNasc = mesNasc; // pq usar o this aqui?
    this->anoNasc = anoNasc;
}



    // Métodos setters (alteram atributos)
    void FreqCardiaca::alterarPNome(string primeiroNome)
    {
        this->primeiroNome = primeiroNome; // Altera o atributo primeiroNome
    }
    void FreqCardiaca::alterarSobrenome(string sobrenome)
    {
        this->sobrenome = sobrenome; // Altera o atributo sobrenome
    }

void FreqCardiaca::alterarDia(int diaNasc) { // this?
    this->diaNasc = diaNasc;
}
void FreqCardiaca::alterarMes(int mesNasc) {
    this->mesNasc = mesNasc;
}
void FreqCardiaca::alterarAno(int anoNasc) {
    this->anoNasc = anoNasc;
}

    // Métodos getters (retornam atributos)
    string FreqCardiaca::retornarPNome()
    {
        return primeiroNome;
    }
    string FreqCardiaca::retornarSobrenome()
    {
        return sobrenome;
    }
    int FreqCardiaca::retornarDia()
    {
        return diaNasc;
    }
    int FreqCardiaca::retornarMes()
    {
        return mesNasc;
    }
    int FreqCardiaca::retornarAno()
    {
        return anoNasc;
    }


    // outros metodos

    int FreqCardiaca::obterIdade(int diaAtual, int mesAtual, int anoAtual)
    {
    int idade = anoAtual - anoNasc;
    if (mesAtual < mesNasc || (mesAtual == mesNasc && diaAtual < diaNasc)) {
        idade--;
    }
    return idade;
    }

    int FreqCardiaca::obterFrequenciaMaxima(int idade)   // 220 - idade
    {
        return 220 - idade;
    }

    void FreqCardiaca::obterFrequenciaIdeal(int idade, int& minAlvo, int& maxAlvo) // 50% a 85% da máxima
    {
    int freqMax = obterFrequenciaMaxima(idade);
    minAlvo = freqMax * 0.50;
    maxAlvo = freqMax * 0.85;
    }
