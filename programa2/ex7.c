/***************************************************************************
 *   ex7.c                                    Version 20160806.231815      *
 *                                                                         *
 *   Petri Net Simulator                                                   *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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
 * @file ex7.c
 * @ingroup GroupUnique
 * @brief Petri Net Simulator
 * @details This program really do a nice job as a template, and template only!
 * @version 20160806.231815
 * @date 2016-08-06
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
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
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc ex7.c -o ex7.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex3.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include "ex7.h" /* To be created for this template if needed */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */

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
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160806.231815" /**< Version Number (string) */
#endif

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
/* prototypes */


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./ex3 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160806.231815
 * @date 2016-08-06
 *
 */
int main(void)
{
    srand(time(NULL));
    int exp_cont, ite_cont;
    clock_t inicio_total, fim_total;
    rede_t *rede = NULL;
    saco_t *saco = NULL;
    dado_t *dado = NULL;

    rede_init(&rede, &saco, &dado); /* initialization function */

    inicio_total = clock();

    for(exp_cont = 0; exp_cont < MAX_EXP; ++exp_cont)
    {
        reiniciar_tokens(rede);

        for(ite_cont = 0; ite_cont < MAX_ITE; ++ite_cont)
        {
            encher_saco(saco, rede->num_transicoes);

            if(!update_rede(rede, saco))
            {
                dado->num_exp_finalizados++;
                break;

            }
        }

        dado->num_ite += ite_cont;
        atualizar_dados(rede, dado);
    }

    fim_total = clock();


    mostrar_lugares_inalcancaveis_overflow(rede);

    dado->num_exp = exp_cont;
    dado->temp_total = ((double)(fim_total - inicio_total))/CLOCKS_PER_SEC;
    dado->exp_seg = exp_cont/dado->temp_total;
    dado->ite_seg = dado->num_ite/dado->temp_total;
    dado->num_medio_ite = (double)dado->num_ite/dado->num_exp;
    dado->trans_seg = (rede->num_transicoes*dado->num_ite*dado->num_exp)/dado->temp_total;
    imprimir_dados(dado);
    double desvio_padrao = calcular_desvio_padrao(dado);
    printf("Desvio Padrão: %lf\n", desvio_padrao);

    end_rede(&rede, &saco, &dado);

    return EXIT_SUCCESS;
}
/* ---------------------------------------------------------------------- */
/* Rede de petri */
PetriNet *createPetriNet()
{
    PetriNet *net = (PetriNet *)malloc(sizeof(PetriNet));
    net->places = NULL;
    net->transitions = NULL;
    net->arcsLT = NULL;
    net->arcsTL = NULL;
    net->num_places = 0;
    net->num_transitions = 0;
    net->num_arcsLT = 0;
    net->num_arcsTL = 0;
    return net;
}

/* ---------------------------------------------------------------------- */
//Funcoes leitura
void rede_init(rede_t **rede, saco_t **saco, dado_t **dado)
{
    IFDEBUG("ex7_init()");
    /* initialization */
    criar_rede(rede);
    ler_rede(*rede);
    criar_saco(saco);
    encher_saco(*saco, (*rede)->num_transicoes);
    criar_dado(dado, (*rede)->num_lugares);

    return;
}
/* ---------------------------------------------------------------------- */
void end_rede(rede_t **rede, saco_t **saco, dado_t **dado)
{
    apagar_rede(rede);
    apagar_saco(saco);
    apagar_dado(dado);
}
/* ---------------------------------------------------------------------- */
int criar_rede(rede_t **rede)
{
    if(!(*rede = malloc(sizeof(rede_t))))
    {
        fprintf(stderr, "Erro ao alocar memoria para rede!\n");
        return 0;
    }

    (*rede)->num_lugares = 0;
    (*rede)->num_transicoes = 0;
    (*rede)->num_arcos_consumidores = 0;
    (*rede)->num_arcos_produtores = 0;
    (*rede)->primeiro_token_estatico = NULL;
    (*rede)->primeiro_token = NULL;
    (*rede)->primeiro_arco = NULL;

    return 1;
}
/* ---------------------------------------------------------------------- */
void apagar_rede(rede_t **rede)
{
    while(apagar_token(&(*rede)->primeiro_token_estatico));
    while(apagar_token(&(*rede)->primeiro_token));
    while(apagar_arco(&(*rede)->primeiro_arco));

    free(*rede);
    *rede = NULL;
}
/* ---------------------------------------------------------------------- */
int criar_dado(dado_t **dado, int num_tokens)
{
    int i;
    dado_token_t *novo_token = NULL;
    dado_token_t *auxiliar = NULL;
    dado_token_t *auxiliar_2 = NULL;

    if(!(*dado = malloc(sizeof(dado_t))))
    {
        fprintf(stderr, "Erro ao alocar memoria para dado!\n");
        return 0;
    }

    (*dado)->num_exp = 0;
    (*dado)->num_exp_finalizados = 0;
    (*dado)->num_ite = 0;
    (*dado)->num_medio_ite = 0;
    (*dado)->exp_seg = 0;
    (*dado)->ite_seg = 0;
    (*dado)->trans_seg = 0;
    (*dado)->temp_total = 0;
    (*dado)->primeiro_token = NULL;

    for(i = 0; i < num_tokens; ++i)
    {
        novo_token = NULL;
        auxiliar = (*dado)->primeiro_token;
        auxiliar_2 = NULL;

        if(!(novo_token = malloc(sizeof(dado_token_t))))
        {
            fprintf(stderr, "Erro ao alocar memoria para dado_token_t\n");
            return 0;
        }

        novo_token->minimo = 0;
        novo_token->maximo = 0;
        novo_token->media = 0;
        novo_token->desvio_padrao = 0;
        novo_token->prox = NULL;

        while(auxiliar != NULL)
        {
            auxiliar_2 = auxiliar;
            auxiliar = auxiliar->prox;
        }

        if(auxiliar_2 != NULL)
            auxiliar_2->prox = novo_token;
        else
            (*dado)->primeiro_token = novo_token;
    }

    return 1;
}
/* ---------------------------------------------------------------------- */
void apagar_dado(dado_t **dado)
{
    dado_token_t *auxiliar = (*dado)->primeiro_token;

    while(!(*dado)->primeiro_token)
    {
        (*dado)->primeiro_token = auxiliar->prox;
        free(auxiliar);
    }

    free(*dado);
    *dado = NULL;
}
/* ---------------------------------------------------------------------- */
void atualizar_dados(rede_t *rede, dado_t *dado)
{
    token_t *token = rede->primeiro_token;
    dado_token_t *dado_token = dado->primeiro_token;

    while(token)
    {
        if(token->num_tokens < dado_token->minimo)
            dado_token->minimo = token->num_tokens;
        if(token->num_tokens > dado_token->maximo)
            dado_token->maximo = token->num_tokens;
        dado_token->media += token->num_tokens;

        token = token->prox;
        dado_token = dado_token->prox;
    }
}
/* ---------------------------------------------------------------------- */
void imprimir_dados(dado_t *dado)
{
    int cont = 0;
    dado_token_t *token = dado->primeiro_token;

    printf("Tempo Total: %lfs\n", dado->temp_total);
    printf("Numero de experimentos: %d\n", dado->num_exp);
    printf("Numero de experimentos finalizados: %d\n", dado->num_exp_finalizados);
    printf("Numero medio de iteracoes por experimento: %lf\n", dado->num_medio_ite);
    printf("Experimentos por segundo: %lf\n", dado->exp_seg);
    printf("Iteracoes por segundo: %lf\n", dado->ite_seg);
    printf("Transicoes por segundo: %lf\n", dado->trans_seg);

    while(token)
    {
        printf("-----------------------------------------------------\n");
        printf("Lugar %d:\n", cont);
        printf("Minimo: %d\n", token->minimo);
        printf("Maximo: %d\n", token->maximo);
        printf("Media: %lf\n", token->media / dado->num_exp);

        token = token->prox;
        cont++;
    }
}
/* ---------------------------------------------------------------------- */
void ler_rede(rede_t *rede)
{
    int i;

    printf("Quantos lugares?\n");
    scanf("%d", &rede->num_lugares);
    printf("Quantas transições?\n");
    scanf("%d", &rede->num_transicoes);
    printf("Quantos arcos consumidores LT?\n");
    scanf("%d", &rede->num_arcos_consumidores);
    printf(" Quantos arcos produtores TL?\n");
    scanf("%d", &rede->num_arcos_produtores);

    printf("Quantos tokens em cada lugar (separados por espaço)?\n");
    for(i = 0; i < rede->num_lugares; ++i)
        inserir_token(&rede->primeiro_token, &rede->primeiro_token_estatico);
    for(i = 0; i < rede->num_arcos_consumidores + rede->num_arcos_produtores; ++i)
        inserir_arco(&rede->primeiro_arco, rede->num_arcos_consumidores);
/* ---------------------------------------------------------------------- */}

int update_rede(rede_t *rede, saco_t *saco)
{
    int transicao_sorteada, rede_finalizada = 1, habilitada;

    while(saco->tamanho)
    {
        transicao_sorteada = sortear_bola(saco) - 1;

        if((habilitada = verificar_transicao(rede, transicao_sorteada)) == 1)
            disparar_transicao(rede, transicao_sorteada);
        else
            if(habilitada)
                rede_finalizada = 0;
    }

    if(rede_finalizada)
        return 0;
    else
        return 1;
}
/* ---------------------------------------------------------------------- */
void imprimir_rede(rede_t *rede)
{
    int i;
    token_t *token = rede->primeiro_token;
    arco_t *arco = rede->primeiro_arco;

    printf("%d\n", rede->num_lugares);
    printf("%d\n", rede->num_transicoes);
    printf("%d\n", rede->num_arcos_consumidores);
    printf("%d\n", rede->num_arcos_produtores);

    for(i = 0; i < rede->num_lugares; ++i)
    {
        printf("%d ", token->num_tokens);
        token = token->prox;
    }
    printf("\n");
    for(i = 0; i < rede->num_arcos_consumidores; ++i)
    {
        printf("%d %d %d\n", arco->lugar, arco->transicao, arco->tokens);
        arco = arco->prox;
    }
    for(i = 0; i < rede->num_arcos_produtores; ++i)
    {
        printf("%d %d %d\n", arco->transicao, arco->lugar, arco->tokens);
        arco = arco->prox;
    }
}
/* ---------------------------------------------------------------------- */
int verificar_transicao(rede_t *rede, int transicao_sorteada)
{
    int pode = 0;

    if((pode = transicao_habilitada(rede, transicao_sorteada)) && transicao_quer_disparar())
        return 1;
    else
        if(pode)
            return 2;
        else
            return 0;
}
/* ---------------------------------------------------------------------- */
int transicao_habilitada(rede_t *rede, int transicao_sorteada)
{
    int i, j;
    arco_t *arco = rede->primeiro_arco;
    token_t *token = NULL;

    for(i = 0; i < rede->num_arcos_consumidores; i++)
    {
        token = rede->primeiro_token;

        if(arco->transicao != transicao_sorteada)
        {
            arco = arco->prox;
            continue;
        }

        for(j = 0; j < arco->lugar; ++j)
            token = token->prox;

        if(arco->tokens > token->num_tokens)
            return 0;

        arco = arco->prox;
    }

    return 1;
}
/* ---------------------------------------------------------------------- */
int transicao_quer_disparar(void)
{
    int numero_sorteado = rand() % CEM_POR;

    if(numero_sorteado <= CHA_DIS - 1)
        return 1;
    else
        return 0;
}
/* ---------------------------------------------------------------------- */
void disparar_transicao(rede_t *rede, int transicao_sorteada)
{
    int i, j;
    arco_t *arco = rede->primeiro_arco;
    token_t *token = NULL;

    for(i = 0; i < rede->num_arcos_consumidores; ++i)
    {
        token = rede->primeiro_token;

        if(arco->transicao != transicao_sorteada)
        {
            arco = arco->prox;
            continue;
        }

        for(j = 0; j < arco->lugar; ++j)
            token = token->prox;

        token->num_tokens -= arco->tokens;
        arco = arco->prox;
    }

    for(i = 0; i < rede->num_arcos_produtores; ++i)
    {
        token = rede->primeiro_token;

        if(arco->transicao != transicao_sorteada)
        {
            arco = arco->prox;
            continue;
        }

        for(j = 0; j < arco->lugar; ++j)
            token = token->prox;

        token->num_tokens += arco->tokens;
        arco = arco->prox;
    }
}
/* ---------------------------------------------------------------------- */
void reiniciar_tokens(rede_t *rede)
{
    token_t *token = rede->primeiro_token;
    token_t *token_estatico = rede->primeiro_token_estatico;

    while(token != NULL)
    {
        token->num_tokens = token_estatico->num_tokens;
        token = token->prox;
        token_estatico = token_estatico->prox;
    }
}
/* ---------------------------------------------------------------------- */
int inserir_token(token_t **token, token_t **token_estatico)
{
    int num_tokens;
    token_t *auxiliar = *token;
    token_t *auxiliar_2 = NULL;
    token_t *novo_token = NULL;

    if(!(novo_token = malloc(sizeof(token_t))))
    {
        fprintf(stderr, "Erro ao alocar memoria para token!\n");
        return 0;
    }

    while(auxiliar != NULL)
    {
        auxiliar_2 = auxiliar;
        auxiliar = auxiliar->prox;
    }

    scanf("%d", &novo_token->num_tokens);
    novo_token->prox = NULL;
    num_tokens = novo_token->num_tokens;

    if(auxiliar_2 != NULL)
        auxiliar_2->prox = novo_token;
    else
        *token = novo_token;

    auxiliar = *token_estatico;
    auxiliar_2 = NULL;
    novo_token = NULL;

    if(!(novo_token = malloc(sizeof(token_t))))
    {
        fprintf(stderr, "Erro ao alocar memoria para token!\n");
        return 0;
    }

    while(auxiliar != NULL)
    {
        auxiliar_2 = auxiliar;
        auxiliar = auxiliar->prox;
    }

    novo_token->num_tokens = num_tokens;
    novo_token->prox = NULL;

    if(auxiliar_2 != NULL)
        auxiliar_2->prox = novo_token;
    else
        *token_estatico = novo_token;

    return 1;
}
/* ---------------------------------------------------------------------- */
int apagar_token(token_t **token)
{
    token_t *auxiliar = *token;

    if(*token != NULL)
    {
        *token = auxiliar->prox;
        free(auxiliar);
        return 1;
    }

    return 0;
}
/* ---------------------------------------------------------------------- */
int inserir_arco(arco_t **arco, int num_arcos_consumidores)
{
    int arco_indice = 0;
    arco_t *auxiliar = *arco;
    arco_t *auxiliar_2 = NULL;
    arco_t *novo_arco = NULL;

    if(!(novo_arco = malloc(sizeof(arco_t))))
    {
        fprintf(stderr, "Erro ao alocar memoria para arco!\n");
        return 0;
    }

    while(auxiliar != NULL)
    {
        auxiliar_2 = auxiliar;
        auxiliar = auxiliar->prox;
        arco_indice++;
    }

    if(arco_indice < num_arcos_consumidores)
        scanf("%d%d%d", &novo_arco->lugar, &novo_arco->transicao, &novo_arco->tokens);
    else
        scanf("%d%d%d", &novo_arco->transicao, &novo_arco->lugar, &novo_arco->tokens);
    novo_arco->prox = NULL;

    if(auxiliar_2 != NULL)
        auxiliar_2->prox = novo_arco;
    else
        *arco = novo_arco;

    return 1;

}
/* ---------------------------------------------------------------------- */
int apagar_arco(arco_t **arco)
{
    arco_t *auxiliar = *arco;

    if(*arco != NULL)
    {
        *arco = auxiliar->prox;
        free(auxiliar);
        return 1;
    }

    return 0;
}
/* ---------------------------------------------------------------------- */
//remove a quantidade especificada de tokens da rede
int remover_tokens(rede_t *rede, int quantidade)
{
    token_t *atual = rede->primeiro_token;

    while(atual != NULL)
    {
        //verifica se o token atual tem tokens suficientes para a remoção
        if(atual->num_tokens >= quantidade)
        {
            //subtrai a quantidade necessaria de tokens do token atual
            atual->num_tokens -= quantidade;
            return 1;
        }
        else
        {
            quantidade -= atual->num_tokens;
            token_t *temp = atual;
            atual = atual->prox;
            free(temp);
            continue;
        }
    }

    return 0;
}
/* ---------------------------------------------------------------------- */
 // remove e atualiza a quantidade especificada de tokens de arcos que correspondem ao lugar e transição
int remover_arcos(rede_t *rede, int lugar, int transicao, int quantidade)
{
    arco_t *atual = rede->primeiro_arco;
    arco_t *anterior = NULL;
    int removidos = 0;

    while(atual != NULL)
    {
    //se o arco atual corresponde ao lugar e transição especificados
        if(atual->lugar == lugar && atual->transicao == transicao)
         {
     // se tem tokens suficientes para remover
             if(atual->tokens >= quantidade)
            {
           //diminui numero de token no arco
                atual->tokens -= quantidade;
                removidos += quantidade;
                break;
            } else
                     {
	     removidos += atual->tokens;
                quantidade -= atual->tokens;
                if(anterior != NULL)
                    anterior->prox = atual->prox; //aponta para o próximo arco
                else
                    rede->primeiro_arco = atual->prox;
                free(atual);
                atual = anterior;
            }
        }
        anterior = atual;
        atual = atual->prox;
    }

    return removidos;
}
/* ---------------------------------------------------------------------- */
//cria e inicializa um novo saco
int criar_saco(saco_t **saco)
{
    if(*saco)
        apagar_saco(saco);
    if( !(*saco = malloc(sizeof(saco_t))) )
        return 0;

    (*saco)->tamanho = 0; //saco esta vazio
    (*saco)->cabeca = NULL; // lista de elementos no saco esta vazia

    return 1;
}
/* ---------------------------------------------------------------------- */
//libera a memória do saco
int apagar_saco(saco_t **saco)
{
    if(!(*saco))
        return 0;

    esvaziar_saco(*saco); //remove e libera a memoria de todos os elementos contidos no saco
    free(*saco);
    *saco = NULL;

    return 1;
}
/* ---------------------------------------------------------------------- */
int inserir_bola(saco_t *saco, int valor)
{
    bola_t *nova_bola = malloc(sizeof(bola_t));

    if(!nova_bola)
        return 0;

    nova_bola->valor = valor;
    nova_bola->proximo = saco->cabeca;
    saco->cabeca = nova_bola;
    saco->tamanho++;

    return 1;
}
/* ---------------------------------------------------------------------- */
int remover_bola_cabeca(saco_t *saco)
{
    bola_t *remover = saco->cabeca;

    if(!saco->tamanho)
        return 0;

    saco->cabeca = saco->cabeca->proximo;
    saco->tamanho--;
    free(remover);

    return 1;
}
/* ---------------------------------------------------------------------- */
int remover_bola_aleatoria(saco_t *saco, int posicao)
{
    int bola_removida, i;

    bola_t *remover = saco->cabeca;
    bola_t *remover_auxiliar = NULL;

    for(i = 0; i < posicao; ++i)
    {
        remover_auxiliar = remover;
        remover = remover->proximo;
    }

    bola_removida = remover->valor;
    if(posicao)
        remover_auxiliar->proximo = remover->proximo;
    else
        saco->cabeca = remover->proximo;
    saco->tamanho--;
    free(remover);

    return bola_removida;
}
/* ---------------------------------------------------------------------- */
int encher_saco(saco_t *saco, int quantidade)
{
    int i;

    if(!(saco))
        return 0;

    if(saco->tamanho)
        esvaziar_saco(saco);

    for(i = 1; i <= quantidade; ++i)
        if(!inserir_bola(saco, i))
            return 0;

    return 1;
}
/* ---------------------------------------------------------------------- */
int esvaziar_saco(saco_t *saco)
{
    if(!saco)
        return 0;

    while(remover_bola_cabeca(saco));

    return 1;
}
/* ---------------------------------------------------------------------- */
void imprimir_saco(saco_t *saco)
{
    bola_t *remover = saco->cabeca;

    printf("Saco: ");
    while(remover)
    {
        printf("%d->", remover->valor);
        remover = remover->proximo;
    }
    printf("NULL\n");
}
/* ---------------------------------------------------------------------- */
int sortear_bola(saco_t *saco)
{
    int numero_aleatorio, bola_sorteada;

    if(!saco)
        return 0;
    if(!saco->tamanho)
        return 0;

    numero_aleatorio = rand()%(saco->tamanho);
    bola_sorteada = remover_bola_aleatoria(saco, numero_aleatorio);

    return bola_sorteada;
}
/* ---------------------------------------------------------------------- */
int conferir_saco(saco_t *saco)
{
    if(!saco)
        return 0;

    return saco->tamanho;
}
/* ---------------------------------------------------------------------- */
double calcular_desvio_padrao(dado_t *dado)
{
    int num_lugares = 0;
    dado_token_t *token = dado->primeiro_token;

    while (token != NULL)
    {
        num_lugares++;
        token = token->prox;
    }

    double soma_valores = 0;
    token = dado->primeiro_token;
    while (token != NULL)
    {
        soma_valores += token->media / dado->num_exp;
        token = token->prox;
    }

    double media = soma_valores / num_lugares;

    double soma_diferenca_quadrado = 0;
    token = dado->primeiro_token;
    while (token != NULL)
    {
        double diferenca = (token->media / dado->num_exp) - media;
        soma_diferenca_quadrado += diferenca * diferenca;
        token = token->prox;
    }

    double desvio_padrao = sqrt(soma_diferenca_quadrado / num_lugares);
    return desvio_padrao;
}
/* ---------------------------------------------------------------------- */
void verificar_alcancabilidade_lugares(rede_t *rede, int *alcancaveis, int lugar)
{
    alcancaveis[lugar] = 1;

    /* verifica arcos produtores para encontrar lugares alcancaveis */
    arco_t *arco = rede->primeiro_arco;
    while(arco != NULL)
    {
        if(arco->lugar == lugar && alcancaveis[arco->transicao] == 0)
            verificar_alcancabilidade_lugares(rede, alcancaveis, arco->transicao);
        arco = arco->prox;
    }
}
/* ---------------------------------------------------------------------- */
// Função para mostrar os lugares inalcançáveis ou com overflow
void mostrar_lugares_inalcancaveis_overflow(rede_t *rede)
{
    int alcancaveis[rede->num_transicoes];
    for(int i = 0; i < rede->num_transicoes; i++)
        alcancaveis[i] = 0;

    // Verificar alcancabilidade a partir de transições habilitadas
    arco_t *arco = rede->primeiro_arco;
    while(arco != NULL)
    {
        if(arco->tokens > MAX_TOKENS_LUGAR)
            printf("Overflow: Lugar %d tem %d tokens (máximo: %d)\n", arco->lugar, arco->tokens, MAX_TOKENS_LUGAR);
        arco = arco->prox;
    }

    // Verificar alcancabilidade dos lugares
    token_t *token = rede->primeiro_token;
    for(int i = 0; i < rede->num_lugares; i++)
    {
        if(token->num_tokens > MAX_TOKENS_LUGAR)
            printf("Overflow: Lugar %d tem %d tokens (máximo: %d)\n", i + 1, token->num_tokens, MAX_TOKENS_LUGAR);
        token = token->prox;
    }

    // Verificar lugares inalcançáveis
    for(int i = 0; i < rede->num_transicoes; i++)
    {
        if(alcancaveis[i] == 0)
            printf("Lugar inalcançável: %d\n", i + 1);
    }
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160806.231815
 * @date 2016-08-06
 *
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex3", "Petri Net Simulator");
    printf("\nUsage: %s [-h|-v]\n", "ex3");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160806.231815
 * @date 2016-08-06
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex3", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 *
 * @author Ruben Carlo Benante
 * @version 20160806.231815
 * @date 2016-08-06
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void ex3_init(void)
{
    IFDEBUG("ex3_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------------- */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160714.153029           */

