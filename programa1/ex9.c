/***************************************************************************
 *   ex9.c                                    Version 20231113.230144      *
 *                                                                         *
 *   Programa que converte temperatura em Fahrenheit para celsius.         *
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
 *   Webpage: http://beco.poli.br/kmbs@poli.br             kmbs            *
 *   Phone: 81988578635                                                    *
 ***************************************************************************/

/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/

/* ---------------------------------------------------------------------- */
/* converte valor de fahrenheit para celsius
 */

int main (void)
{
    /* declarações */
    float cel, far;

    /* codigo e calculo da conversão */
    printf("\nDigite a temperatura em graus Fahrenheit: ");
    scanf("%f", &far);

        cel = ((far - 32) * 5)/9;

    printf("\n A temperatura em Fahrenheit convertida para celsius fica: %2.f ºC\n", cel);

            return 0;
}

