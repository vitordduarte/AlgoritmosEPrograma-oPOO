// main.cpp: ler dados do usuário, instanciar o objeto, exibir nome completo, data de nascimento, idade, freq. máxima e faixa ideal.

//main.cpp

#include "FrequenciaCardiaca.h"

int main()
{
    FreqCardiaca FreqCardiaca; // Instancia (cria) um objeto mago usando o construtor padrão

    // chama metodos
    FreqCardiaca.alterarPNome("jose");
    FreqCardiaca.alterarSobrenome("silva");
    FreqCardiaca.alterarDia(15);
    FreqCardiaca.alterarMes(10);
    FreqCardiaca.alterarMes(1000);


    // Data atual (exemplo)
    int diaAtual = 2, mesAtual = 10, anoAtual = 2024;


    //dados pelo usuario
    /*
    string nome, sobrenome;
    int dia, mes, ano;
    int diaAtual, mesAtual, anoAtual;

    // Entrada de dados pessoais
    cout << "Digite o primeiro nome: ";
    cin >> nome;
    pessoa.alterarPNome(nome);

    cout << "Digite o sobrenome: ";
    cin >> sobrenome;
    pessoa.alterarSobrenome(sobrenome);

    cout << "Digite o dia de nascimento (1-31): ";
    cin >> dia;
    pessoa.alterarDia(dia);

    cout << "Digite o mes de nascimento (1-12): ";
    cin >> mes;
    pessoa.alterarMes(mes);

    cout << "Digite o ano de nascimento (ex: 1995): ";
    cin >> ano;
    pessoa.alterarAno(ano);

    // Entrada da data atual
    cout << "\nDigite a data atual." << endl;
    cout << "Dia: ";
    cin >> diaAtual;
    cout << "Mes: ";
    cin >> mesAtual;
    cout << "Ano: ";
    cin >> anoAtual;
    */
   

    // Calcular idade
    int idade = FreqCardiaca.obterIdade(diaAtual, mesAtual, anoAtual);

    // Calcular frequências
    int freqMax = FreqCardiaca.obterFrequenciaMaxima(idade);
    int minIdeal, maxIdeal;
    FreqCardiaca.obterFrequenciaIdeal(idade, minIdeal, maxIdeal);

    // Exibir dados
    cout << "Nome completo: " 
         << FreqCardiaca.retornarPNome() << " " 
         << FreqCardiaca.retornarSobrenome() << endl;

    cout << "Data de nascimento: "
         << FreqCardiaca.retornarDia() << "/"
         << FreqCardiaca.retornarMes() << "/"
         << FreqCardiaca.retornarAno() << endl;

    cout << "Idade: " << idade << endl;
    cout << "Frequencia Maxima: " << freqMax << endl;
    cout << "Frequencia Ideal: de " << minIdeal << " a " << maxIdeal << endl;

    return 0;
};