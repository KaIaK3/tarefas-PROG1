/***************************************************************************
 *   soma.c                                   Version 20231108.154148      *
 *                                                                         *
 *   Programa que soma 2 valores e mostra o resultado                      *
 *   Copyright (C) 2023         by Kaic Marcelo De Brito Silva             *
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

/* ---------------------------------------------------------------------- */
/* calcula 2 valores e retorna o resultado da soma*/
int main(void)
{
    // variaveis locais
    int k = 0;
    int j = 0;
    int soma = 0;

    // entradas
    printf("Digite o primeiro numero: \n");
    scanf("%i", &k);

    printf("Digite o segundo numero: \n");
    scanf("%i", &j);

    // calculo e amostra do resultado
    soma = j + k;

    printf("A SOMA E: %i \n", soma);

    return EXIT_SUCCESS;
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

