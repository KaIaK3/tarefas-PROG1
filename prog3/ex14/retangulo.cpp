/***************************************************************************
 *   retangulo.cpp                            Version 20231213.130258      *
 *                                                                         *
 *   Classe Retangulo                                                      *
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
 *   $ make retangulo.out
 */

/* ---------------------------------------------------------------------- */
/* includes */
#include <iostream> /* (Input/output library) Several standard stream objects */
using namespace std;

/* ---------------------------------------------------------------------- */
/* defines */
#ifndef VERSION
#define VERSION 20231213.140725
#endif

/* ---------------------------------------------------------------------- */
/* class retangulo */
class retangulo
{
    private:
        int base, altura;
    public:
        void inicia(int, int);
        void imprime(void);
        retangulo(int, int);
        retangulo(void);
        ~retangulo(void);
};

/* ---------------------------------------------------------------------- */
/* methods for class retangulo */

/* ---------------------------------------------------------------------- */
/* inicia retangulo, protege overflow */
void retangulo::inicia(int b, int a)
{
    if(b < 2 || b > 70)
        base = 5;
    else
        base = b;
    if(a < 2 || a > 20)
        altura = 5;
    else
        altura = a;
}

/* ---------------------------------------------------------------------- */
/* imprime retangulo */
void retangulo::imprime(void)
{
    int l, c;

    cout << "┌";
    for(c = 0; c < base; c++)
        cout << "─";
    cout << "┐";
    for(l = 1; l < altura; l++)
    {
        cout << "\n│";
        for(c = 0; c < base; c++)
            cout << " ";
        cout << "│";
    }
    cout << "\n└";

    for(c = 0; c < base; c++)
        cout << "─";
    cout << "┘";
    cout << "\n\n";
}

/* ---------------------------------------------------------------------- */
/* construtor com argumentos do retangulo */
retangulo::retangulo(int b, int a)
{
        cout << "Construindo retangulo com 2 argumentos..." << "\n";
		base=((b<2||b>70)?5:b);
		altura=((a<2||a>70)?5:a);
}

/* ---------------------------------------------------------------------- */
/* construtor sem argumentos do retangulo */
retangulo::retangulo(void)
{
    cout << "Construindo retangulo sem argumentos..." << "\n";
}

/* ---------------------------------------------------------------------- */
/* destrutor do retangulo */
retangulo::~retangulo(void)
{
    cout << "Destruindo retangulo..." << "\n";
}

/* ---------------------------------------------------------------------- */
/* Main Func
 */
int main(void)
{
    retangulo a; /* a eh objeto da classe retangulo */
    retangulo b(1,2); /* b inicia com tamanho 2,2 */

    a.inicia(5,3);
    a.imprime();
    b.imprime();

    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : CPP config - Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20220718.172615      */


