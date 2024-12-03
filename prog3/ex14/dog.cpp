/***************************************************************************
 *   dog.cpp                                  Version 20231214.091416      *
 *                                                                         *
 *   draw a dog                                                            *
 *   Copyright (C) 2023         by Ruben Carlo Benante                     *
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

/*
 * Instrucoes para compilar:
 *   $ make dog.out
 */

/* ---------------------------------------------------------------------- */
/* includes */
#include <iostream> /* (Input/output library) Several standard stream objects */
using namespace std;

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* g++ -DVERSION="0.1.160612.142306" */
#define VERSION "20231214.091416" /* Version Number (string) */
#endif

/* ---------------------------------------------------------------------- */
/* class dog */

class dog
{
    public:
        void orelhas(void);
        void olhos(void);
        void nariz(void);
        void patas(void);
};

/* ---------------------------------------------------------------------- */
/* methods for dogs */
/*
   /\___/\
    (0_0)
     (Y)
--oOo-U-oOo---
*/

/* ---------------------------------------------------------------------- */
/* print ears */
void dog::orelhas(void)
{
    cout << "\n   /\\___/\\\n";
}

/* ---------------------------------------------------------------------- */
/* print eyes */
void dog::olhos(void)
{
    cout << "    (0_0)\n";
}

/* ---------------------------------------------------------------------- */
/* print nose */
void dog::nariz(void)
{
    cout << "     (Y)\n";
}

/* ---------------------------------------------------------------------- */
/* print paws */
void dog::patas(void)
{
    cout << "--oOo-U-oOo---\n\n";
}

/* ---------------------------------------------------------------------- */
/* class cat */

class cat
{
    public:
        void orelhas(void);
        void olhos(void);
        void nariz(void);
        void patas(void);

};

/* ---------------------------------------------------------------------- */
/* methods for cats */
/*
     |\_/|
    /(0_0)\
   |==(Y)==|
 --(u)---(u)--
*/

/* ---------------------------------------------------------------------- */
/* orelhinha do gato */

void cat::orelhas(void)
{
    cout << "\n\n\n     |\\_/|\n";
}

/* ---------------------------------------------------------------------- */
/* print eyes */
void cat::olhos(void)
{
    cout << "    /(0_0)\\ \n";
}

/* ---------------------------------------------------------------------- */
/* print nose */
void cat::nariz(void)
{
    cout << "   |==(Y)==| \n";
}

/* ---------------------------------------------------------------------- */
/* print paws */
void cat::patas(void)
{
    cout << " --(u)---(u)--\n\n";
}

/* ---------------------------------------------------------------------- */
/* Main func
 *
 * It receives as input ...
 *
 * It returns ...
 */
int main(void)
{
    dog d;
    cat c;

    d.orelhas();
    d.olhos();
    d.nariz();
    d.patas();

    c.orelhas();
    c.olhos();
    c.nariz();
    c.patas();

    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : CPP config - Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20220718.172615      */


