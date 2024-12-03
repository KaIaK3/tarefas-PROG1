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
/* class document */

class document
{
    public:
        void help(void); /* print some help */
        void copyr(void); /* print version and copyright information */
};


/* ---------------------------------------------------------------------- */
/* methods for class document */

/* ---------------------------------------------------------------------- */
/* Prints help information
 *  usually called by opt -h or --help
 */
void document::help(void)
{
    cout << "retangulo - Classe Retangulo\n";
    cout << "\nUsage: retangulo\n\n";
    cout << "This program does...\n";
    cout << "\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n";
    cout << "\nTodo:\n\tLong options not implemented yet.\n";
    cout << "\nAuthor:\n\tWritten by Ruben Carlo Benante <rcb@beco.cc>\n\n";
    return;
}

/* ---------------------------------------------------------------------- */
/* Prints version and copyright information
 *  usually called by opt -V
 */
void document::copyr(void)
{
    cout << "retangulo - Version " << VERSION << "\n";
    cout << "\nCopyright (C) 2023 Ruben Carlo Benante <rcb@beco.cc>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n";
    return;
}

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
        friend class janela;
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
        cout << "Construindo retangulo com argumentos..." << "\n";
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
/* class janela derivada de retangulo */
class janela : public retangulo
{
    private:
        int lini, cini;
    public:
        void posiciona(int, int);
        void imprime(void);
};

/* ---------------------------------------------------------------------- */
/* methods for class janela  */

/* ---------------------------------------------------------------------- */
/* posiciona janela */

void janela::posiciona(int l, int c)
{
    if(l<2 || l>70)
        lini = 0;
    else
        lini = l;
    if(c<2 || c>20)
        cini = 0;
    else
        cini = c;
}

/* ---------------------------------------------------------------------- */
/* imprime janela retangulo */
void janela::imprime()
{
    int l, c;
    int i;

    for(i=0; i<lini; i++)
        cout << "\n";
    for(i=0; i<cini; i++)
        cout << " ";
    cout << "┌";
    for(c = 0; c < base; c++)
        cout << "─";
    cout << "┐";
    for(l = 1; l < altura; l++)
    {
        cout << "\n";
        for(i=0; i<cini; i++)
            cout << " ";
        cout << "│";
        for(c = 0; c < base; c++)
            cout << " ";
        cout << "│";
    }
    cout << "\n";
    for(i=0; i<cini; i++)
        cout << " ";
    cout << "└";

    for(c = 0; c < base; c++)
        cout << "─";
    cout << "┘";
    cout << "\n\n";
}

/* ---------------------------------------------------------------------- */
/* Main Func
 */
int main(void)
{
    document doc; /* doc eh objeto da classe document */
    retangulo a; /* a eh objeto da classe retangulo */
    retangulo b(1,2); /* b inicia com tamanho 2,2 */
    janela j;

    doc.copyr();

    a.inicia(5,3);
    a.imprime();
    b.imprime();

    j.inicia(3,3);
    j.posiciona(3,5);
    j.imprime();

    return 0;
}

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : CPP config - Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20220718.172615      */


