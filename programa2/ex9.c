/***************************************************************************
 *   ex9.c                                    Version 20240523.155727      *
 *                                                                         *
 *   Atividade do bingo                                                    *
 *   Copyright (C) 2024         by Kaic Marcelo De Brito Silva             *
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
 *   Kaic Marcelo De Brito Silva                                           *
 *   Email: kmbs@poli.br                                                   *
 *   Webpage: http://beco.poli.br/kmbs                                     *
 *   Phone: 81988578635                                                    *
 ***************************************************************************/

/*
 * Instrucoes para compilar:
 * $gcc ex9.c -o ex9.x -Wall -Wextra -g -O0 -DDEBUG=1
 * opcoes extras: -ansi -pedantic-errors
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include "libpext.c" /* Standard I/O functions */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex9.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142306" */
#define VERSION "20240523.155727" /* Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /* Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */

/* Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /* string buffer */


/* ---------------------------------------------------------------------- */
/* Funcao responsavel pela chamada das funcoes do jogo do bingo.
 */
int main(void)
{
    srand(time(NULL));
    /* local declarations */
    int i; /* general index */
    // char s[SBUFF]; /* a string to hold ...
    int card[SIZE][SIZE];
    int restart = 0; /* variável que serve como condição para laço principal continuar rodando */
    char saideira; /* variável que determinará se o usuário quer recomeçar ou não */
    int pergunta = 0; /* variável que garante o laço referente à pergunta se o jogador quer recomeçar ou não*/
    int turnos = 0; /* variavel que conta quantos turnos para o jogo acabar */

    /* code */
    while(restart == 0) /* laço principal do bingo */
    {
        generate_card(card);
        print_card(card);
        Bola *saco = criar_saco_bingo();

        for (i = 0; i < 99; i++)
        {
            sleep(1);
            Bola *bola_sorteada = sortear_bola(&saco);
            printf("\t~Bola Sorteada: %d\n", bola_sorteada->numero);
            mark_number(card, bola_sorteada->numero);
            sleep(1);
            print_card(card);
            turnos++;

            while(1)
            {
                if (prosseguir())
                {
                    break;
                }
                else
                {
                    restart = 1;
                    break;
                }
            }
            if (restart == 1)
            {
                break;
            }

            if (checa_vitoria(card))
            {
                    printf("\t~PARABENS VOCE GANHOU!\n");
                    printf("\t~Demorou %d turnos para voce ganhar\n", turnos);
                    free(bola_sorteada);
                    break;
            }
            free(bola_sorteada);
        }
        while(pergunta == 0 && restart == 0)
        {
            printf("\t~VOCÊ QUER JOGAR DE NOVO?(s/n)\n\t");
            scanf("%c", &saideira);
            switch(saideira) /* laço que analisa a resposta do usário */
            {
                case 's':
                    pergunta++;
                    break;
                case 'S':
                    pergunta++;
                    break;
                case 'N':
                    printf("\t            ._______________.\n");
                    printf("\t            |!ATÉ A PRÓXIMA!|\n");
                    printf("\t            °¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨°\n\n");
                    restart++;
                    pergunta++;
                    break;
                case 'n':
                    printf("\t            ._______________.\n");
                    printf("\t            |!ATÉ A PRÓXIMA!|\n");
                    printf("\t            °¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨°\n\n");
                    restart++;
                    pergunta++;
                    break;
                default:
                    printf("\t~Desculpe, não entendi a resposta.  \n    (Por favor, responda com (s) para sim ou (n) para não.)\n");
                    break;
            }
        }
        pergunta--;
    }
    /* ...and we are done */
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

