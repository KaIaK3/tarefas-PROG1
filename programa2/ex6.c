#include "libkaiak.h"

int main(void)
{
    lista *l1=NULL, *b=NULL, *a=NULL;
    inserir(&l1, 1);
    inserir(&l1, 2);
    inserir(&l1, 3);

    imprimir(l1);
    b=buscar(l1, 2);

    if(b!=NULL)
        printf("b->c: %d\n", b->c);

    a=anterior(l1, b);

    if(a!=NULL)
        printf("a->c: %d\n", a->c);

    remover(&l1, b);
    imprimir(l1);

    return 0;
}
