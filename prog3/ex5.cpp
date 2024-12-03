#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort
#include <cstdlib>   // Para std::rand e std::srand
#include <ctime>     // Para std::time, usado para gerar a seed dos números aleatórios


int main()
{
    std::vector<int> valores(500); // Vetor com 500 valores
    std::srand(std::time(0));      // Inicializa a seed para geração de números aleatórios

    // Preenche o vetor com valores aleatórios entre 0 e 1000
    for(int& valor : valores)
    {
        valor = std::rand() % 1001;
    }

    // Ordena o vetor em ordem crescente
    std::sort(valores.begin(), valores.end());

    // Exibe os primeiros 20 valores para verificação
    std::cout << "Os primeiros 20 valores ordenados são: ";
    for(int i = 0; i < 20; ++i)
    {
        std::cout << valores[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
