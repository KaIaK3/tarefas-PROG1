/***************************************************************************
 *   auto3.h                                 Version 20210512.104607         *
 *   ER to AFND                                                            *
 *                                                                         *
 *   Library for auto3, a program that converts ER into AFND                 *
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
 * \file auto3.h
 * \ingroup GroupUnique
 * \brief Converte ER para AFND
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

#ifndef _EX14_H
#define _EX14_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <malloc.h>  /* Dynamic memory allocation */
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
struct final
{
    unsigned short int value; /* num estado final */
    struct final *prox;  /* prox nodo */
};

/* tipo lista encadeada simples da funcao de transicao delta */
struct delta
{
    unsigned short int Ei;  /* estado inicial */
    char Le;               /* string com rotulos dos arcos */
    unsigned short int Ef;  /* estado destino final */
    struct delta *prox;  /* prox nodo */
};

/* tipo quintupla: representacao formal de um automato */
struct automato
{
    unsigned short int K;   /* numero de estados K=3 -> estados q0, q1 e q2 */
    char A;                 /* ultima letra do alfabeto A=b -> {a,b} */
    unsigned short int S;   /* estado inicial */
    struct final *F;               /* lista de estados finais */
    struct delta *D;             /* lista da funcao de transicao d(ei, le, ef) */
};

/* tipo lista encadeada simples dos estados finais */
typedef struct st_estlist
{
    int estado;
    struct st_estlist *prox;
} lest_t;

/* type lista encadeada simples da funcao de transicao */
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
} lconj_t;

/* type quintupla: representacao formal de um automato */
typedef struct st_quintupla
{
    int K;   /* conjunto de estados */
    char A;                 /* alfabeto */
    int S;   /* estado inicial */
    lest_t *F;               /* lista de estados finais */
    ltrans_t *D;               /* lista da funcao de transicao d(ei, le, ef) */
} quintupla_t;

typedef struct st_tree
{
    char *expReg;
    int type_op; /*type de operador, 0->nao operador, 1 ->operador unario, 2->operador binario*/
    quintupla_t Q;
    struct st_tree *left, *right, *pai;
} t_tree;
/* Variaveis Global*/

int id_state = 0;

/* ---------------------------------------------------------------------- */
/* prototypes */
void insert_ER_padrao(char *expReg);
void auto3_init_entrada_padrao(void);/* inicializa com entrada padrao */
void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void auto3_init(char *expReg); /* global initialization function */
void auto3_update(void); /**< Updates values during program cycle */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */
void entrada_nao_reconhecida(void); /* erro na leitura */
void insert_ER(char *expReg, char *insert);
void quebraExpressao(char *expReg, t_tree **raiz);
void transformacao(t_tree *raiz);
void coleta_final(lest_t **list, FILE *stream); /* auxiliar da funcao insert_dados(), coleta do arquivo os estados finais*/
void coleta_transicao(ltrans_t **list, FILE *stream);
int type_operador(char info);

/* Funções de separação do conjunto em subconjuntos */
void separator(char *expReg, char **partEsc, char **partright, char *op, int size); /* Separa a expressão regular em subconjuntos */
void mini_quintupla(quintupla_t *q, char *lei); /* Cria uma mini quíntupla a partir de uma string */
void transitions_finais(ltrans_t **dest, lest_t *list, int novoFinal); /* Atualiza a lista de transições finais */

/* Tipos de operações */
void operacao_estrela(quintupla_t *res, quintupla_t q); /* Aplica a operação estrela de Kleene */
void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2); /* Aplica a operação OU (disjunção) */
void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2); /* Aplica a operação E (conjunção) */
void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op); /* Aplica uma operação geral entre quíntuplas */

void copia_ltrans(ltrans_t **dest, ltrans_t *list); /* Copia uma lista de transições */
void copia_lestado(lest_t **dest, lest_t *list); /* Copia todos os estados da lista 'list' para a lista 'dest', preservando a ordem */
void coleta_final(lest_t **list, FILE *stream); /* Coleta os estados finais a partir de um stream */
void coleta_transicao(ltrans_t **list, FILE *stream); /* Coleta as transições a partir de um stream */

void entrada_padrao(char *expReg);
void insert_Automato(quintupla_t *Q, const char *insert); /* coleta a quintupla de arquivo formatado especifico*/
void insert_estado(lest_t **list, int est); /* Coloca um estado em uma lista ordenada */
void insert_transicao(ltrans_t **list, int ei, char *lei, int ef); /* Insere uma transição no final de uma lista de transições */
void insert_tree(t_tree **raiz, t_tree *ant, char *info); /* Coloca um nó em uma árvore binária de expressões */

void imprime_transicao(ltrans_t *list, FILE *stream); /* Imprime as transições de uma lista para um arquivo */
void imprime_estados(lest_t *list, FILE *stream); /* Imprime os estados de uma lista para um arquivo */
void imprime_tree(t_tree *raiz, FILE *stream); /* Imprime a árvore em pré-ordem para um arquivo */
void salva_quintupla(quintupla_t Q, char *arquivo); /* Imprime quintupla na tela */
lconj_t *busca_conjunto(lconj_t *list, int id); /* Busca um conjunto específico por ID em uma lista de conjuntos */
ltrans_t *busca_simultaneo(ltrans_t *list, int ref); /* Busca uma transicao cujo o estado de referencia (ref) seja simutaneo*/
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei); /* Busca uma transição por estado inicial (ei) e símbolo lido (lei) em lista */
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef); /* Procura primeira transição na lista tendo o estado inicial igual a est */
ltrans_t *busca_por_ei(ltrans_t *list, int est); /* Procura a primeira transição na lista que tenha o estado inicial igual a est */
ltrans_t *busca_por_ef(ltrans_t *list, int est); /* Procura a primeira transição na lista que tenha o estado final igual a est */

void remove_transicao(ltrans_t **list, ltrans_t *r); /* Remove uma transição específica de uma lista de transições */
void remove_estado(lest_t **list, lest_t *r); /* Remove um estado específico de uma lista de estados */
void remove_conjunto(lconj_t **list, lconj_t *r); /* Remove um conjunto específico de uma lista de conjuntos */
void apaga_estados(lest_t **list); /* Libera todos os estados de uma lista de estados */
void apaga_conjunto(lconj_t **list); /* Libera todos os conjuntos de uma lista de conjuntos */
void apaga_transicao(ltrans_t **list); /* Libera todas as transições de uma lista de transições */

#endif /* NOT def _EX14_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

