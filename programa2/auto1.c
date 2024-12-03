/***************************************************************************
 *   auto1.c                                 Version 20210512.104607         *
 *                                                                         *
 *   Converte AFND para AFD                                                *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.               *
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

/* ---------------------------------------------------------------------- */
/**
 * @file auto1.c
 * @ingroup GroupUnique
 * @brief Converte AFND para AFD
 * @details This program really do a nice job as a template, and template only!
 * @version 20160618.013215
 * @date 2016-06-18
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc auto1.c -o ex12.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astyle -A1 -s4 -k3 -xj -SCNeUpv auto1.c
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto1.h */

#include "auto1.h" /* To be created for this template if needed */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./auto1 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-18
 *
 */
int main(int argc, char *argv[])
{
    int opt, cont; /* return from getopt() */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;

    cont = 0;
    while((opt = getopt(argc, argv, "vhcnfe:")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'c':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'f':
                if(!cont)
                    auto1_init(argv[2]);
                else
                    auto1_init("saida_AFND.txt");
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    auto1_init_entrada_padrao();

    return EXIT_SUCCESS;
}

/* Write your functions here... */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "auto1", "Converte AFND para AFD");
    printf("\nUsage: %s [-h|-v]\n", "auto1");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-n): input data is a NFA (Nondeterministic Finite Automata) 5-tuple to be converted to a DFA (Deterministic Finite Automata) 5-tuple.\n");
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto1", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void auto1_init(const char *entrada)
{
    IFDEBUG("auto1_init()");

    quintupla_t Qafnd, Qafd;
    lconj_t *simultaneo = NULL;

    entrada_Automato(&Qafnd, entrada);
    estados_simultaneos(Qafnd, &simultaneo);

    estados_novos(Qafnd, &Qafd, simultaneo);

    salva_quintupla(Qafd, NULL);
    salva_quintupla(Qafd, "saida_AFD.txt");
    return;
}

void auto1_init_entrada_padrao(void)
{
    quintupla_t Qafnd, Qafd;
    lconj_t *simultaneo = NULL;

    auto1_entrada_padrao(&Qafnd);
    estados_simultaneos(Qafnd, &simultaneo);

    estados_novos(Qafnd, &Qafd, simultaneo);

    salva_quintupla(Qafd, NULL);
    salva_quintupla(Qafd, "saida_AFD.txt");
    return;

}

void estados_simultaneos(quintupla_t Q, lconj_t **simultaneo)
{
    lconj_t *plconj;
    ltrans_t *plsimul;
    lest_t *plest;
    int i;

    for(i = 0; i < Q.K; i++)
    {
        insere_conjunto(simultaneo, i);
        plconj = busca_conjunto(*simultaneo, i);
        insere_estado(&plconj->estados, i);
        plest = plconj->estados;
        while(plest != NULL)
        {
            plsimul = Q.D;
            while((plsimul = busca_simultaneo(plsimul, plest->estado)) != NULL)
            {
                insere_estado(&plconj ->estados, plsimul ->ef);
                plsimul = plsimul->prox;
            }
            plest = plest->prox;
        }
    }
    return;
}

ltrans_t *busca_simultaneo(ltrans_t *list, int ref)
{
    return busca_transicao(list, ref, "E");
}

void estados_novos(quintupla_t Qantigo, quintupla_t *Qnovo, lconj_t *simultaneo)
{
    int estado;
    char lei, slei[2];
    lconj_t *conj_estados = NULL, *plconj;
    lest_t *plest, *list = NULL;
    ltrans_t *pltrans;

    Qnovo->A = Qantigo.A;
    Qnovo->D = NULL;
    Qnovo->F = NULL;

    insere_conjunto(&conj_estados, 0);

    plconj = busca_conjunto(conj_estados, 0);
    primeiro_estado(&plconj->estados, simultaneo, Qantigo.S);
    Qnovo->S = 0;
    Qnovo->K = 1;

    while(plconj != NULL)
    {
        for(lei = 'a'; lei <= Qantigo.A; ++lei)
        {
            pltrans = Qantigo.D;
            slei[0] = lei;
            slei[1] = '\0';

            plest = plconj ->estados;
            list = NULL;
            while(plest != NULL)
            {
                while((pltrans = busca_transicao(pltrans, plest->estado, slei)) != NULL)
                {
                    insere_estado(&list, pltrans->ef);
                    pltrans = pltrans->prox;
                }
                plest = plest->prox;
            }
            if(list != NULL)
            {
                modelando_conjunto(simultaneo, &list);
                estado = novo_estado(list, &conj_estados);
                Qnovo->K = estado + 1 > Qnovo->K ? estado + 1 : Qnovo ->K;
                insere_transicao(&Qnovo->D, plconj->id, slei, estado);
            }
            apaga_estados(&list);
        }
        plconj = plconj->prox;
    }
    definir_final(conj_estados, Qantigo.F, &Qnovo -> F);
    apaga_conjunto(&conj_estados);
    return;
}

int novo_estado(lest_t *list, lconj_t **conj_estados)
{
    int id;
    lconj_t *plconj = *conj_estados;

    for(id = 0; plconj != NULL; id++)
    {
        if(igualdade_conjunto(plconj->estados, list))
            return id;
        plconj = plconj->prox;
    }
    insere_conjuntoFULL(conj_estados, list, id);
    return id;
}

void primeiro_estado(lest_t **estados, lconj_t *simultaneo, int s)
{
    copia_estado(estados, simultaneo, s);
    return;

}

void copia_estado(lest_t **estados, lconj_t *simultaneo, int s)
{
    lconj_t *plconj = busca_conjunto(simultaneo, s);
    lest_t *plest = plconj->estados;
    while(plest != NULL)
    {
        insere_estado(estados, plest->estado);
        plest = plest->prox;
    }

    return;
}

void modelando_conjunto(lconj_t *simultaneo, lest_t **list)
{
    lest_t *plest = *list;

    *list = NULL;

    while(plest != NULL)
    {
        copia_estado(list, simultaneo, plest ->estado);
        plest = plest->prox;
    }
    return;
}
void definir_final(lconj_t *conjunto, lest_t *final, lest_t **list)
{
    lconj_t *plconj = conjunto;
    lest_t *plest, *plfinal = final;

    while(plconj != NULL)
    {
        plest = plconj->estados;
        while(plest != NULL)
        {
            plfinal = final;
            while(plfinal != NULL)
            {
                if(plest->estado == plfinal->estado)
                    insere_estado(list, plconj->id);
                plfinal = plfinal->prox;
            }
            plest = plest->prox;
        }
        plconj = plconj-> prox;
    }
    return;
}
/* ---------------------------------------------- */
/* saida texto */
void salva_quintupla(quintupla_t Q, char *arquivo)
{
    FILE *pf;

    if(!arquivo)
        pf = stdout;
    else
        pf = fopen(arquivo, "w");

    fprintf(pf, "#K\n");
    fprintf(pf, "%d\n", Q.K);
    fprintf(pf, "#A\n");
    fprintf(pf, "%c\n", Q.A);
    fprintf(pf, "#S\n");
    fprintf(pf, "%d\n", Q.S);
    fprintf(pf, "#F\n");
    /* funcao loop imprime estado final */
    imprime_estados(Q.F, pf);
    fprintf(pf, "#D\n");
    /* funcao loop imprime transicao */
    imprime_transicao(Q.D, pf);

    if(arquivo)
        fclose(pf);

    return;
}

int igualdade_conjunto(lest_t *list, lest_t *list2)
{
    lest_t *pl = list, *pl2 = list2;
    while(1)
    {
        if(!pl)
        {
            if(!pl2)
                break;
            else
                return 0;
        }
        else
        {
            if(!pl2)
                return 0;
        }
        if(pl->estado != pl2->estado)
            return 0;
        pl = pl->prox;
        pl2 = pl2->prox;
    }
    return 1;
}

ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef)
{
    ltrans_t *pl = list;
    while(pl != NULL)
    {
        if(pl->ei == ei && pl->ef == ef)
            return pl;
        pl = pl->prox;
    }
    return NULL;
}
/* ---------------------------------------------------------------------- */
/*entrada*/
void entrada_Automato(quintupla_t *Q, const char *entrada)
{
    FILE *pf = fopen(entrada, "r");
    char ch[SBUFF];
    fgets(ch, SBUFF, pf); /* #K */
    fgets(ch, SBUFF, pf); /* #K */
    Q->K = atoi(ch);

    fgets(ch, SBUFF, pf); /* #A */
    fgets(ch, SBUFF, pf); /* #A */
    Q->A = *ch;

    fgets(ch, SBUFF, pf); /* #S */
    fgets(ch, SBUFF, pf); /* #S */
    Q->S = atoi(ch);

    fgets(ch, SBUFF, pf); /* #F */
    Q->F = NULL;
    coleta_final(&Q->F, pf);

    fgets(ch, SBUFF, pf); /* #D */
    Q->D = NULL;
    coleta_transicao(&Q->D, pf);

    fclose(pf);
    return;
}

void auto1_entrada_padrao(quintupla_t *Q)
{
    char ch[SBUFF];

    /* Ler #K */
    fgets(ch, SBUFF, stdin); /* Ignorar o rotulo #K */
    fgets(ch, SBUFF, stdin); /* Ler o valor de #K */
    Q->K = atoi(ch);

    /* Ler #A */
    fgets(ch, SBUFF, stdin); /* Ignorar o rotulo #A */
    fgets(ch, SBUFF, stdin); /* Ler o valor de #A */
    Q->A = *ch;

    /* Ler #S */
    fgets(ch, SBUFF, stdin); /* Ignorar o rotulo #S */
    fgets(ch, SBUFF, stdin); /* Ler o valor de #S */
    Q->S = atoi(ch);

    /* Ler #F */
    fgets(ch, SBUFF, stdin); /* Ignorar o rotulo #F */
    Q->F = NULL;
    coleta_final(&Q->F, stdin); /* Ler o conjunto de estados finais */

    /* Ler #D */
    fgets(ch, SBUFF, stdin); /* Ignorar o rótulo #D */
    Q->D = NULL;
    coleta_transicao(&Q->D, stdin); /* Ler o conjunto de transições */

    return;
}


void coleta_final(lest_t **list, FILE *stream)
{
    char ch[SBUFF], *sch;

    fgets(ch, SBUFF, stream);
    sch = strtok(ch, " ");

    do
    {
        insere_estado(list, atoi(sch));
    }
    while((sch = strtok(NULL, " ")) != NULL);
    return;
}

void coleta_transicao(ltrans_t **list, FILE *stream)
{
    char ch[SBUFF], *sei, *slei, *sef;

    while(fgets(ch, SBUFF, stream) != NULL)
    {
        if(strcmp(ch, "\n") == 0)
            return;
        sei = strtok(ch, " ");
        slei = strtok(NULL, " ");
        sef = strtok(NULL, " ");

        insere_transicao(list, atoi(sei), slei, atoi(sef));
    }
    return;
}
/*------------------------------------------------------------------------*/
/*Busca*/
ltrans_t *busca_por_ei(ltrans_t *list, int est)
{
    ltrans_t *pl = list;

    while(pl != NULL)
    {
        if(pl->ei == est)
            return pl;
        pl = pl->prox;
    }
    return NULL;
}

ltrans_t *busca_por_ef(ltrans_t *list, int est)
{
    ltrans_t *pl = list;

    while(pl != NULL)
    {
        if(pl->ef == est)
            return pl;
        pl = pl->prox;
    }
    return NULL;
}

ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei)
{
    ltrans_t *pl = list;

    while(pl != NULL)
    {
        if(pl->ei == ei && strcmp(pl->lei, lei) == 0)
            return pl;
        pl = pl->prox;
    }
    return NULL;
}

void imprime_transicao(ltrans_t *list, FILE *stream)
{
    ltrans_t *pl = list;

    while(pl != NULL)
    {
        fprintf(stream, "%d %s %d\n", pl->ei, pl->lei, pl->ef);
        pl = pl->prox;
    }
    return;
}

/* ---------------------------------------------------------------------- */
/*Impressão*/
void insere_estado(lest_t **list, int est)
{
    lest_t *pl = *list, *plant = NULL;
    while(pl != NULL)
    {
        if(pl->estado > est)
            break;
        else
            if(pl->estado == est)
                return;
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(lest_t));
    pl->estado = est;
    pl->prox = NULL;
    if(!plant)
    {
        pl->prox = *list;
        *list = pl;
    }
    else
    {
        pl->prox = plant->prox;
        plant->prox = pl;

    }
    return;
}

void insere_transicao(ltrans_t **list, int ei, char *lei, int ef)
{
    ltrans_t *pl = *list, *plant = NULL;
    while(pl != NULL)
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(ltrans_t));
    pl->ei = ei;
    pl->lei = (char *)malloc(strlen(lei) * sizeof(char));
    strcpy(pl->lei, lei);
    pl->ef = ef;
    pl->prox = NULL;

    if(!plant)
        *list = pl;
    else
        plant->prox = pl;

    return;
}

void imprime_estados(lest_t *list, FILE *stream)
{
    lest_t *pl = list;

    if(pl != NULL)
    {
        fprintf(stream, "%d", pl->estado);
        pl = pl->prox;
    }

    while(pl != NULL)
    {
        fprintf(stream, " %d", pl->estado);
        pl = pl->prox;
    }
    fprintf(stream, "\n");
    return;
}

void imprime_arvore(t_arvore *raiz, FILE *stream)
{
    t_arvore *pl = raiz;

    if(!pl)
        return;

    imprime_arvore(pl->esq, stream);
    imprime_arvore(pl->dir, stream);

    printf("\n");
    if(pl->tipo_op == 2)
        fprintf(stream, "(%s)%s(%s)\n", pl->esq->expReg, pl->expReg, pl->dir->expReg);
    else
        if(pl->tipo_op == 1)
            fprintf(stream, "(%s)%s\n", pl->esq->expReg, pl->expReg);
        else
            fprintf(stream, "%s\n", pl->expReg);

    salva_quintupla(pl->Q, NULL);
    getchar();
    printf("\n");

    return;
}

lconj_t *busca_conjunto(lconj_t *list, int id)
{
    lconj_t *pl = list;
    while(pl != NULL)
    {
        if(pl -> id == id)
            return pl;
        pl = pl->prox;
    }
    return NULL;
}
void insere_conjunto(lconj_t **list, int id)
{
    lconj_t *pl = *list, *plant = NULL;
    while(pl != NULL)
    {
        plant = pl;
        pl = pl ->prox;
    }
    pl = malloc(sizeof(lconj_t));
    pl ->id = id;
    pl ->estados = NULL;
    pl -> prox = NULL;

    if(!plant)
        *list = pl;
    else
        plant -> prox = pl;
    return;
}
void insere_conjuntoFULL(lconj_t **conjunto, lest_t *list, int id)
{
    lconj_t *pltrans;
    insere_conjunto(conjunto, id);
    pltrans = busca_conjunto(*conjunto, id);

    while(list != NULL)
    {
        insere_estado(&pltrans -> estados, list ->estado);
        list = list ->prox;
    }
    return;
}

void imprime_conjunto(lconj_t *list, FILE *stream)
{
    lconj_t *pl = list;

    while(pl != NULL)
    {
        fprintf(stream, "%d: ", pl -> id);
        imprime_estados(pl->estados, stream);
        pl = pl->prox;
    }
    fprintf(stream, "\n");
    return;
}

/* Limpeza */

void remove_estado(lest_t **list, lest_t *r)
{
    lest_t *pl = *list, *plant = NULL;

    while(pl != NULL)
    {
        if(pl == r)
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl)
        return;

    if(!plant)
        *list = pl->prox;
    else
        plant->prox = pl->prox;

    free(pl);
    return;
}

void remove_transicao(ltrans_t **list, ltrans_t *r)
{
    ltrans_t *pl = *list, *plant = NULL;

    while(pl != NULL)
    {
        if(pl == r)
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl)
        return;

    if(!plant)
        *list = pl->prox;
    else
        plant->prox = pl->prox;

    free(pl);
    return;
}

/* ---------------------------------------------------------------------- */
void apaga_estados(lest_t **list)
{
    lest_t *pl = *list;

    while(pl != NULL)
    {
        remove_estado(list, pl);
        pl = *list;
    }
    return;
}

/* ---------------------------------------------------------------------- */
void apaga_transicao(ltrans_t **list)
{
    ltrans_t *pl = *list;

    while(pl != NULL)
    {
        remove_transicao(list, pl);
        pl = *list;
    }
}
/* ---------------------------------------------------------------------- */
void remove_conjunto(lconj_t **list, lconj_t *r)
{
    lconj_t *pl = *list, *plant = NULL;

    while(pl != NULL)
    {
        if(pl == r)
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl)
        return;

    if(!plant)
        *list = pl->prox;
    else
        plant->prox = pl->prox;

    free(pl);

    return;
}

void apaga_conjunto(lconj_t **list)
{
    lconj_t *pl = *list;

    while(pl != NULL)
    {
        apaga_estados(&pl->estados);
        remove_conjunto(list, pl);
        pl = *list;
    }
    return;
}
/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */
/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

