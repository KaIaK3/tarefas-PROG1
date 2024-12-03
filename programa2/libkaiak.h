// libkaiak.h


/* =============== defines =================== */

#ifndef libkaiak_h
#define libkaiak_h

#define NUMERO_DE_SORTEIOS 6
#define RANGE_DE_NUMEROS 6

typedef struct st_lista
{
    int c; //o item armazenado
    struct st_lista *prox; //ponteiro para próximo
}lista;


typedef struct stree
{
    int i;
    struct stree *esq;
    struct stree *dir;
} tree;

/* ============= fim dos defines ============ */

/* ========================== includes ================================== */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include <time.h> /* Time and date functions */
#include <sys/time.h> /* Time and date functions */
#include <math.h> /* Mathematics functions */
#include <string.h> /*biblioteca para strings*/
#include <allegro.h> /* biblioteca grafica */

/* ======================== fim das includes =========================== */


/* ================================= Prototipos de função ========================================= */

float norma (float x, float minimum1, float maximum1); /* caso especifico da função conversão, retorno */
float conversao (float x, float minimum1, float maximum1, float minimun2, float maximum2); /* função que tem as formulas para normalização */
void sortear_sem_repeticao(int numeros_sorteados[NUMERO_DE_SORTEIOS]); /* função do sorteio sem repetição, treino para redes de petri */
char *concatenar(const char *string1, const char *string2); /* função de concatenação de palavras */
int ePrefixo(const char *str, const char *prefixo); /* função para comparar 2 strings e dizer o seu prefixo */
int eSufixo(const char *str, const char *sufixo); /* função para comparar 2 strings e dizer o seu sufixo */
int temSubPalavra(const char *str, const char *sub_palavra); /* função para verificar se uma string contém uma sub-palavra em C */
void imprimir(lista *cabeca); /* imprimir uma lista completa */
lista *anterior(lista *cabeca, lista *r); /* determinação de um elemento anterior a um nó */
void remover(lista **cabeca, lista *r); /* algoritmo de exclusão da lista com suas caracteristicas para excluir */
void inserir(lista **cabeca, int x); /* algoritmo de inclusão ao final da lista */
lista *buscar(lista *cabeca, int x); /* algoritmo de busca na lista */
void preorder (tree *t); /* impressão da arvore antes da ordem de busca */
void posorder (tree *t); /* impressão da arvore após a ordem de busca */
void inorder (tree *t); /* impressão da arvore enquanto faz a ordem de busca */
#endif

