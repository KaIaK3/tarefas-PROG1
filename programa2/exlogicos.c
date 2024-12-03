/* Codigo que determina a entrada em um certo evento de acordo
 * com a idade e o sexo da pessoa. exercicio de operadores logicos em C*/


#include <stdio.h>

int main(void)
{
    int idade;
    char sexo;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &sexo);

    if (idade >= 18 && (sexo == 'M' || sexo == 'F') && !(idade >= 70 && (sexo == 'M' || sexo == 'F')))
        printf("Você é elegível para participar do evento.\n");
    else
        printf("Você não é elegível para participar do evento.\n");

    return 0;
}
