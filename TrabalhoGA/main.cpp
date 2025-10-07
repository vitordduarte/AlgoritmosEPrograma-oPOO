
/*

Tabela 1 – Tela Inicial
1 novo album
2 Acessar Álbum 
3 Sair do Aplicativo


Tabela 2 – Tela Gerenciar Álbum
1 Ver Álbum 
2 Gerenciar a coleção 
3 Abrir pacote de Figurinhas
4 Voltar ao menu Anterior

Tabela 3 – Tela Gerenciar Coleção
Código Opção Descrição
1 Colar Figurinha
2 Disponibilizar para
troca
3 Propor troca de figurinhas
4 Revisar solicitações
de troca
5 Voltar ao menu
Anterior
*/

#include "clocale"
#include "Usuario.cpp"
using namespace std;


int main()
{
    
    setlocale(LC_ALL,"pt_BR.UTF-8"); // Para conseguirmos utilizar caracteres do português
    //Deixei tudo aqui por enquanto, que não sei onde seria melhor de colocar
    char showMenu()
    {
        char option;
        cout << "============= MENU DE OPCOES ==============" << endl;
        cout << " 1 - novo album e cadastro de usuario" << endl;
        cout << " 2 - Acessar Album " << endl;
        cout << " 3 - Sair do Aplicativo" << endl;
        cout << " Digite uma opcao: ";
        cin >> option;
        return option;
    }

    void run()
    {
        string nomeDeUsuario;
        string senha;

        char option;
        do {
        
        option = showMenu();
        switch(option)
        {
            case '1': //novo album e cadastro de usuario            
                cout << "\nQual o seu nome? " << endl;
                cin >>  nomeDeUsuario;
                cout << "\nCrie uma senha para o seu usuario: " << endl;
                cin >> senha;
                void cadastrar (nomeDeUsuario, senha)
                //Concluir parte de criação de album
                break;
            case '2': // Acessar Album
                break;
            case '3': // Sair do programa
                cout << "Saindo do programa!" << endl;
                break;
            default: // Opcão invalida
                cout << "Opcao invalida!" << endl;
        }

        }while(option != '3');

    }


};