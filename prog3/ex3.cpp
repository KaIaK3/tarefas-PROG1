#include "libkaiak.hpp"

int main (void)
{
    double valor, minimo, maximo;

    std::cout << "Digite o valor a ser normalizado: ";
    std::cin >> valor;

    std::cout << "Digite o valor minimo: ";
    std::cin >> minimo;

    std::cout << "Digite o valor maximo: ";
    std::cin >> maximo;

 // Normalizando para o intervalo [0, 1]
    double valorNormalizado = normalizacao::normalizar(valor, minimo, maximo);
    std::cout << "Valor normalizado para [0, 1]: " << valorNormalizado << std::endl;

    return 0;

}


