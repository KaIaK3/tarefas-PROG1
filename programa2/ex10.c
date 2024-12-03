/* falta comentarios aqui */

#include "libkaiak.c"

int main(void)
{
    int valor = 0;
    int i;
    tree *raiz = NULL;
    tree **t = NULL; // Ponteiro para ponteiro para percorrer e modificar a arvore
    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios

    // Inserir 25 elementos aleatorios de 0 a 100
    for (i = 0; i < 25; i++)
    {
        valor = rand() % 101; // Gera um numero entre 0 e 100

        // Inserir o valor na arvore
        t = &raiz; // Ponteiro para ponteiro para percorrer e modificar a arvore
        while (*t != NULL)
        {
            if (valor < (*t) -> i)
                t = &((*t) -> esq);
            else if (valor > (*t) -> i)
                t = &((*t) -> dir);
            else
                break; // Nao insere valores duplicados
        }

        if (*t == NULL)
        {
            *t = (tree*)malloc(sizeof(tree));
            (*t)->i = valor;
            (*t)->esq = NULL;
            (*t)->dir = NULL;
        }
    }

    // Imprimir a arvore nas tres ordens
    printf("Preorder:\n");
    preorder(raiz);
    printf("\n");

    printf("Inorder:\n");
    inorder(raiz);
    printf("\n");

    printf("Posorder:\n");
    posorder(raiz);
    printf("\n");

    return 0;
}
