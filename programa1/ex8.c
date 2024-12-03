#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // variaveis locais
    float k;
    float j;
    float divisao = 0;

    // entradas
    printf("Digite o primeiro numero: \n");
    scanf("%f",&k);
    printf("Digite o segundo numero: \n");
    scanf("%f", &j);

    // calculo e amostra do resultado
    divisao = k / j;

    printf("A DIVISAO E: %.2f \n", divisao);

    return EXIT_SUCCESS;
}
