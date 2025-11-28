#include <iostream>
#include <limits>
#include <string>
#include "Alimento.h"
#include "Eletronico.h"
#include "Vestuario.h"
#include "Camiseta.h"
#include "Smartphone.h"
#include "Compra.h"
#include "Cliente.h"

using namespace std;

// Função auxiliar para limpar o buffer do cin em caso de erro
void limparEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Cria um alimento com dados digitados
Produto* criarAlimento() {
    string nome, validade, tipo;
    float preco, peso;
    int estoque;

    cout << "Nome do alimento: ";
    getline(cin, nome);
    cout << "Preco: ";
    cin >> preco;
    cout << "Estoque: ";
    cin >> estoque;
    cout << "Peso (kg): ";
    cin >> peso;
    limparEntrada();
    cout << "Data de validade: ";
    getline(cin, validade);
    cout << "Tipo de alimento: ";
    getline(cin, tipo);

    return new Alimento(nome, preco, estoque, peso, validade, tipo);
}

// Cria um eletrônico genérico
Produto* criarEletronico() {
    string nome;
    float preco, peso;
    int estoque, tensao, garantia;

    cout << "Nome do eletronico: ";
    getline(cin, nome);
    cout << "Preco: ";
    cin >> preco;
    cout << "Estoque: ";
    cin >> estoque;
    cout << "Peso (kg): ";
    cin >> peso;
    cout << "Tensao (V): ";
    cin >> tensao;
    cout << "Garantia (meses): ";
    cin >> garantia;
    limparEntrada();

    return new Eletronico(nome, preco, estoque, peso, tensao, garantia);
}

// Cria um vestuário genérico
Produto* criarVestuario() {
    string nome, tamanho, material;
    float preco, peso;
    int estoque;

    cout << "Nome do vestuario: ";
    getline(cin, nome);
    cout << "Preco: ";
    cin >> preco;
    cout << "Estoque: ";
    cin >> estoque;
    cout << "Peso (kg): ";
    cin >> peso;
    limparEntrada();
    cout << "Tamanho: ";
    getline(cin, tamanho);
    cout << "Material: ";
    getline(cin, material);

    return new Vestuario(nome, preco, estoque, peso, tamanho, material);
}

// Cria uma camiseta
Produto* criarCamiseta() {
    string nome, tamanho, material, estampa;
    float preco, peso;
    int estoque;

    cout << "Nome da camiseta: ";
    getline(cin, nome);
    cout << "Preco: ";
    cin >> preco;
    cout << "Estoque: ";
    cin >> estoque;
    cout << "Peso (kg): ";
    cin >> peso;
    limparEntrada();
    cout << "Tamanho: ";
    getline(cin, tamanho);
    cout << "Material: ";
    getline(cin, material);
    cout << "Estampa: ";
    getline(cin, estampa);

    return new Camiseta(nome, preco, estoque, peso, tamanho, material, estampa);
}

// Cria um smartphone
Produto* criarSmartphone() {
    string nome, marca;
    float preco, peso;
    int estoque, tensao, garantia, armazenamento;

    cout << "Nome do smartphone: ";
    getline(cin, nome);
    cout << "Preco: ";
    cin >> preco;
    cout << "Estoque: ";
    cin >> estoque;
    cout << "Peso (kg): ";
    cin >> peso;
    cout << "Tensao (V): ";
    cin >> tensao;
    cout << "Garantia (meses): ";
    cin >> garantia;
    cout << "Armazenamento (GB): ";
    cin >> armazenamento;
    limparEntrada();
    cout << "Marca: ";
    getline(cin, marca);

    return new Smartphone(nome, preco, estoque, peso, tensao, garantia, armazenamento, marca);
}

int main() {
    string nomeCliente;
    cout << "Digite o nome do cliente: ";
    getline(cin, nomeCliente);
    Cliente cliente(nomeCliente);

    Compra compra;
    compra.setData("N/A"); // se quiser pode pedir a data ao usuário

    int opcao = -1;

    while (opcao != 0) {
        cout << "\n\n===== Menu Loja =====\n\n";
        cout << "Cliente: " << cliente.getNomeUsuario() << "\n";
        cout << "1 - Adicionar Alimento\n";
        cout << "2 - Adicionar Eletronico\n";
        cout << "3 - Adicionar Vestuario\n";
        cout << "4 - Adicionar Camiseta\n";
        cout << "5 - Adicionar Smartphone\n";
        cout << "6 - Remover item por indice\n";
        cout << "7 - Exibir resumo da compra\n";
        cout << "8 - Salvar compra em CSV\n";
        cout << "9 - Carregar compra de CSV\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        limparEntrada();

        switch (opcao) {
        case 1:
            compra.adicionarItem(criarAlimento());
            break;
        case 2:
            compra.adicionarItem(criarEletronico());
            break;
        case 3:
            compra.adicionarItem(criarVestuario());
            break;
        case 4:
            compra.adicionarItem(criarCamiseta());
            break;
        case 5:
            compra.adicionarItem(criarSmartphone());
            break;
        case 6: {
            int idx;
            cout << "Indice do item para remover: ";
            cin >> idx;
            limparEntrada();
            compra.removerItem(idx);
            break;
        }
        case 7:
            compra.exibirResumoCompra();
            break;
        case 8: {
            string nomeArq;
            cout << "Nome do arquivo CSV para salvar (ex: compra.csv): ";
            getline(cin, nomeArq);
            if (nomeArq.empty()) nomeArq = "compra.csv";
            compra.salvarCSV(nomeArq);
            break;
        }
        case 9: {
            string nomeArq;
            cout << "Nome do arquivo CSV para carregar (ex: compra.csv): ";
            getline(cin, nomeArq);
            if (nomeArq.empty()) nomeArq = "compra.csv";
            compra.carregarCSV(nomeArq);
            break;
        }
        case 0:
            cout << "\nSaindo...\n\n";
            break;
        default:
            cout << "\nOpcao invalida.\n\n";
            break;
        }
    }

    // Ao sair, o destrutor de Compra libera todos os produtos
    return 0;
}
