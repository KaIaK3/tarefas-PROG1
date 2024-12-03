/***************************************************************************
 *   ex7.h                                    Version 20160806.231942      *
 *                                                                         *
 *   Petri Net Simulator - header file                                     *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
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
 * \file ex7.h
 * \ingroup GroupUnique
 * \brief Petri Net Simulator - header file
 * \details This program really do a nice job as a template, and template only!
 * \version 20160806.231942
 * \date 2016-08-06
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

#ifndef _EX7_H
#define EX7_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h>  /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h>/* get options from system argc/argv */
#include <time.h>  /* Time and date functions */
#include <math.h>  /* Mathematics functions */
#include <string.h>  /* Strings functions definitions */
#include <malloc.h>  /* Dynamic memory allocation */
#include <stdbool.h> /* Boolean Functions */
#include <unistd.h>  /* UNIX standard function */
/* #include <dlfcn.h> */ /* Dynamic library */
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
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex7.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160806.231942" /**< Version Number (string) */
#endif
#define MAX_PLACES 100
#define MAX_TRANSITIONS 100
#define MAX_ARCS 200
#define CEM_POR 100
#define CHA_DIS 50
#define MAX_TOKENS_LUGAR 100
#define MAX_ITE 100
#define MAX_EXP 100

/* arco consumidor LT */
typedef struct
{
    int place;
    int transition;
    int weight;
} ArcLT;


/* arco produtor TL */
typedef struct
{
    int transition;
    int place;
    int weight;
} ArcTL;


typedef struct
{
    int id;
    int tokens;
} Place;


typedef struct
{
    int id;
    int *output_places;
    int *inputPlaces;
    int numInputPlaces;
    int numOutputPlaces;
} Transition;


typedef struct PlaceNode
{
    Place place;
    int id;
    int tokens;
    int places;
    struct PlaceNode *next;
} PlaceNode;


typedef struct TransitionNode
{
    Transition transition;
    int id;
    int *outputplaces;
    int *inputPlaces;
    int numInputPlaces;
    int numOutputPlaces;
    int tokens;
    struct TransitionNode *next;
} TransitionNode;


typedef struct ArcLTNode
{
    ArcLT arcLT;
    struct ArcLTNode *next;
    int place;
    int transition;
    int weight;
} ArcLTNode;


typedef struct ArcTLNode
{
    ArcTL arcTL;
    int place;
    int transition;
    int weight;
    struct ArcTLNode *next;
} ArcTLNode;

typedef struct
{
    PlaceNode *places;
    TransitionNode *transitions;
    ArcLTNode *arcsLT;
    ArcTLNode *arcsTL;
    int num_places;
    int num_transitions;
    int num_arcsLT;
    int num_arcsTL;
} PetriNet;

typedef struct lugar
{
    int num_tokens;
    struct lugar* prox;
} lugar_t;

lugar_t* criar_lugar(int num_tokens);

//TEST FUNCTIONS
typedef struct token_t
{
    int num_tokens;
    struct token_t *prox;
} token_t;

typedef struct arco_t
{
    int lugar;
    int transicao;
    int tokens;
    struct arco_t *prox;
} arco_t;

typedef struct rede_t
{
    int num_lugares;
    int num_transicoes;
    int num_arcos_consumidores;
    int num_arcos_produtores;
    token_t *primeiro_token_estatico;
    token_t *primeiro_token;
    arco_t *primeiro_arco;
} rede_t;

typedef struct dado_token_t
{
    int minimo;
    int maximo;
    double media;
    double desvio_padrao;
    struct dado_token_t *prox;
} dado_token_t;

typedef struct dado_t
{
    int num_exp;
    int num_exp_finalizados;
    int num_ite;
    double num_medio_ite;
    double exp_seg;
    double ite_seg;
    double trans_seg;
    double temp_total;
    dado_token_t *primeiro_token;
} dado_t;

typedef struct bola_t
{
    int valor;
    struct bola_t *proximo;
} bola_t;

typedef struct saco_t
{
    int tamanho;
    bola_t *cabeca;
} saco_t;

//FIM STRUCS TEST

/* Função para disparar uma transição */
void disparar(TransitionNode t, PlaceNode* places, int num_tokens_necessarios)
{
    for (int i = 0; i < t.numInputPlaces; i++)
    {
        places[t.inputPlaces[i]].tokens -= num_tokens_necessarios;
    }
    for (int i = 0; i < t.numOutputPlaces; i++)
    {
        places[t.outputplaces[i]].tokens += num_tokens_necessarios;
    }
}

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

//TEST PROTOTYPES

void rede_init(rede_t **rede, saco_t **saco, dado_t **dado); //Inicia a rede
void end_rede(rede_t **rede, saco_t **saco, dado_t **dado); //Finaliza a rede

int criar_rede(rede_t **rede); //Cria a rede
void apagar_rede(rede_t **rede); //Apaga a rede

int criar_dado(dado_t **dado, int num_tokens); //Cria os dados usados na rede
void apagar_dado(dado_t **dado); //Apaga os dados utilizados
void atualizar_dados(rede_t *rede, dado_t *dado); //Atualiza os dados da rede
void imprimir_dados(dado_t *dado); //Imprime os dados da rede

void ler_rede(rede_t *rede); //Le a rede
int update_rede(rede_t *rede, saco_t *saco); //Atualiza a rede
void imprimir_rede(rede_t *rede); //Imprime a rede

int verificar_transicao(rede_t *rede, int transicao_sorteada); //Verifica a transição
int transicao_habilitada(rede_t *rede, int transicao_sorteada);
int transicao_quer_disparar(void); //Verifica se a transiçao quer disparar
void disparar_transicao(rede_t *rede, int transicao_sorteada); //Disparo
void reiniciar_tokens(rede_t *rede); //Reinicia os tokens da rede

int inserir_token(token_t **token, token_t **token_estatico); //Insere os tokens
int apagar_token(token_t **token); //Apaga os tokens

int inserir_arco(arco_t **arco, int num_arcos_consumidores); //Insere os arcos usados na rede
int apagar_arco(arco_t **arco); //Apaga os arcos

int criar_saco(saco_t **saco); //Cria o saco da rede
int apagar_saco(saco_t **saco); //Apaga o saco
int inserir_bola(saco_t *saco, int valor); //Insere as bolas
int remover_bola_cabeca(saco_t *saco); //Remove as bolas
int remover_bola_aleatoria(saco_t *saco, int posicao); //Remove bolas aleatorias
int encher_saco(saco_t *saco, int quantidade); //Enche o saco da rede
int esvaziar_saco(saco_t *saco); //Esvazia o saco
void imprimir_saco(saco_t *saco); //Imprime o saco
int sortear_bola(saco_t *saco); //Sorteia a bola
int conferir_saco(saco_t *saco); //Confere o saco

int remover_tokens(rede_t *rede, int quantidade); //Remove tokens
int remover_arcos(rede_t *rede, int lugar, int transicao, int quantidade); //Remove arcos

double calcular_desvio_padrao(dado_t *dado); //Calcula o desvio padrao dos dados
void mostrar_lugares_inalcancaveis_overflow(rede_t *rede); //Mostra lugares inalcançaveis
void debug(const char *message); //Mensagem de debug
//NOVOS PROTOTIPOS



#endif /* NOT def _EX3_H */



/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */


