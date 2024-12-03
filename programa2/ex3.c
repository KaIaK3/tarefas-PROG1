#include "libkaiak.h"

int main()
{
    int numeros_sorteados[NUMERO_DE_SORTEIOS];

    // Chamar a função de sorteio sem repetição
    sortear_sem_repeticao(numeros_sorteados);

    // Imprimir os números sorteados
    printf("Os numeros sorteados sao: \n");
    for (int i = 0; i < NUMERO_DE_SORTEIOS; i++)
    {
        printf("%d \n", numeros_sorteados[i]);
    }
    printf("\n");

    return 0;
}
