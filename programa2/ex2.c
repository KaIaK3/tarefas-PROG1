
#include "libkaiak.h"

int main (void)
{
    float dado1, dado2;

    // Solicitar que o usuário insira os dados
    printf("Digite o valor do primeiro dado (entre 0 e 100): ");
    scanf("%f", &dado1);

    printf("Digite o valor do segundo dado (entre 0 e 100): ");
    scanf("%f", &dado2);

    // Verificar se os valores estão dentro do intervalo permitido
    if (dado1 < 0 || dado1 > 100 || dado2 < 0 || dado2 > 100) {
        printf("Erro: Os valores devem estar entre 0 e 100.\n");
        return 1; // Encerrar o programa com código de erro
    }
    // Normalizar os dados e imprimir os resultados
    float dado1_normalizado = norma(dado1, 0, 100);
    float dado2_normalizado = norma(dado2, 0, 100);

    printf("Dado 1 normalizado: %.2f\n", dado1_normalizado);
    printf("Dado 2 normalizado: %.2f\n", dado2_normalizado);

    return 0;
}


