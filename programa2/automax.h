/***************************************************************************
 *   automax.h                                 Version 20210512.104607         *
 *   AFND, AFD and ER                                                      *
 *                                                                         *
 *   Converte de tudo: AFD, AFND e ER                                      *
 *   Copyright (C) 2016-2021         by Ruben Carlo Benante                *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file automax.h
 * \ingroup GroupUnique
 * \brief Converte AFD, AFND e ER
 * \details This program really do a nice job as a template, and template only!
 * \version 20160618.013412
 * \date 2016-06-18
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _EXALL_H
#define _EXALL_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
/* Bibliotecas de conversão de autômatos */
/* #include "auto1.h" /1* AFND para AFD (afnd2afd) *1/ */
/* #include "auto2.h" /1* AFD para ER (afd2er) *1/ */
/* #include "auto3.h" /1* ER para AFND (er2afnd) *1/ */

/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20210512.104607" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */
#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_estlist
{
    int estado;
    struct st_estlist *prox;
} lest_t;

/* tipo lista encadeada simples da funcao de transicao */
typedef struct st_translist
{
    int ei;     /* estado inicial */
    char *lei;
    int ef;     /* estado final */
    struct st_translist *prox;
} ltrans_t;

/* lista de conjuntos de estdados*/
typedef struct st_conjlist
{
    int id;
    struct st_estlist *estados;
    struct st_conjlist *prox;
}lconj_t;

/* tipo quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    int S;   /* estado inicial */
    lest_t *F;               /* lista de estados finais */
    ltrans_t *D;               /* lista da funcao de transicao d(ei, le, ef) */
}quintupla_t;

typedef struct st_arvore
{
    char *expReg;
    int tipo_op; /*tipo de operador, 0->nao operador, 1 ->operador unario, 2->operador binario*/
    quintupla_t Q;
    struct st_arvore *esq, *dir, *pai;
}t_arvore;
/* Variaveis Global*/

int id_estado= 0;

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void automax_init(void);  /**< Initializes some operations before start */
void automax_update(void); /**< Updates values during program cycle */
/* int funcexample(int i, int *o, int *z); /1* just an example with complete doxygen fields *1/ */
/* t_quintupla entrada(void); /1* recebe os dados da quintupla do AFD *1/ */

/* INITS */
void ER_AFND_init(char *expReg); /* global initialization function */
void AFND_AFD_init(const char *arquivo);
void AFD_ER_init(const char *arquivo);
void entrada_Automato(quintupla_t *Q, const char *entrada); /* coleta a quintupla de arquivo formatado especifico*/

void entrada_ER(char *expReg, char *entrada);
void quebraExpressao(char *expReg, t_arvore **raiz);
void transformacao(t_arvore *raiz);
void salva_quintupla(quintupla_t Q, char *arquivo);

void separador(char *expReg, char **partEsc, char **partDir, char *op, int size);
void mini_quintupla(quintupla_t *q, char *lei);
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal);

/* Funções de Operação */
void operacao_estrela(quintupla_t *res, quintupla_t q);
void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2);
void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2);
void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op);
void uniao(ltrans_t **list);
void concatena(ltrans_t **list, int est);
char *estrela(ltrans_t **list, int ei_ef);
void concatena_aux(char **dest, char *ch, char *ch2);

void copia_ltrans(ltrans_t **dest, ltrans_t *list);
void copia_lestado(lest_t **dest, lest_t *list);

/* Funções de Verificação */
int tipo_operador(char info);
void modelando_conjunto(lconj_t *simultaneo, lest_t **list); /* A list entra com o conjunto de indices para os conjuntos de estados simultaneos*/
int igualdade_conjunto(lest_t *list, lest_t *list2); /* verifica se dois conjuntos sao identicos*/
void definir_final(lconj_t *conjunto, lest_t *final, lest_t **list);
void estados_limite(quintupla_t *Q);
int lista_unitaria(ltrans_t *list);
int definir_tamanho(char *ch, char *ch2);
int estado_eliminar(quintupla_t Q);
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2);

/* Funções de Estados*/
void estados_simultaneos(quintupla_t Q, lconj_t **simultaneo); /* Gerar os estados simultaneos*/
void estados_novos(quintupla_t Qantigo, quintupla_t *Qnovo, lconj_t *simultaneo); /* Gerar a quintupla para AFD*/
int novo_estado(lest_t *list, lconj_t **conj_estados); /* gera um novo estado (AFD) caso não haja estado igual*/
void primeiro_estado(lest_t **estados, lconj_t *simultaneo, int s); /* busca entre o estados simultaneos o que o estados inicial, tal conjunto se torna o estado inicial da AFD*/
void copia_estado(lest_t **estados, lconj_t *simultaneo, int s); /* copia um conjunto dos estados simultanenos para um conjunto separado*/

/* Funções Insert*/
void insere_arvore(t_arvore **raiz, t_arvore *ant, char *info);
void insere_estado(lest_t **list, int est);
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef);
void insere_conjunto(lconj_t **list, int id);
void insere_conjuntoFULL(lconj_t **conjunto, lest_t *list, int id);


/* Funções de Coleta */
void coleta_final(lest_t **list, FILE *stream);
void coleta_transicao(ltrans_t **list, FILE *stream);

/* Funções de Impressão */
void imprime_transicao(ltrans_t *list, FILE *stream);
void imprime_estados(lest_t *list, FILE *stream);
void imprime_arvore(t_arvore *raiz, FILE *stream);

/* Funções de Busca */
lconj_t *busca_conjunto(lconj_t *list, int id); /* Busca um conjunto na lista pelo identificador único */
ltrans_t *busca_simultaneo(ltrans_t *list, int ref); /* Busca uma transição simultânea (epsilon) na lista */
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei); /* Busca uma transição na lista pelo estado inicial e rótulo */
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef); /* Busca uma transição na lista pelo estado inicial e final */
ltrans_t *busca_por_ei(ltrans_t *list, int est); /* Busca uma transição na lista pelo estado inicial */
ltrans_t *busca_por_ef(ltrans_t *list, int est); /* Busca uma transição na lista pelo estado final */

/* Funções de remoção */
void remove_estado(lest_t **list, lest_t *r); /* Remove um estado específico de uma lista de estados */
void remove_transicao(ltrans_t **list, ltrans_t *r); // Remove uma transição específica de uma lista de transições
void remove_conjunto(lconj_t **list, lconj_t *r); /* Remove um conjunto específico de uma lista de conjuntos */
void apaga_estados(lest_t **list); /* Libera todos os estados de uma lista de estados */
void apaga_conjunto(lconj_t **list); /* Libera todos os conjuntos de uma lista de conjuntos */
void apaga_transicao(ltrans_t **list); /* Libera todas as transições de uma lista de transições */

#endif /* NOT def _EXALL_H */
//END OF CODE
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

