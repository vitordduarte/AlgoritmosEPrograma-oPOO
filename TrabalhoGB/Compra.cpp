#include "Compra.h"
#include "Alimento.h"
#include "Eletronico.h"
#include "Vestuario.h"
#include "Camiseta.h"
#include "Smartphone.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Compra::Compra()
    : data(""), valorTotal(0.0f) {}

Compra::~Compra() {
    // Libera a memória dos produtos adicionados com new
    for (Produto* p : itens) {
        delete p;
    }
    itens.clear();
}

// Adiciona um item na compra
void Compra::adicionarItem(Produto* p) {
    if (p != nullptr) {
        itens.push_back(p);
        valorTotal += p->getPreco();
    }
}

// Remove um item pelo índice, liberando a memória
void Compra::removerItem(int index) {
    if (index < 0 || index >= static_cast<int>(itens.size())) {
        cout << "Índice inválido.\n";
        return;
    }

    Produto* p = itens[index];
    valorTotal -= p->getPreco();
    delete p;

    itens.erase(itens.begin() + index);
}

// Calcula o total percorrendo o vetor (garante coerência)
float Compra::calcularTotal() const {
    float total = 0.0f;
    for (Produto* p : itens) {
        total += p->getPreco();
    }
    return total;
}

// Soma o frete de todos os itens usando polimorfismo
float Compra::calcularFreteTotal() const {
    float totalFrete = 0.0f;
    for (Produto* p : itens) {
        totalFrete += p->calcularFrete();
    }
    return totalFrete;
}

bool Compra::vazia() const {
    return itens.empty();
}

// Exibe todos os itens e os totais
void Compra::exibirResumoCompra() const {
    if (vazia()) {
        cout << "Compra vazia.\n";
        return;
    }

    cout << "===== Resumo da Compra =====\n";
    if (!data.empty()) {
        cout << "Data: " << data << "\n";
    }

    for (size_t i = 0; i < itens.size(); ++i) {
        cout << "Item " << i << ": ";
        itens[i]->exibirInfo();
    }

    float totalProdutos = calcularTotal();
    float totalFrete = calcularFreteTotal();

    cout << "Total produtos: R$ " << totalProdutos << "\n";
    cout << "Total frete:    R$ " << totalFrete << "\n";
    cout << "Total geral:    R$ " << (totalProdutos + totalFrete) << "\n";
    cout << "============================\n";
}

void Compra::setData(const string &data1) {
    data = data1;
}

string Compra::getData() const {
    return data;
}

// Funções auxiliares internas (arquivo-local) para conversão
static int strToInt(const string &s) {
    if (s.empty()) return 0;
    return stoi(s);
}

static float strToFloat(const string &s) {
    if (s.empty()) return 0.0f;
    return stof(s);
}

// Salva os itens da compra em um arquivo CSV
void Compra::salvarCSV(const string &nomeArquivo) const {
    ofstream arq(nomeArquivo);
    if (!arq) {
        cout << "Erro ao abrir arquivo para escrita: " << nomeArquivo << "\\n";
        return;
    }

    // Cabeçalho
    arq << "tipo;nome;preco;estoque;peso;dataValidade;tipoAlimento;"
           "tensao;garantiaMeses;tamanho;material;estampa;armazenamentoGB;marca\n";

    // Para cada produto, detecta o tipo concreto com dynamic_cast
    for (Produto* p : itens) {
        string tipo = "";
        string nome = p->getNome();
        float preco = p->getPreco();
        int estoque = 0;   // não temos getter de estoque, poderia ser ajustado se precisar
        float peso = 0.0f; // idem, mantemos 0 para simplificar

        // Campos específicos (iniciados vazios)
        string dataValidade = "";
        string tipoAlimento = "";
        string tamanho = "";
        string material = "";
        string estampa = "";
        int tensao = 0;
        int garantiaMeses = 0;
        int armazenamentoGB = 0;
        string marca = "";

        if (auto c = dynamic_cast<Camiseta*>(p)) {
            tipo = "CAMISETA";
            tamanho = c->getTamanho();
            material = c->getMaterial();
            estampa = c->getEstampa();
        } else if (auto s = dynamic_cast<Smartphone*>(p)) {
            tipo = "SMARTPHONE";
            tensao = s->getTensao();
            garantiaMeses = s->getGarantia();
            // Para armazenamento e marca usamos getEspecificacoes apenas como info,
            // mas aqui manteremos simplificado: não temos getters específicos, então deixamos 0/""
        } else if (auto a = dynamic_cast<Alimento*>(p)) {
            tipo = "ALIMENTO";
            dataValidade = a->getDataValidade();
            // tipoAlimento não tem getter específico, mas poderíamos adicionar se necessário
        } else if (auto e = dynamic_cast<Eletronico*>(p)) {
            tipo = "ELETRONICO";
            tensao = e->getTensao();
            garantiaMeses = e->getGarantia();
        } else if (auto v = dynamic_cast<Vestuario*>(p)) {
            tipo = "VESTUARIO";
            tamanho = v->getTamanho();
            material = v->getMaterial();
        } else {
            tipo = "DESCONHECIDO";
        }

        arq << tipo << ';'
            << nome << ';'
            << preco << ';'
            << estoque << ';'
            << peso << ';'
            << dataValidade << ';'
            << tipoAlimento << ';'
            << tensao << ';'
            << garantiaMeses << ';'
            << tamanho << ';'
            << material << ';'
            << estampa << ';'
            << armazenamentoGB << ';'
            << marca << '\n';
    }

    arq.close();
    cout << "Compra salva em: " << nomeArquivo << "\\n";
}

// Carrega itens de um arquivo CSV, substituindo os itens atuais
void Compra::carregarCSV(const string &nomeArquivo) {
    ifstream arq(nomeArquivo);
    if (!arq) {
        cout << "Erro ao abrir arquivo para leitura: " << nomeArquivo << "\\n";
        return;
    }

    // Limpa itens atuais
    for (Produto* p : itens) {
        delete p;
    }
    itens.clear();
    valorTotal = 0.0f;

    string linha;
    // Lê e descarta o cabeçalho
    if (!getline(arq, linha)) {
        cout << "Arquivo vazio ou invalido.\\n";
        return;
    }

    // Lê cada linha do CSV
    while (getline(arq, linha)) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        string campo;
        string campos[14];
        int idx = 0;

        // Separa por ';'
        while (getline(ss, campo, ';') && idx < 14) {
            campos[idx++] = campo;
        }

        string tipo = campos[0];
        string nome = campos[1];
        float preco = strToFloat(campos[2]);
        int estoque = strToInt(campos[3]);
        float peso = strToFloat(campos[4]);
        string dataValidade = campos[5];
        string tipoAlimento = campos[6];
        int tensao = strToInt(campos[7]);
        int garantiaMeses = strToInt(campos[8]);
        string tamanho = campos[9];
        string material = campos[10];
        string estampa = campos[11];
        int armazenamentoGB = strToInt(campos[12]);
        string marca = campos[13];

        Produto* p = nullptr;

        if (tipo == "ALIMENTO") {
            p = new Alimento(nome, preco, estoque, peso, dataValidade, tipoAlimento);
        } else if (tipo == "ELETRONICO") {
            p = new Eletronico(nome, preco, estoque, peso, tensao, garantiaMeses);
        } else if (tipo == "VESTUARIO") {
            p = new Vestuario(nome, preco, estoque, peso, tamanho, material);
        } else if (tipo == "CAMISETA") {
            p = new Camiseta(nome, preco, estoque, peso, tamanho, material, estampa);
        } else if (tipo == "SMARTPHONE") {
            p = new Smartphone(nome, preco, estoque, peso, tensao, garantiaMeses, armazenamentoGB, marca);
        } else {
            cout << "Tipo desconhecido na linha: " << linha << "\\n";
        }

        if (p != nullptr) {
            adicionarItem(p);
        }
    }

    cout << "Compra carregada de: " << nomeArquivo << "\\n";
}
