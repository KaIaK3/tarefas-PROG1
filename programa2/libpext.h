// libpext.h


/* =============== defines =================== */

#ifndef libpext_h
#define libpext_h
#define SIZE 5
typedef struct st_bola
{
    int numero;
    struct st_bola *prox;
} Bola;


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


Bola *criar_bola(int numero); /*dps do termino do codigo, adicionar comentarios nas funcoes*/
Bola *criar_saco_bingo(void);
Bola *sortear_bola(Bola **saco);
void generate_card(int card[SIZE][SIZE]);
void print_card(int card[SIZE][SIZE]);
void mark_number( int card[SIZE][SIZE], int number);
int checa_vitoria(int card[SIZE][SIZE]);
int prosseguir(void);
#endif

