/***************************************************************************
 *   auto2.h                                 Version 20210512.104607         *
 *   AFD to ER                                                             *
 *                                                                         *
 *   Library for auto2, a program that convert AFD into Exp Reg              *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License                *
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
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file auto2.h
 * \ingroup GroupUnique
 * \brief Converte AFD para ER
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

#ifndef _EX13_H
#define _EX13_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */

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

#ifndef VERSION
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

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* tipo lista encadeada simples dos estados finais */
typedef struct st_lef
{
    unsigned short int f; /* num estado final */
    struct st_lef *prox;  /* prox nodo */
} t_lef;

typedef struct st_estlist
{
    int estado;
    struct st_estlist *prox;
} lest_t;

/* tipo lista encadeada simples da funcao de transicao delta */
typedef struct st_delta
{
    unsigned short int ei;  /* estado inicial */
    char *le;               /* string com rotulos dos arcos */
    unsigned short int ef;  /* estado destino final */
    struct st_delta *prox;  /* prox nodo */
} t_delta;

typedef struct st_translist
{
    int ei;     /* estado inicial */
    char *lei;
    int ef;     /* estado final */
    struct st_translist *prox;
} ltrans_t;

typedef struct st_quintupla
{
    int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    int S;   /* estado inicial */
    lest_t *F;               /* lista de estados finais */
    ltrans_t *D;               /* lista da funcao de transicao d(ei, le, ef) */
} quintupla_t;

typedef struct st_arvore
{
    char *expReg;
    int tipo_op; /*tipo de operador, 0->nao operador, 1 ->operador unario, 2->operador binario*/
    quintupla_t Q;
    struct st_arvore *esq, *dir, *pai;
} t_arvore;

/* lista de conjuntos de estados */
typedef struct st_conjlist
{
    int id;
    struct st_estlist *estados;
    struct st_conjlist *prox;
} lconj_t;



/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void auto2_init(const char *arquivo);
void auto2_update(void); /* Updates values during programi */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
void auto2_entrada(quintupla_t *Q, const char *entrada);
void coleta_final(lest_t **list, FILE *stream);
void coleta_transicao(ltrans_t **list, FILE *stream);
void salva_quintupla(quintupla_t Q, char *arquivo);
void uniao(ltrans_t **list);
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal);
void estados_limite(quintupla_t *Q);
int lista_unitaria(ltrans_t *list);
int eliminar_estado(quintupla_t Q);
void concatenacao(ltrans_t **list, int est);
void concatenacao_aux(char **dest, char *ch, char *ch2);
char *estrela(ltrans_t **list, int ei_ef);
int def_tamanho(char *ch, char *ch2);
void imprime_estados(lest_t *list, FILE *stream);
void imprime_arvore(t_arvore *raiz, FILE *stream);
void imprime_transicao(ltrans_t *list, FILE *stream);
void imprime_estados(lest_t *list, FILE *stream);
void imprime_arvore(t_arvore *raiz, FILE *stream);
void insere_estado(lest_t **list, int est);
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef);
void remove_estado(lest_t **list, lest_t *r);
void remove_transicao(ltrans_t **list, ltrans_t *r);
void apaga_estados(lest_t **list);
void apaga_transicao(ltrans_t **list);
void remove_conjunto(lconj_t **list, lconj_t *r);
void apaga_conjunto(lconj_t **list);
void auto2_init_entrada_padrao(void);
void auto2_entrada_padrao(quintupla_t *Q);


lconj_t *busca_conjunto(lconj_t *list, int id);                /* Busca um conjunto na lista pelo identificador único */
ltrans_t *busca_simultaneo(ltrans_t *list, int ref);           /* Busca uma transição simultânea (epsilon) na lista */
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei);  /* Busca uma transição na lista pelo estado inicial e rótulo */
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef); /* Busca uma transição na lista pelo estado inicial e final */
ltrans_t *busca_por_ei(ltrans_t *list, int est);               /* Busca uma transição na lista pelo estado inicial */
ltrans_t *busca_por_ef(ltrans_t *list, int est);               /* Busca uma transição na lista pelo estado final */
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2); /* Busca transições semelhantes na lista */

#endif /* NOT def _EX13_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */
