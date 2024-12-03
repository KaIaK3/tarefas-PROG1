#include <stdio.h>
#include <stdlib.h>


//exemplo de função recursiva

//atividade: 2 funçoes recursivas que imprimem de 1 a 10, uma recursiva na ida e outra na volta. (imprimo-chamo (ida)) (chamo-imprimo(volta))

int fat (int n)
{
    int f;
    if (n <= 0)
        return 1;

    f = n * fat(n - 1);
    return f;
}

