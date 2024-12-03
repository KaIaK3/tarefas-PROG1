/***************************************************************************
 *   auto1.h                                 Version 20210512.104607         *
 *   AFND to AFD                                                           *
 *                                                                         *
 *   Converte AFND para AFD                                                *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
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
 * \file auto1.h
 * \ingroup GroupUnique
 * \brief Converte AFND para AFD
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

#ifndef _EX12_H
#define _EX12_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <stdbool.h>
#include <string.h> /* Strings functions definitions */
#include <malloc.h>  /* Dynamic memory allocation */
#include <time.h> /* Time and date functions */
#include <math.h> /* Mathematics functions */
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
char sfile[256];

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */

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

typedef struct st_quintupla
{
    int K; /* conjunto de estados */
    char A;/* alfabeto */
    int S; /* estado inicial */
    lest_t *F; /* lista de estados finais */
    ltrans_t *D;/* lista da funcao de transicao d(ei, le, ef) */
} quintupla_t;

typedef struct st_arvore
{
    char *expReg;
    int tipo_op; /*tipo de operador, 0->nao operador, 1 ->operador unario, 2->operador binario*/
    quintupla_t Q;
    struct st_arvore *esq, *dir, *pai;
} t_arvore;

typedef struct st_conjlist
{
    int id;
    struct st_estlist *estados;
    struct st_conjlist *prox;
} lconj_t;

int id_estado = 0;
/* ---------------------------------------------------------------------- */
/* prototypes */
void help(void);
void copyr(void);
void auto1_init_entrada_padrao(void);
void auto1_init(const char *entrada);
void auto1_update(void);
void auto1_entrada_padrao(quintupla_t *Q);
void estados_simultaneos(quintupla_t Q, lconj_t **simultaneo);
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
void salva_quintupla(quintupla_t Q, char *arquivo); /* armazena uma quintupla no arquivo com o nome dado, ou imprime na tela*/
void coleta_final(lest_t **listm, FILE *stream); /* auxiliar da funcao entrada_dados(), coleta do arquivo os estados finais*/
void coleta_transicao(ltrans_t **list, FILE *stream);/* auxiliar da funcao entrada_dados(), coleta do arquivo as transicoes*/

void insere_estado(lest_t **list, int est);
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef);
void imprime_conjunto(lconj_t *list, FILE *stream);
void imprime_transicao(ltrans_t *list, FILE *stream);
void imprime_estados(lest_t *list, FILE *stream);
void imprime_arvore(t_arvore *raiz, FILE *stream);
void insere_conjunto(lconj_t **list, int id);
void insere_conjuntoFULL(lconj_t **conjunto, lest_t *list, int id);
lconj_t *busca_conjunto(lconj_t *list, int id);
void entrada_Automato(quintupla_t *Q, const char *entrada); /* coleta a quintupla de arquivo formatado especifico*/
int igualdade_conjunto(lest_t *list, lest_t *list2); /* verifica se dois conjuntos sao identicos*/
void definir_final(lconj_t *conjunto, lest_t *final, lest_t **list);
void estados_novos(quintupla_t Qantigo, quintupla_t *Qnovo, lconj_t *simultaneo);
int novo_estado(lest_t *list, lconj_t **conj_estados);
void modelando_conjunto(lconj_t *simultaneo, lest_t **list);
void copia_estado(lest_t **estados, lconj_t *simultaneo, int s);
void primeiro_estado(lest_t **estados, lconj_t *simultaneo, int s);
void remove_estado(lest_t **list, lest_t *r);
void remove_transicao(ltrans_t **list, ltrans_t *r); /* Busca uma transicao cujo o estado de referencia (ref) seja simutaneo*/
ltrans_t *busca_simultaneo(ltrans_t *list, int ref);
ltrans_t *busca_por_ei(ltrans_t *list, int est);
ltrans_t *busca_por_ef(ltrans_t *list, int est);
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei);
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef);
void apaga_estados(lest_t **list);
void apaga_transicao(ltrans_t **list);
void apaga_conjunto(lconj_t **list);
#endif /* NOT def _EX12_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

