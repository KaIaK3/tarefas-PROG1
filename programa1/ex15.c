/***************************************************************************
 *   aleatorio.c                              Version 20231130.140733      *
 *                                                                         *
 *   Gerar numero aleatorio                                                *
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
 *   Webpage: http://beco.poli.br/kmbs@poli.br               kmbs          *
 *   Phone: 81988578635                                                    *
 ***************************************************************************/
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <time.h>

/* ---------------------------------------------------------------------- */

/* prototypes */
unsigned int meusrand(unsigned int);
unsigned int meurand(void);

/* ---------------------------------------------------------------------- */

int main(void)
{
    meusrand(time(NULL));

    unsigned int r;
    int i, d;
    int histograma[6] = {0};
    int frequenciaEsperada = 100000 / 6;

    for (i = 0; i < 100000; i++)
        {
            r = meurand();
            d = r%6+1;
            histograma[d - 1]++;
        }

// Imprime o histograma
    printf("Histograma:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d: %d\n", i + 1, histograma[i]);
    }

    // Verifica equiprobabilidade
    printf("\nVerificação de Equiprobabilidade:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d: %s\n", i + 1, (histograma[i] == frequenciaEsperada) ? "OK" : "Not OK");
    }

    return EXIT_SUCCESS;

}

unsigned int meurand(void)
{
    unsigned int s = 0;
    int a = 16807;
    int b = 0;
    int c = 293461841;

    s = meusrand(-1);

    s = (((s * a) + b)) % c;

    return meusrand(s);
}

unsigned int meusrand(unsigned int t)
{
    static unsigned int s = 0;

    if (t != -1)

        s=t;

    return s;
}


/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

