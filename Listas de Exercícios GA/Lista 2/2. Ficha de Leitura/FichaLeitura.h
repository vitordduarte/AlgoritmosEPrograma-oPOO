/*2. Ficha de Leitura
Defina a classe FichaLeitura (arquivo FichaLeitura.h) para acompanhar leituras.
• Atributos: titulo, autor, anoPublicacao, numPaginas, paginaAtual, lido, nota0a5.
• Métodos: construtores, iniciarLeitura, marcarLido, avancarPaginas, avaliar, getters/setters.
Inclua protótipos de métodos para exibir percentualLido() e resumo(). */

#ifndef FICHALEITURA_H // para evitar erros de inclusao
#define FICHALEITURA_H

#include <string>
#include <iostream>

class FichaLeitura {
// -------------------- ATRIBUTOS (Dados/Estado) --------------------
private:
    std::string titulo;
    std::string autor;
    int anoPublicacao;
    int numPaginas;
    int paginaAtual;
    bool lido;          // Status: True se a leitura foi concluída
    int nota0a5;        // Nota de avaliação de 0 a 5

// -------------------- MÉTODOS (Ações/Comportamento) --------------------
public:
    // --- CONSTRUTORES ---
    
    // Construtor Padrão
    FichaLeitura(); 
    
    // Construtor Completo (com todos os campos obrigatórios)
    FichaLeitura(const std::string& titulo, const std::string& autor, int anoPublicacao, int numPaginas);

    // Destrutor (boa prática)
    ~FichaLeitura();
    
    
    // --- MÉTODOS DE AÇÃO ---
    
    // Inicia a leitura (define a página atual como 1)
    void iniciarLeitura();
    
    // Avança um certo número de páginas (verifica limites)
    void avancarPaginas(int paginas);
    
    // Marca o livro como lido (define 'lido' como true e 'paginaAtual' como 'numPaginas')
    void marcarLido();
    
    // Atribui uma nota ao livro (verifica se a nota está no intervalo 0-5)
    void avaliar(int nota);
    
    
    // --- GETTERS (Leitura) ---
    // Usando 'const' para indicar que o método não modifica o objeto
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAnoPublicacao() const;
    int getNumPaginas() const;
    int getPaginaAtual() const;
    bool isLido() const; // Nomeclatura 'is' é comum para bool
    int getNota() const;

    
    // --- SETTERS (Modificação) ---
    void setTitulo(const std::string& titulo);
    void setAutor(const std::string& autor);
    void setAnoPublicacao(int ano);
    void setNumPaginas(int paginas);
    // Não precisa de setPaginaAtual/setLido/setNota, pois há métodos de ação específicos (avancarPaginas/marcarLido/avaliar)
    
    
    // --- PROTÓTIPOS DE CÁLCULO/RESUMO ---
    
    // Calcula e retorna o percentual de leitura concluído
    float percentualLido() const;
    
    // Exibe um resumo formatado da ficha
    void resumo() const;
};

#endif // FICHALEITURA_H
