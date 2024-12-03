/***************************************************************************
 *   delta.c                                  Version 20231213.155339      *
 *                                                                         *
 *   exercicio do delta                                                    *
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
#include <math.h>  /* Mathematics functions */
#include <time.h>
/* ---------------------------------------------------------------------- */

int main(void)

{
    int dig = 1;
    int iteracoes = 100;
    double aprox;
    double real;
    char str[320];

    srand(time(NULL));


    for (int i = 0; i < iteracoes; i++)
    {
        real = ((double)rand() / RAND_MAX) * 100.0;  // Varie conforme necessário

        sprintf(str, "%4.*f", dig, real);
        aprox = atof(str);

        printf("Iteração %d:\n", i + 1);
        printf("Real: %f\n", real);
        printf("Aproximado: %f\n", aprox);

        // Compara os valores e imprime o resultado
        if (real < aprox)
            printf("Real menor\n");
        else if (real > aprox)
            printf("Real maior\n");
        else
            printf("Iguais\n");

        printf("\n");
    }

    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

