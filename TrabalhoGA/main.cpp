#include <iostream>
#include <string>
#include <clocale>
#include "Usuario.h"
#include "Troca.h"
#include "Persistencia.h"
using namespace std;

// caminhos dos CSV 
string arqFigs  = "figurinhas.csv";
string arqUsers = "usuarios.csv";
string arqTrocas= "trocas.csv";

// base em memória com arrays estáticos (tamanhos definidos em Album.h)
Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

UsuarioCsv baseUsuariosCsv[MAX_USUARIOS];
int totalUsuariosCsv = 0;

CatalogoFig catalogo[MAX_FIGURINHAS];
int totalCatalogo = 0;

LinhaTroca baseTrocasCsv[MAX_TROCAS];
int totalTrocasCsv = 0;

int encontrarUsuarioPorNome(string nome) {
    for (int i = 0; i < totalUsuarios; i = i + 1) {
        if (usuarios[i].getNome() == nome) {
            return i;
        }
    }
    return -1;
}

int encontrarUsuarioPorCredenciais(string nome, string senha) {
    for (int i = 0; i < totalUsuarios; i = i + 1) {
        if (usuarios[i].getNome() == nome && usuarios[i].getSenha() == senha) {
            return i;
        }
    }
    return -1;
}

void construirAlbunsComCatalogo() {
    for (int i = 0; i < totalUsuarios; i = i + 1) {
        usuarios[i].getAlbum()->carregarCatalogo(catalogo, totalCatalogo);
    }
}

void carregarTudo() {
    bool leuCatalogo = carregarCatalogoFigurinhas(arqFigs, catalogo, MAX_FIGURINHAS, totalCatalogo);
    if (!leuCatalogo) {
        cout << "Aviso: não foi possível ler " << arqFigs << ".\n";
    }

    bool leuUsuarios = carregarUsuarios(arqUsers, baseUsuariosCsv, MAX_USUARIOS, totalUsuariosCsv);
    if (!leuUsuarios) {
        cout << "Aviso: não foi possível ler " << arqUsers << ".\n";
    }

    // cria objetos Usuario a partir do CSV
    totalUsuarios = 0;
    for (int i = 0; i < totalUsuariosCsv && i < MAX_USUARIOS; i = i + 1) {
        usuarios[totalUsuarios] = Usuario(baseUsuariosCsv[i].username, baseUsuariosCsv[i].senha);
        totalUsuarios = totalUsuarios + 1;
    }

    // aplica catálogo nos álbuns
    construirAlbunsComCatalogo();

    // carrega trocas e distribui para o álbum do destinatário
    bool leuTrocas = carregarTrocas(arqTrocas, baseTrocasCsv, MAX_TROCAS, totalTrocasCsv);
    if (!leuTrocas) {
        cout << "Aviso: não foi possível ler " << arqTrocas << ".\n";
    }

    for (int i = 0; i < totalTrocasCsv; i = i + 1) {
        LinhaTroca linha = baseTrocasCsv[i];
        int indiceDestinatario = encontrarUsuarioPorNome(linha.destinatario);
        if (indiceDestinatario != -1) {
            Troca t(linha.proponente, linha.destinatario, linha.figurinha_requerida, linha.figurinha_oferecida);
            if (linha.status == 1) {
                t.aceitar();
            } else if (linha.status != 0) {
                t.setStatus(2); // outros valores tratados como recusado
            }
            usuarios[indiceDestinatario].getAlbum()->adicionarTroca(t);
        }
    }
}

void sincronizarTrocasCsv() {
    // Reconstrói baseTrocasCsv varrendo todos os álbuns
    totalTrocasCsv = 0;
    for (int iUsuario = 0; iUsuario < totalUsuarios; iUsuario = iUsuario + 1) {
        Album* album = usuarios[iUsuario].getAlbum();
        Troca* requisicoes = album->getTrocasRecebidasArray();
        int quantidade = album->getQtdTrocasRecebidas();

        for (int iTroca = 0; iTroca < quantidade && totalTrocasCsv < MAX_TROCAS; iTroca = iTroca + 1) {
            LinhaTroca linha;
            linha.proponente = requisicoes[iTroca].getProponente();
            linha.destinatario = requisicoes[iTroca].getDestinatario();
            linha.figurinha_oferecida = requisicoes[iTroca].getFigOferecida();
            linha.figurinha_requerida = requisicoes[iTroca].getFigRequerida();
            int st = requisicoes[iTroca].getStatus();
            if (st == 1) {
                linha.status = 1;
            } else if (st == 0) {
                linha.status = 0;
            } else {
                linha.status = 2;
            }
            baseTrocasCsv[totalTrocasCsv] = linha;
            totalTrocasCsv = totalTrocasCsv + 1;
        }
    }
    if (!salvarTrocas(arqTrocas, baseTrocasCsv, totalTrocasCsv)) {
        cout << "Aviso: não foi possível salvar " << arqTrocas << ".\n";
    } else {
        cout << "(Trocas salvas em " << arqTrocas << ")\n";
    }
}

void cadastrar() {
    string nome, senha;
    cout << "Nome de usuário: ";
    cin >> nome;
    if (encontrarUsuarioPorNome(nome) != -1) {
        cout << "Usuário já existe!\n";
        return;
    }
    cout << "Senha: ";
    cin >> senha;

    if (totalUsuarios >= MAX_USUARIOS) {
        cout << "Limite de usuários atingido.\n";
        return;
    }

    usuarios[totalUsuarios] = Usuario(nome, senha);
    totalUsuarios = totalUsuarios + 1;
    usuarios[totalUsuarios - 1].getAlbum()->carregarCatalogo(catalogo, totalCatalogo);

    // atualiza base CSV e persiste
    if (totalUsuariosCsv < MAX_USUARIOS) {
        baseUsuariosCsv[totalUsuariosCsv].username = nome;
        baseUsuariosCsv[totalUsuariosCsv].senha = senha;
        totalUsuariosCsv = totalUsuariosCsv + 1;
    }
    if (!salvarUsuarios(arqUsers, baseUsuariosCsv, totalUsuariosCsv)) {
        cout << "Aviso: não foi possível salvar " << arqUsers << ".\n";
    } else {
        cout << "Usuário cadastrado e salvo em " << arqUsers << ".\n";
    }
}

int login() {
    string nome, senha;
    cout << "Usuário: ";
    cin >> nome;
    cout << "Senha: ";
    cin >> senha;
    int indice = encontrarUsuarioPorCredenciais(nome, senha);
    if (indice == -1) {
        cout << "Usuário ou senha incorretos.\n";
        return -1;
    }
    cout << "Bem-vindo, " << nome << "!\n";
    return indice;
}

void menuTrocas(Usuario* usuarioAtual) {
    Album* album = usuarioAtual->getAlbum();
    char opcao;
    do {
        cout << "\n=== Gerenciar Trocas ===\n";
        cout << "1 Propor troca\n";
        cout << "2 Revisar solicitações recebidas\n";
        cout << "3 Voltar\n";
        cout << "Opção: ";
        cin >> opcao;

        if (opcao == '1') {
            string alvo;
            int quer;
            int oferece;
            cout << "Usuário destinatário: ";
            cin >> alvo;
            int indiceAlvo = encontrarUsuarioPorNome(alvo);
            if (indiceAlvo == -1) {
                cout << "Usuário não encontrado.\n";
            } else {
                cout << "Número da figurinha que você deseja (do outro): ";
                cin >> quer;
                cout << "Número da figurinha que você oferece (sua): ";
                cin >> oferece;
                Troca t(usuarioAtual->getNome(), alvo, quer, oferece);
                usuarios[indiceAlvo].getAlbum()->adicionarTroca(t);

                // espelha e salva no trocas.csv
                if (totalTrocasCsv < MAX_TROCAS) {
                    LinhaTroca linha;
                    linha.proponente = usuarioAtual->getNome();
                    linha.destinatario = alvo;
                    linha.figurinha_requerida = quer;
                    linha.figurinha_oferecida = oferece;
                    linha.status = 0;
                    baseTrocasCsv[totalTrocasCsv] = linha;
                    totalTrocasCsv = totalTrocasCsv + 1;
                    salvarTrocas(arqTrocas, baseTrocasCsv, totalTrocasCsv);
                }
                cout << "Proposta enviada e gravada em trocas.csv.\n";
            }
        } else if (opcao == '2') {
            Troca* requisicoes = album->getTrocasRecebidasArray();
            int quantidade = album->getQtdTrocasRecebidas();
            if (quantidade == 0) {
                cout << "Nenhuma solicitação.\n";
            } else {
                for (int i = 0; i < quantidade; i = i + 1) {
                    cout << i << " - " << requisicoes[i].getProponente()
                         << " oferece " << requisicoes[i].getFigOferecida()
                         << " por " << requisicoes[i].getFigRequerida()
                         << " (status " << requisicoes[i].getStatus() << ")\n";
                }
                int indiceEscolhido;
                cout << "Escolha o índice (-1 voltar): ";
                cin >> indiceEscolhido;
                if (indiceEscolhido >= 0 && indiceEscolhido < quantidade) {
                    cout << "1 Aceitar, 2 Recusar, 0 Voltar: ";
                    int decisao;
                    cin >> decisao;
                    if (decisao == 1) {
                        requisicoes[indiceEscolhido].aceitar();
                        cout << "Troca marcada como aceita.\n";
                    } else if (decisao == 2) {
                        requisicoes[indiceEscolhido].setStatus(2); // recusada
                        cout << "Troca recusada.\n";
                    }
                    // salva estado atual no CSV
                    sincronizarTrocasCsv();
                }
            }
        }
    } while (opcao != '3');
}

void menuUsuario(Usuario* usuario) {
    Album* album = usuario->getAlbum();
    char opcao;
    do {
        cout << "\n1 Ver Álbum\n2 Colar Figurinha\n3 Disponibilizar para troca\n4 Abrir Pacote\n5 Trocas\n6 Sair\nOpção: ";
        cin >> opcao;

        if (opcao == '1') {
            cout << "=== Capa do Álbum ===\n"; // página 0 é a CAPA (não lista figurinhas)
            int totalPags = album->getTotalPaginas();
            for (int p = 1; p <= totalPags; p = p + 1) {
                album->mostrarPagina(p);
            }
        } else if (opcao == '2') {
            int numero;
            cout << "Número da figurinha para colar: ";
            cin >> numero;
            if (album->colarFigurinha(numero)) {
                cout << "Colada!\n";
            } else {
                cout << "Não foi possível colar.\n";
            }
        } else if (opcao == '3') {
            int numero;
            cout << "Número da figurinha para disponibilizar: ";
            cin >> numero;
            if (album->disponibilizarParaTroca(numero)) {
                cout << "Agora está disponível para troca!\n";
            } else {
                cout << "Não foi possível.\n";
            }
        } else if (opcao == '4') {
            album->abrirPacote();
        } else if (opcao == '5') {
            menuTrocas(usuario);
        }
    } while (opcao != '6');
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // carrega CSVs
    carregarTudo();

    char opcao;
    do {
        cout << "\n=== ÁLBUM DE FIGURINHAS ===\n";
        cout << "1 Novo Álbum (cadastrar)\n2 Acessar Álbum\n3 Sair\nEscolha: ";
        cin >> opcao;
        if (opcao == '1') {
            cadastrar();
        } else if (opcao == '2') {
            int indice = login();
            if (indice != -1) {
                menuUsuario(&usuarios[indice]);
            }
        }
    } while (opcao != '3');

    cout << "Saindo...\n";
    return 0;
}
