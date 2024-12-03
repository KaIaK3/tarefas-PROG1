/***************************************************************************
 *   ex14.c                                   Version 20240104.133106      *
 *                                                                         *
 *   SIMULAÇÃO MONTE CARLO PARA JOGADA DE DADOS                            *
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
 *   Webpage: http://beco.poli.br/kmbs@poli.br           kmbs              *
 *   Phone: 81988578635                                                    *
 ***************************************************************************/
/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h> /* Time and date functions */

/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */
/* #include "ex14.h" */ /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/* definitions */

#define numSimulacoes 10000

/* ---------------------------------------------------------------------- */

//range dos dados que quero sortear aleatoriamente, neste caso é o lançamento de um dado, que varia de 1 a 6
int lancarDado()
{
    return rand() % 6 + 1;
}

int main() {

    int i;
    int resultadoLancamento;
    int somaResultados = 0;  // Variável para armazenar a soma dos resultados dos lançamentos

    srand(time(NULL));

    // Realizar as simulações
    for (i = 0; i < numSimulacoes; i++) {
        resultadoLancamento = lancarDado();
        somaResultados += resultadoLancamento;
    }

    // Calcular o valor esperado (média)
    double valorEsperado = (double)somaResultados / numSimulacoes;

    // Exibir o resultado
    printf("A tendencia central do dado está entre: %.5lf\n", valorEsperado);

    return 0;
}




/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

