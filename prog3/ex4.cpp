#include "libkaiak.hpp"


int main()
{
    srand(time(nullptr));
    SorteioSemRepeticao sorteio(10); // Sorteio de números de 1 a 10

    for (int i = 0; i < 10; ++i)
    {
        int numero = sorteio.sortear();
        std::cout << numero << " ";
    }
    std::cout << std::endl;

    return 0;
}
