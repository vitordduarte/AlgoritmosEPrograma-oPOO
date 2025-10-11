#include <iostream>
#include <string>
#include <clocale>
#include "Usuario.h"
#include "Troca.h"
#include "Persistencia.h"
using namespace std;

/*
    main.cpp
    ---------
    Organiza os MENUS conforme o enunciado e integra todas as funcionalidades:
    - Tela Inicial (Novo, Acessar, Sair)
    - Após login: "Gerenciar Álbum" com Ver Álbum, Gerenciar a coleção, Abrir Pacote e Voltar.
    - "Gerenciar a coleção" com Colar, Disponibilizar, Propor troca e Revisar solicitações.
    - Persistência garantida ao cadastrar, propor/decidir e ao sair do aplicativo.
*/

// Caminhos dos CSVs (mesma pasta do executável)
string arqFigs  = "figurinhas.csv";
string arqUsers = "usuarios.csv";
string arqTrocas= "trocas.csv";

// "Banco de dados" em memória (arrays estáticos + contadores)
Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

UsuarioCsv baseUsuariosCsv[MAX_USUARIOS];
int totalUsuariosCsv = 0;

CatalogoFig catalogo[MAX_FIGURINHAS];
int totalCatalogo = 0;

LinhaTroca baseTrocasCsv[MAX_TROCAS];
int totalTrocasCsv = 0;

// ---- Utilitários de busca ----
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

// ---- Inicializações ----
void construirAlbunsComCatalogo() {
    // Aplica o catálogo carregado a todos os álbuns dos usuários já existentes
    for (int i = 0; i < totalUsuarios; i = i + 1) {
        usuarios[i].getAlbum()->carregarCatalogo(catalogo, totalCatalogo);
    }
}

void carregarTudo() {
    /*
        Carrega catálogo, usuários e trocas dos CSVs.
        - Monta objetos Usuario[] a partir do usuarios.csv
        - Constrói os álbuns pelo catálogo
        - Carrega trocas e distribui para o destinatário correto
    */
    bool leuCatalogo = carregarCatalogoFigurinhas(arqFigs, catalogo, MAX_FIGURINHAS, totalCatalogo);
    if (!leuCatalogo) { cout << "Aviso: não foi possível ler " << arqFigs << ".\n"; }

    bool leuUsuarios = carregarUsuarios(arqUsers, baseUsuariosCsv, MAX_USUARIOS, totalUsuariosCsv);
    if (!leuUsuarios) { cout << "Aviso: não foi possível ler " << arqUsers << ".\n"; }

    totalUsuarios = 0;
    for (int i = 0; i < totalUsuariosCsv && i < MAX_USUARIOS; i = i + 1) {
        usuarios[totalUsuarios] = Usuario(baseUsuariosCsv[i].username, baseUsuariosCsv[i].senha);
        totalUsuarios = totalUsuarios + 1;
    }

    construirAlbunsComCatalogo();

    bool leuTrocas = carregarTrocas(arqTrocas, baseTrocasCsv, MAX_TROCAS, totalTrocasCsv);
    if (!leuTrocas) { cout << "Aviso: não foi possível ler " << arqTrocas << ".\n"; }

    // Distribui as trocas lidas para o álbum do DESTINATÁRIO
    for (int i = 0; i < totalTrocasCsv; i = i + 1) {
        LinhaTroca linha = baseTrocasCsv[i];
        int indiceDestinatario = encontrarUsuarioPorNome(linha.destinatario);
        if (indiceDestinatario != -1) {
            Troca t(linha.proponente, linha.destinatario, linha.figurinha_requerida, linha.figurinha_oferecida);
            if (linha.status == 1)      { t.aceitar(); }
            else if (linha.status != 0) { t.setStatus(2); } // qualquer outro vira 2 (recusado)
            usuarios[indiceDestinatario].getAlbum()->adicionarTroca(t);
        }
    }
}

// ---- Persistência de trocas (snapshot) ----
void sincronizarTrocasCsv() {
    /*
        Reconstrói a base de trocas a partir de todos os álbuns.
        Cada Troca é transformada em LinhaTroca e gravada no CSV.
    */
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
            if (st == 1)      { linha.status = 1; }
            else if (st == 0) { linha.status = 0; }
            else              { linha.status = 2; }
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

// ---- Fluxo de cadastro/login ----
void cadastrar() {
    /*
        Cadastro simples:
        - Impede duplicidade de nomes.
        - Cria Usuario + Album (carregado com catálogo e estado inicial "faltando tudo").
        - Atualiza baseUsuariosCsv e grava em usuarios.csv imediatamente.
    */
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
    /*
        Pede usuário/senha e compara diretamente (por preferência do projeto).
        Se sucesso, retorna o índice do usuário; senão, -1.
    */
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

// ---- Ver Álbum: navegação com Capa/Próxima/Anterior ----
void navegarAlbum(Album* album) {
    /*
        Começa exibindo a Capa (índice 0) e permite navegar entre as páginas 1..N.
        O conteúdo de cada página usa Pagina::mostrar, que indica Colada/Colar/Disponível/Faltando.
    */
    int totalPags = album->getTotalPaginas();
    int atual = 0; // 0 = CAPA, 1..N = páginas
    char cmd;
    do {
        if (atual == 0) {
            cout << "\n=== CAPA do Álbum ===\n";
        } else {
            album->mostrarPagina(atual);
        }
        cout << "[A]nterior  [P]róxima  [V]oltar: ";
        cin >> cmd;
        if (cmd == 'P' || cmd == 'p') {
            if (atual < totalPags) {
                atual = atual + 1;
            }
        } else if (cmd == 'A' || cmd == 'a') {
            if (atual > 0) {
                atual = atual - 1;
            }
        }
    } while (!(cmd == 'V' || cmd == 'v'));
}

// ---- Submenu: Gerenciar a Coleção ----
void menuGerenciarColecao(Usuario* usuarioAtual) {
    /*
        Submenu que concentra as operações de coleção e troca:
        - Visualização em matriz (somente não coladas) por página.
        - Colar, Disponibilizar, Propor e Revisar trocas (aceitar aplica nos dois álbuns).
    */
    Album* album = usuarioAtual->getAlbum();

    // Visualização em MATRIZ por página (apenas não coladas)
    int totalPags = album->getTotalPaginas();
    int paginaEscolhida = 1;
    do {
        cout << "\nDigite a página para visualizar a COLEÇÃO (1.." << totalPags << ", 0 para continuar): ";
        cin >> paginaEscolhida;
        if (paginaEscolhida >= 1 && paginaEscolhida <= totalPags) {
            album->mostrarColecaoMatrizPorPagina(paginaEscolhida);
        }
    } while (paginaEscolhida != 0);

    char opcao;
    do {
        cout << "\n=== Gerenciar a coleção ===\n";
        cout << "1 Colar Figurinha\n";
        cout << "2 Disponibilizar para troca\n";
        cout << "3 Propor troca de figurinhas\n";
        cout << "4 Revisar solicitações de troca\n";
        cout << "5 Voltar\n";
        cout << "Opção: ";
        cin >> opcao;

        if (opcao == '1') {
            int numero;
            cout << "Número da figurinha para colar: ";
            cin >> numero;
            if (album->colarFigurinha(numero)) { cout << "Colada!\n"; }
            else { cout << "Não foi possível colar.\n"; }
        } else if (opcao == '2') {
            int numero;
            cout << "Número da figurinha para disponibilizar: ";
            cin >> numero;
            if (album->disponibilizarParaTroca(numero)) { cout << "Agora está disponível para troca!\n"; }
            else { cout << "Não foi possível.\n"; }
        } else if (opcao == '3') {
            // Propor troca: lista usuários e mostra rapidamente as figurinhas disponíveis do alvo (status 2).
            cout << "Usuários cadastrados:\n";
            for (int i = 0; i < totalUsuarios; i = i + 1) {
                cout << " - " << usuarios[i].getNome() << "\n";
            }
            string alvo;
            cout << "Usuário destinatário: ";
            cin >> alvo;
            int indiceAlvo = encontrarUsuarioPorNome(alvo);
            if (indiceAlvo == -1) {
                cout << "Usuário não encontrado.\n";
            } else {
                Album* albAlvo = usuarios[indiceAlvo].getAlbum();
                cout << "Figurinhas DISPONÍVEIS do " << alvo << ": ";
                bool alg = false;
                for (int n = 1; n <= albAlvo->getTotalFigurinhas(); n = n + 1) {
                    Figurinha* arr = albAlvo->getFigurinhasPtr();
                    if (arr[n - 1].getStatus() == 2) {
                        cout << n << " ";
                        alg = true;
                    }
                }
                if (!alg) { cout << "(nenhuma marcada como disponível)"; }
                cout << "\n";

                int quer, oferece;
                cout << "Número da figurinha que você deseja (do outro): ";
                cin >> quer;
                cout << "Número da figurinha que você oferece (sua): ";
                cin >> oferece;

                Troca t(usuarioAtual->getNome(), alvo, quer, oferece);
                usuarios[indiceAlvo].getAlbum()->adicionarTroca(t);

                // Persiste na base de trocas (espelho do estado atual)
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
        } else if (opcao == '4') {
            // Revisar solicitações de troca RECEBIDAS
            Troca* reqs = album->getTrocasRecebidasArray();
            int qtd = album->getQtdTrocasRecebidas();
            if (qtd == 0) {
                cout << "Nenhuma solicitação.\n";
            } else {
                for (int i = 0; i < qtd; i = i + 1) {
                    cout << i
                         << " - " << reqs[i].getProponente()
                         << " oferece " << reqs[i].getFigOferecida()
                         << " por " << reqs[i].getFigRequerida()
                         << " (status " << reqs[i].getStatus() << ")\n";
                }
                int idx; cout << "Escolha o índice (-1 voltar): "; cin >> idx;
                if (idx >= 0 && idx < qtd) {
                    cout << "1 Aceitar, 2 Recusar, 0 Voltar: ";
                    int dec; cin >> dec;
                    if (dec == 1) {
                        // Aplica a troca nos DOIS álbuns se ambos têm as figurinhas não coladas
                        string nomeProp = reqs[idx].getProponente();
                        int nRequerida = reqs[idx].getFigRequerida();
                        int nOferecida = reqs[idx].getFigOferecida();
                        int iProp = encontrarUsuarioPorNome(nomeProp);
                        if (iProp == -1) {
                            cout << "Proponente não encontrado. Troca recusada.\n";
                            reqs[idx].setStatus(2);
                        } else {
                            Album* albProp = usuarios[iProp].getAlbum();
                            bool okDest = album->possuiNaoColada(nRequerida);
                            bool okProp = albProp->possuiNaoColada(nOferecida);

                            if (!okDest || !okProp) {
                                cout << "Uma das partes não possui a figurinha em condição de troca. Recusada.\n";
                                reqs[idx].setStatus(2);
                            } else {
                                album->perderNaoColada(nRequerida);
                                album->ganharOuManter(nOferecida);
                                albProp->perderNaoColada(nOferecida);
                                albProp->ganharOuManter(nRequerida);

                                reqs[idx].aceitar();
                                cout << "Troca aceita e aplicada nos dois álbuns.\n";
                            }
                        }
                        sincronizarTrocasCsv();
                    } else if (dec == 2) {
                        reqs[idx].setStatus(2);
                        cout << "Troca recusada.\n";
                        sincronizarTrocasCsv();
                    }
                }
            }
        }
    } while (opcao != '5');
}

// ---- Menu pós-login: Gerenciar Álbum ----
void menuGerenciarAlbum(Usuario* u) {
    /*
        Menu principal após o login:
        1) Ver Álbum (navegação Capa/Próxima/Anterior)
        2) Gerenciar a coleção (submenu)
        3) Abrir Pacote (aleatório, comentado na função)
        4) Voltar (retorna à Tela Inicial)
    */
    Album* album = u->getAlbum();
    char opc;
    do {
        cout << "\n=== Gerenciar Álbum ===\n";
        cout << "1 Ver Álbum\n";
        cout << "2 Gerenciar a coleção\n";
        cout << "3 Abrir Pacote de Figurinhas\n";
        cout << "4 Voltar\n";
        cout << "Opção: ";
        cin >> opc;

        if (opc == '1')      { navegarAlbum(album); }
        else if (opc == '2') { menuGerenciarColecao(u); }
        else if (opc == '3') { album->abrirPacote(); }
    } while (opc != '4');
}

// ---- Tela Inicial ----
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // carrega CSVs e aplica catálogo
    carregarTudo();

    char op;
    do {
        cout << "\n=== ÁLBUM DE FIGURINHAS ===\n";
        cout << "1 Novo Álbum (cadastrar)\n";
        cout << "2 Acessar Álbum\n";
        cout << "3 Sair do Aplicativo\n";
        cout << "Escolha: ";
        cin >> op;
        if (op == '1') {
            cadastrar();
        } else if (op == '2') {
            int idx = login();
            if (idx != -1) {
                menuGerenciarAlbum(&usuarios[idx]);
            }
        }
    } while (op != '3');

    // Persistência final garantida ao sair do aplicativo
    salvarUsuarios(arqUsers, baseUsuariosCsv, totalUsuariosCsv);
    sincronizarTrocasCsv();

    cout << "Saindo...\n";
    return 0;
}
