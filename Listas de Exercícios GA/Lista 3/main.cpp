#include <iostream> // Inclui a biblioteca para entrada e saída (cout, cin)

// Definição da classe Dado
class Dado {
private:
    int faces; // Atributo que armazena o número de faces do dado

public:
    // Construtor padrão: cria um dado com 6 faces
    Dado() : faces(6) {}

    // Construtor com parâmetro: permite criar um dado com número de faces definido
    Dado(int f) : faces(f) {}

    // Método para alterar o número de faces do dado
    void setFaces(int f) {
        faces = f;
    }

    // Método que "rola" o dado e retorna o valor sorteado
    int rolar() {
        // Usamos um contador estático para simular valores pseudoaleatórios
        // Ele é estático para manter o valor entre diferentes chamadas da função
        static int contador = 0;
        contador++; // Incrementa o contador a cada rolagem
        return (contador % faces) + 1; // Gera um valor entre 1 e faces
    }
};

int main() {
    // ---------------------
    // a) Criando um ponteiro para um dado de 6 faces
    // ---------------------
    Dado* dado1 = new Dado(6); // Aloca dinamicamente um objeto Dado com 6 faces
    std::cout << "Jogada do dado de 6 faces: " << dado1->rolar() << "\n"; 
    // Chama o método rolar() e imprime o resultado
    delete dado1; // Libera a memória alocada dinamicamente

    std::cout << "-----------------------------\n";

    // ---------------------
    // b) Criando um array dinâmico de 3 dados
    // ---------------------
    Dado* dados = new Dado[3]; // Aloca dinamicamente um array de 3 dados usando construtor padrão

    // Configurando o número de faces de cada dado
    dados[0].setFaces(6);   // Primeiro dado com 6 faces
    dados[1].setFaces(8);   // Segundo dado com 8 faces
    dados[2].setFaces(12);  // Terceiro dado com 12 faces

    // Rolar cada dado 3 vezes
    for(int i = 0; i < 3; i++) { // Para cada dado no array
        // Imprime informações do dado
        std::cout << "Dado " << i+1 << " (" << (i==0?6:i==1?8:12) << " faces): ";
        for(int j = 0; j < 3; j++) { // Rola o mesmo dado 3 vezes
            std::cout << dados[i].rolar() << " "; // Imprime o resultado de cada jogada
        }
        std::cout << "\n"; // Pula linha após 3 jogadas
    }

    delete[] dados; // Libera a memória alocada para o array de dados

    return 0; // Indica que o programa terminou corretamente
}
