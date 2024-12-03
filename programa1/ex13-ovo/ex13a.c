/***************************************************************************
 *   ex13a.c                                  Version 20240103.204017      *
 *                                                                         *
 *   JOGO DO OVO                                                           *
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
 *   Webpage: http://beco.poli.br/kmbs@poli.br             kmbs            *
 *   Phone: 81988578635                                                    *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <stdbool.h>
#include <time.h>  /* Time and date functions */

/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex13a.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#define TABULEIRO_TAM 15

/* ---------------------------------------------------------------------- */


char tabuleiro[TABULEIRO_TAM];

void inicializarTabuleiro()
{
    for(int i = 0; i < TABULEIRO_TAM; i++)
        tabuleiro[i] = '-';
}

bool jogadaValida(int posicao)
{
    if(posicao < 0 || posicao >= TABULEIRO_TAM)
    {
        printf("Posição inválida. Escolha outra posição.\n");
        return false;
    }
    if(tabuleiro[posicao] != '-')
    {
        printf("Posição já ocupada. Escolha outra posição.\n");
        return false;
    }
    return true;
}

bool verificaVitoria(char jogador)
{
    for(int i = 0; i <= TABULEIRO_TAM - 3; i++)
    {
        if(tabuleiro[i] == 'O' && tabuleiro[i + 1] == 'V' && tabuleiro[i + 2] == 'O')
                  return true;
    }
    return false;
}

void imprimirTabuleiro()
{
    for(int i = 0; i < TABULEIRO_TAM; i++)
        printf("%c ", tabuleiro[i]);
    printf("\n");
}

void humano(char jogador)
{
    int posicao;
    char jogada;

    printf("Jogador %c, escolha uma posição (0 a 14) e a jogada (O ou V): ", jogador);
    scanf("%d %c", &posicao, &jogada);

    while(!jogadaValida(posicao) || (jogada != 'O' && jogada != 'V'))
    {
        printf("Jogada inválida. Escolha novamente.\n");
        printf("Jogador %c, escolha uma posição (0 a 14) e a jogada (O ou V): ", jogador);
        scanf("%d %c", &posicao, &jogada);
    }

    tabuleiro[posicao] = jogada;
}

int main()
{

    inicializarTabuleiro();
    srand(time(NULL));

    char vencedor = '\0'; // Variável para armazenar o vencedor

    while(!verificaVitoria('A') && !verificaVitoria('B'))
    {
        imprimirTabuleiro();
        humano('A');
        if(verificaVitoria('A'))
        {
            vencedor = 'A';
            break;
        }

        imprimirTabuleiro();
        humano('B');
        if(verificaVitoria('B'))
        {
            vencedor = 'B';
            break;
        }

        int posicaoVazia = 0;
        for(int i = 0; i < TABULEIRO_TAM; i++)
        {
            if(tabuleiro[i] == '-')
            {
                posicaoVazia = 1;
                break;
            }
        }

        if(!posicaoVazia)
        {
            // Todas as posições estão preenchidas, termina o jogo como empate
            break;
        }
    }

    printf("Fim de jogo!\n");
    if(vencedor != '\0')
        printf("Jogador %c venceu!\n", vencedor);
    else
        printf("Empate!\n");

    return 0;
}

/* ---------------------------------------------------------------------- */

/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

