 /**************************************************************************
 *   pe5.c                                    Version 20190817.235856      *
 *                                                                         *
 *   Project Euler                                                         *
 *   Copyright (C) 2015-2019   Template by Ruben Carlo Benante             *
 *   Author: Kaic Marcelo De Brito Silva                                   *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
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
 **************************************************************************/

/* ---------------------------------------------------------------------- */
/* includes */
#include "projecteuler.h"
#include "myeulerlib.h"

/* ---------------------------------------------------------------------- */
/* defines */
/* Project Euler Exercise Number */
/* #define PEN pe ## 5 */
#define SPEN "pe" "5"
/* ---------------------------------------------------------------------- */
/* prototypes */
void pe5(void); /* Proj. Euler problem #5 */

/* ---------------------------------------------------------------------- */
/* main function */
/* Do not change the main function. Use the void pe5(void) and
 * others you create here or in the myeulerlib.c and myeulerlib.h files
 */
int main(void)
{
    printf("Project Euler 20190817.233439, %s\n", SPEN);
    help(); /* optional help message at start */
    GRABsignals(); /* grab interruption signals */
    pe5(); /* Proj. Euler problem #5 */
    LEGOsignals(); /* restore interruption signals */
    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* Proj. Euler problem #5 */
/* Problem description: qual o menor numero positivo que é igualmente divisivel por todos os numeros de 1 a 20
 *
 */

void pe5(void)
{
    unsigned long j;
    bool sobrouresto = false;
    ulong r = 1; /* answer */

    while(1)
    {
        sobrouresto = false;

        for (j = 2; j <= 20 && !sobrouresto; j++)
        {
            sobrouresto = (r % j) != 0;

            if (sobrouresto)
                break;
        }
        if(!sobrouresto)
        {
            printf("%s: %lu\n", __FUNCTION__, r); /* answer */
            break;
        }
            r++;
    }
return ;
}
/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160612.142044      */

