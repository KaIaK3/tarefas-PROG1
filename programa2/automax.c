/***************************************************************************
 *   automax.c                                 Version 20210512.104607         *
 *                                                                         *
 *   Converte AFD, AFND e ER                                               *
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
 * @file automax.c
 * @ingroup GroupUnique
 * @brief Converte AFD, AFND e ER
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
 *   $gcc automax.c -o automax.x -Wall
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
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv automax.c
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in automax.h */

 #include "automax.h"  /* To be created for this template if needed */

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
 *    $./automax -h
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

    IFDEBUG("Starting optarg loop...\n");

    /* getopt() configured options:
     *        -h  help
     *        -c  copyrithg and version notes
     *        -v  verbose
     *        -f  transformacao AFD -> ER
     *        -n  transformacao AFND -> AFD
     *        -e  transformacao ER -> AFND
     */
    opterr = 0;

    cont= 0;
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
            case '?':
                break;
            case 'f':
                if(!cont)
                    AFD_ER_init(argv[2]);
                else
                    AFD_ER_init("saida_AFD.txt");
                break;
            case 'n':
                if(!cont)
                    AFND_AFD_init(argv[2]);
                else
                    AFND_AFD_init("saida_AFND.txt");
                break;
            case 'e':
                if(!cont)
                    ER_AFND_init(argv[2]);
                else
                    ER_AFND_init("saida_ER.txt");
                break;
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    if(verb)

        printf("Verbose level set at: %d\n", verb);
    /* ...and we are done */

    return EXIT_SUCCESS;
}

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


void ER_AFND_init(char *entrada)
{
    char expReg[SBUFF];
    t_arvore *raiz= NULL;

    IFDEBUG("automax_init()");
    /* initialization */

    entrada_ER(expReg, entrada);
    quebraExpressao(expReg, &raiz);

    transformacao(raiz);

    printf("\n\nExpressao Regular: %s\nQuintupla: \n\n", expReg);
    salva_quintupla(raiz->Q, NULL);
    salva_quintupla(raiz->Q, "saida_AFND.txt");

  return;
}

/* identifica o tipo da informacao: nao operador, operador unario ou operador binario */

int tipo_operador(char info)
{
    if(info == '.' || info == '|')
        return 2;
    if(info == '*')
        return 1;
    return 0;
}

/* responsavel em quebra a expressao regular em expressoes minimas, e armazenando numa arvore binaria */

void quebraExpressao(char *expReg, t_arvore **raiz)
{
    const int nOp= 3; /*numero de operadores*/
    char operadores[3] = { '|', '.', '*'} /*operadores em ordem crescente de prioridade*/,
         *op = malloc(2*sizeof(char)) /*operador*/,
         *partEsq, *partDir; /*Quebra da expressoes partes esquerda e direita*/
    int i, parentese= 0 /*parentese aberto*/;
    size_t j;

    if(!expReg)
        return;
    /*Procurando pelo operador de menor prioridade, sera o ponto de bisseccao da expressao*/
    for(i=0; i<nOp; i++)
    {
        for(j=0; j<strlen(expReg); j++) /*expressao escolhida, de baixa prioridade para alta*/
        {
            if(expReg[j] == '(') /* para caso esteja entrando no parentese onde torna a expressao prioritaria*/
                parentese++;
            else if(expReg[j] == ')') /* saindo do parentese */
                parentese--;
            else if (expReg[j] == operadores[i] && parentese == 0) /* verificando se entrou o operador, caso nao esteja dentro do parentese */
            {
                separador(expReg, &partEsq, &partDir, op, j);

                insere_arvore(raiz, *raiz, op);

                /* caso foi alcancado uma expressao minima */
                if(strlen(partEsq) == 1)
                    insere_arvore(raiz, *raiz, partEsq);
                else
                    quebraExpressao(partEsq, raiz);

                /* caso foi alcancado uma expressao minima */
                if(strlen(partDir) == 1)
                    insere_arvore(raiz, *raiz, partDir);
                else
                    quebraExpressao(partDir, raiz);

                return;
            }
        }
     }
     return;
}

/* Separar a expressao regular no ponto pre determinado */
void separador(char *expReg, char **partEsq, char **partDir, char *op, int size)
{
    char *esq, *dir;

    esq=malloc((size+1)*sizeof(char));
    dir=malloc((strlen(expReg)-size)*sizeof(char));

    strncpy(esq, expReg, size);
    esq[size] = '\0';
    strcpy(dir, expReg+size+1);

    /*
     *Retirar os parenteses no caso da expressao regular esteja contida nelas
    */

    *partEsq=esq;
    *partDir=dir;

    op[0]=expReg[size];
    op[1]='\0';

    /*retira os parenteses caso toda a expressao esteja contida nas mesmas*/
    if(*esq == '(' && *(esq+strlen(esq)-1) == ')')
    {
        esq= esq+1;
        esq[strlen(esq)-1]= '\0';
    }

    /*retira os parenteses caso toda a expressao esteja contida nas mesmas*/
    if(*dir == '(' && dir[strlen(dir)-1] == ')')
    {
        dir= dir+1;
        dir[strlen(dir)-1]= '\0';
    }

    return;
}

/* realiza as operacoes de acordo com a arvore binaria, na ordem pos ordem */

void transformacao(t_arvore *raiz)
{
    t_arvore *pl= raiz;

    /* parada da recursividade */
    if(!pl)
        return;

    transformacao(pl -> esq);
    /* caso o operador seja unario, o operador apenas opera com o ramo esquerdo (predefinindo a escolha)*/
    if(pl -> tipo_op == 1)
    {
        operacao_geral(&pl->Q, pl->esq->Q, pl->esq->Q, pl->expReg[0]);
        return;
    }
    else
        transformacao(pl->dir);

    /*operador binario*/
    if(pl->tipo_op==2)
    {
        operacao_geral(&pl->Q, pl->esq->Q, pl->dir->Q, pl->expReg[0]);
        return;
    }

    /*não operador(ER minima)*/
    mini_quintupla(&pl->Q, pl->expReg);
    return;
}

void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op)
{
    switch(op)
    {
        case '.':
            operacao_e(res, q1, q2);
            break;
        case '|':
            operacao_ou(res, q1, q2);
            break;
        case '*':
            operacao_estrela(res, q1);
            break;
        default:
            printf("\n\nErro!!!, operador nao existe %c\n\n", op);
    }
    return;
}

/* realiza a operacao concatenacao */

void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2)
{
    res->K= q1.K + q2.K;
    res->A= q1.A > q2.A ? q1.A : q2.A; /* a lei maior prevalece, sendo, a < b < c < d ...  */
    res->S= q1.S; /* estado inicial de q1 prevalece */

    res->F= NULL;
    copia_lestado(&res->F, q2.F); /*os estados finais de q2 prevalece*/

    /*ambas as transicoes de q1 e q2 sao mantidas e eh adicionado transicoes*/
    res->D= NULL;
    copia_ltrans(&res->D, q1.D);
    copia_ltrans(&res->D, q2.D);

    /*transicoes adicionadas sao as que vao unir os finais de q1 com o inicial de q2*/
    transicoes_finais(&res->D, q1.F, q2.S);

    return;
}

/* realiza a operacao ou */

void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2)
{
    /*eh adicionado mais dois estados alem dos que ja exitem nas quintuplas q1 e q2*/
    res->K= q1.K + q2.K + 2;
    res->A= q1.A > q2.A ? q1.A : q2.A; /* prevalece o maior alfabeto*/
    res->S= id_estado; /*o estado inicial eh um dos novos estados adicionados*/
    char lei[]= "E";

    res->F= NULL;
    insere_estado(&res->F, id_estado+1); /*o estado final eh um dos novos estados adicionados*/

    res->D= NULL;
    /*As transicoes de q1 e q2 sao mantidas*/
    copia_ltrans(&res->D, q1.D);
    copia_ltrans(&res->D, q2.D);

    /*o novo estado inicial eh conectado aos antigos estados inicial de q1 e q2*/
    insere_transicao(&res->D, res->S, lei, q1.S);
    insere_transicao(&res->D, res->S, lei, q2.S);

    /*O novo estado final eh conectado com os antigos estados finais de q1 e q2*/
    transicoes_finais(&res->D, q1.F, res->F->estado);
    transicoes_finais(&res->D, q2.F, res->F->estado);

    /*atualizando os estados totais*/
    id_estado+= 2;

    return;
}
/* @brief realiza a operacao estrela */

void operacao_estrela(quintupla_t *res, quintupla_t q)
{
    /* Estados, Alfabeto e Estado Inicial sao mantidos*/

    res->K= q.K;
    res->A= q.A;
    res->S= q.S;

    res->F= NULL;
    /* Estados Finais sao mantidos e o estado inicial passa ser final tambem */
    copia_lestado(&res->F, q.F);
    insere_estado(&res->F, q.S);

    res->D= NULL;
    /* Transicoes sao mantidas */
    copia_ltrans(&res->D, q.D);
    /* Os finais que se ligam com os iniciais formando a estrela */
    transicoes_finais(&res-> D, q.F, q.S);
}

/* Gera transicoes onde os estados finais deixam de ser estados finais e mudam para um novo */
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal)
{
    lest_t *pl = list;

    while(pl!=NULL)
    {
        insere_transicao(dest, pl->estado, "E", novoFinal);
        pl=pl->prox;
    }

return;
}
/* copia uma lista de estados */
void copia_lestado(lest_t **dest, lest_t *list)
{
    while(list!= NULL)
     {
         insere_estado(dest, list->estado);
         list= list->prox;
     }
    return;
}
/* copia uma lista de transicoes */
void copia_ltrans(ltrans_t **dest, ltrans_t *list)
{
    while(list!= NULL)
    {
        insere_transicao(dest, list->ei, list->lei, list->ef);
        list= list->prox;
    }

        return;
}
/* constroi uma quintupla simples, com apenas um transicao possivel, exemplos de expressoes regular -> "a", "b" ou "c" ... */

void mini_quintupla(quintupla_t *q, char *lei)
{
    q->K= 2;
    q->A= lei[0];
    q->S= id_estado;
    q->F= NULL;
    insere_estado(&q->F, id_estado+1);
    q->D= NULL;
    insere_transicao(&q->D, id_estado, lei, id_estado+1);
    id_estado+= 2;
    return;
}

void AFND_AFD_init(const char *entrada)
{
    IFDEBUG("automax_init()");
    /* initialization */

    quintupla_t Qafnd, Qafd;
    lconj_t *simultaneo= NULL;

    entrada_Automato(&Qafnd, entrada);
    estados_simultaneos(Qafnd, &simultaneo);

    estados_novos(Qafnd, &Qafd, simultaneo);

    salva_quintupla(Qafd, NULL);
    salva_quintupla(Qafd, "saida_AFD.txt");

    return;
}

/* gera um lista de conjuntos de estados simultaneos */
void estados_simultaneos(quintupla_t Q, lconj_t **simultaneo)
{
    lconj_t *plconj;
    ltrans_t *plsimul;
    lest_t *plest;
    int i;

    for(i=0; i<Q.K; i++)
    {
        insere_conjunto(simultaneo, i);
        plconj = busca_conjunto(*simultaneo, i);
        insere_estado(&plconj->estados, i);
        plest= plconj->estados;
        while(plest!= NULL)
        {
            plsimul= Q.D;
            while((plsimul= busca_simultaneo(plsimul, plest->estado)) != NULL)
            {
                insere_estado(&plconj->estados, plsimul->ef);
                plsimul= plsimul->prox;
            }
            plest= plest->prox;
        }
    }
    return;
}

/* gera a quintupla AFD */

void estados_novos(quintupla_t Qantigo, quintupla_t *Qnovo, lconj_t *simultaneo)
{
    int estado;
    char lei, slei[2];
    lconj_t *conj_estados= NULL, *plconj;
    lest_t *plest, *list= NULL;
    ltrans_t *pltrans;

    Qnovo->A= Qantigo.A;
    Qnovo->D= NULL;
    Qnovo->F= NULL;

    insere_conjunto(&conj_estados, 0);

    plconj= busca_conjunto(conj_estados, 0);
    primeiro_estado(&plconj->estados, simultaneo, Qantigo.S);
    Qnovo->S= 0;
    Qnovo->K= 1;

    while(plconj!= NULL)
    {
        for(lei='a'; lei <= Qantigo.A; ++lei)
        {
            pltrans= Qantigo.D;
            slei[0]= lei;
            slei[1]= '\0';

            plest= plconj->estados;
            list= NULL;
            while(plest!= NULL)
            {
                while((pltrans= busca_transicao(pltrans, plest->estado, slei))!= NULL)
                {
                    insere_estado(&list, pltrans->ef);
                    pltrans= pltrans->prox;
                }
                plest= plest->prox;
            }

            if(list!= NULL)
            {
                modelando_conjunto(simultaneo, &list);
                estado= novo_estado(list, &conj_estados);
                Qnovo->K= estado+1 > Qnovo->K ? estado+1 : Qnovo->K;
                insere_transicao(&Qnovo->D, plconj->id, slei, estado);
            }
            apaga_estados(&list);
        }
        plconj= plconj->prox;
   }
   definir_final(conj_estados, Qantigo.F, &Qnovo->F);
   apaga_conjunto(&conj_estados);
   return;
 }

/* gera um estado para AFD se caso ainda nao foi gerado */

int novo_estado(lest_t *list, lconj_t **conj_estados)
{
    int id;
    lconj_t *plconj= *conj_estados;

    for(id=0; plconj!= NULL; id++)
    {
        if(igualdade_conjunto(plconj->estados, list))
        {
            return id;
        }
        plconj=plconj->prox;
    }
    insere_conjuntoFULL(conj_estados, list, id);

    return id;
}

/* tranforma um conjunto de indices dos estados simultaneos para um conjunto de estados */
void modelando_conjunto(lconj_t *simultaneo, lest_t **list)
{
    lest_t *plest= *list;

    *list= NULL;

    while(plest!= NULL)
    {
        copia_estado(list, simultaneo, plest->estado);
        plest= plest->prox;
    }

    return;
}

/* Busca uma transicao com o estado inicial e o estado final como referencia */

ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef)
{
    ltrans_t *pl= list;

    while(pl!= NULL)
    {
        if(pl->ei== ei && pl->ef == ef)
        return pl;
        pl= pl->prox;
    }

    return NULL;
}

ltrans_t *busca_simultaneo(ltrans_t *list, int ref)
{
    return busca_transicao(list, ref, "E");
}

lconj_t *busca_conjunto(lconj_t *list, int id)
{
    lconj_t *pl= list;

    while(pl!= NULL)
    {
        if(pl->id == id)
        return pl;
        pl= pl->prox;
    }

    return NULL;
}

/* salva um quintupla no arquivo caso dado o nome, caso nao imprime na tela */

void salva_quintupla(quintupla_t Q, char *arquivo)
{
    FILE *pf;

    if(!arquivo)
        pf= stdout;
    else
        pf= fopen(arquivo, "w");

    fprintf(pf, "#K\n");
    fprintf(pf, "%d\n", Q.K);
    fprintf(pf, "#A\n");
    fprintf(pf, "%c\n", Q.A);
    fprintf(pf, "#S\n");
    fprintf(pf, "%d\n", Q.S);
    fprintf(pf, "#F\n");
    imprime_estados(Q.F, pf);
    fprintf(pf, "#D\n");
    imprime_transicao(Q.D, pf);

    if(arquivo)
        fclose(pf);

    return;
}

/* verificar se dois conjuntos sao iguais */
int igualdade_conjunto(lest_t *list, lest_t *list2)
{
    lest_t *pl= list, *pl2= list2;

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
        pl= pl->prox;
        pl2= pl2->prox;
    }

    return 1;
}


/* copia o estado para o conjunto de estados simultaneos */
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

/*  a funcao que copia estado e manda o primeiro estado para a lista de estados simultaneos */
void primeiro_estado(lest_t **estados, lconj_t *simultaneo, int s)
{
    copia_estado(estados, simultaneo, s);
    return;
}

void definir_final(lconj_t *conjunto, lest_t *final, lest_t **list)
{
    lconj_t *plconj= conjunto;
    lest_t *plest, *plfinal= final;

    while(plconj!= NULL)
    {
        plest= plconj->estados;
        while(plest!= NULL)
        {
            plfinal= final;
            while(plfinal!= NULL)
            {
                if(plest->estado == plfinal->estado)
                    insere_estado(list, plconj->id);
                plfinal= plfinal->prox;
            }
            plest= plest->prox;
        }
        plconj= plconj->prox;
    }

    return;
}

/* inicia a conversão de AFD para ER. */

void AFD_ER_init(const char *arquivo)
{
    IFDEBUG("automax_init()");

    int estado;
    quintupla_t Q;
    FILE *pf= fopen("saida_ER.txt", "w");

    entrada_Automato(&Q, arquivo);

    estados_limite(&Q);

    while(!lista_unitaria(Q.D))
    {
        uniao(&Q.D);

        estado= estado_eliminar(Q);

        concatena(&Q.D, estado);
    }
    fprintf(stdout, "Expressao Regular: %s\n", Q.D->lei);
    fprintf(pf, "%s", Q.D->lei);
    fclose(pf);
    return;
}

/* limita a quintupla para apenas uma unica entrada e uma unica saida da AFD */

void estados_limite(quintupla_t *Q)
{
    lest_t *pl= Q->F;
    insere_transicao(&Q->D, Q->K, "E", Q->S);

    while(pl!= NULL)
    {
        insere_transicao(&Q->D, pl->estado, "E", Q->K+1);
        pl= pl->prox;
    }
    return;
}

/* verifica se a lista das transicoes possui apenas um elemento */

int lista_unitaria(ltrans_t *list)
{
    if(!list)
        return 0;
    return list->prox == NULL ? 1 : 0;
}
/* procura por transicoes semelhantes do tipo transicao 1 e 2 (ei1 == ei2, lei1 != ou == lei2, ef1 == ef2), e faz a uniao das leis separando as pelo operador | */

void uniao(ltrans_t **list)
{
    ltrans_t *pl, *pl2, res/* variavel que vai unificar as transicoes semelhantes*/;

    while(busca_semelhantes(*list, &pl, &pl2)) /* procurando por transicoes semelhantes, retorna 0 se nada for encontrado, e 1 se encontrado*/
    {
        res.ei= pl->ei;
        res.ef= pl->ef;
        res.lei= malloc(definir_tamanho(pl->lei, pl2->lei) * sizeof(char)); /* definindo o tamanho da string que vai unir as leis*/

        /* processo de atribuicao da uniao das leis em um string*/
        if(strcmp(pl->lei, "E") != 0)
        {
            strcpy(res.lei, pl->lei);
            if(strcmp(pl2->lei, "E") != 0)
            {
                strcat(res.lei, "|");
                strcat(res.lei, pl2->lei);
            }
        }
        else
        {
            if(strcmp(pl2->lei, "E") != 0)
                strcpy(res.lei, pl2->lei);
            else
                strcpy(res.lei, "E");
        }

        remove_transicao(list, pl);
        remove_transicao(list, pl2);
        insere_transicao(list, res.ei, res.lei, res.ef);
        free(res.lei);
    }
    return;
}
/* Procura pelo estado com menos interacoes, e ignora os estado limitesn*/
int estado_eliminar(quintupla_t Q)
{
    int vetor[Q.K], i, menor /* indice do vetor com menor valor*/;
    ltrans_t *pl= Q.D;

    for(i=0; i<Q.K; i++) vetor[i]= 0;

    while(pl!= NULL)
    {
        if(pl->ei < Q.K)
            vetor[pl->ei]+= 1;
        if(pl->ef < Q.K)
            vetor[pl->ef]+= 1;

     pl= pl->prox;
    }
    menor= 0; /* indice do vetor inicial*/
    for(i=1; i<Q.K; i++)
    {
        if(vetor[menor] == 0)
            menor = i;
        else if(vetor[menor] > vetor[i] && vetor[i] != 0)
            menor= i;
    }
    return menor;
}
/* faz a concatenacao de duas leis dado o estado que sera eliminado nessa juncao, Se apropria da funcao concatena_aux para atribuir as leis em uma unica string */

void concatena(ltrans_t **list, int est)
{
    ltrans_t *pl= *list, *pl2, *plr, *pl2r, res;
    char *chstar, *aux;

    chstar= estrela(list, est); /* verifica se o estado selecionado possui a estrela*/

    while((pl= busca_por_ef(pl, est)) != NULL) /* procurando por transicoes que terminam com o estado de referencia (est)*/
    {
        pl2= *list;
        while((pl2= busca_por_ei(pl2, est))!= NULL) /* procurando por transicoes que inicia com o 'est'*/
        {
            /* Processo de concatenacao*/
            res.ei= pl->ei;

            if(chstar!= NULL)
            {
                concatena_aux(&aux, pl->lei, chstar);
                concatena_aux(&res.lei, aux, pl2->lei);
            }
            else
                concatena_aux(&res.lei, pl->lei, pl2->lei);
            res.ef= pl2->ef;

            insere_transicao(list, res.ei, res.lei, res.ef);
           /* ---------------------------------- */

           pl2r= pl2;
           pl2= pl2->prox;
           remove_transicao(list, pl2r);
        }
        plr= pl;
        pl= pl->prox;
        remove_transicao(list, plr);
    }
    return;
}

/* Funcao que contatena (atribui) duas leis numa string */

void concatena_aux(char **dest, char *ch, char *ch2)
{
    *dest= malloc(definir_tamanho(ch, ch2) * sizeof(char));

     if(strcmp(ch, "E") != 0)
     {
         if(strlen(ch)> 1 && strcmp(ch2, "E") != 0)
         {
             strcpy(*dest, "(");
             strcat(*dest, ch);
             strcat(*dest, ")");
         }
         else
             strcpy(*dest, ch);
     }

     if(strcmp(ch2, "E") != 0)
     {
         if(strcmp(ch, "E") != 0)
         {
             strcat(*dest, ".");
             if(strlen(ch2)> 1)
             {
                 strcat(*dest, "(");
                 strcat(*dest, ch2);
                 strcat(*dest, ")");
             }
             else
                 strcat(*dest, ch2);
         }
         else
             strcpy(*dest, ch2);
     }

      if(strcmp(ch, "E") == 0 && strcmp(ch2, "E") == 0)
          strcpy(*dest, "E");

      return;
}

/* verifica se o estado dado possui a estrela, se caso sim, retorna a lei, se nao retorna NULL */

char *estrela(ltrans_t **list, int ei_ef)
{
    int tamanho= 0;
    char *chstar;
    ltrans_t *plstar;

    if((plstar= busca_transicao_lei(*list, ei_ef, ei_ef)) == NULL)
        return NULL;

    if((tamanho= strlen(plstar->lei)) > 1)
        tamanho+= 2;

    chstar= malloc((tamanho + 1)*sizeof(char));

    if(strlen(plstar->lei) > 1)
        strcpy(chstar, "(");
    else
        strcpy(chstar, "");

    strcat(chstar, plstar->lei);

    if(strlen(plstar->lei) > 1)
        strcat(chstar, ")");

    strcat(chstar, "*");
    remove_transicao(list, plstar);

    return chstar;
}

/* define o tamanho de memoria que sera usada para armazena duas leis */
int definir_tamanho(char *ch, char *ch2)
{
    int tamanho= 0;

    if(strcmp(ch, "E")!= 0)
    {
        tamanho+= strlen(ch) +1; /*para o ponto ou \0 */
        if(strlen(ch)>1)
            tamanho+= 2; /*2 para os parenteses*/
    }

    if(strcmp(ch2, "E")!= 0)
    {
        tamanho+= strlen(ch) + 1; /* para o \0*/
        if(strlen(ch) > 1)
            tamanho+= 2; /*2 para os parenteses*/
    }

    return tamanho > 0 ? tamanho : 2;
}

/*-----Entrada-----*/

/* Coleta as entradas do arquivo (quintuola AFND) */
void entrada_Automato(quintupla_t *Q, const char *entrada)
{
    FILE *pf = fopen(entrada, "r");
    char ch[SBUFF];

    fgets(ch, SBUFF, pf); /* #K*/
    fgets(ch, SBUFF, pf); /* #K*/
    Q->K= atoi(ch);

    fgets(ch, SBUFF, pf); /* #A*/
    fgets(ch, SBUFF, pf); /* #A*/
    Q->A= *ch;

    fgets(ch, SBUFF, pf); /* #S*/
    fgets(ch, SBUFF, pf); /* #S*/
    Q->S= atoi(ch);

    fgets(ch, SBUFF, pf); /* #F*/
    Q->F= NULL;
    coleta_final(&Q->F, pf);

    fgets(ch, SBUFF, pf); /* #D*/
    Q->D= NULL;
    coleta_transicao(&Q->D, pf);

    fclose(pf);

    return;
}

/* Armazena estados finais do arquivo coletado */
void coleta_final(lest_t **list, FILE *stream)
{
    char ch[SBUFF], *sch;

    fgets(ch, SBUFF, stream);
    sch = strtok(ch, " ");

    do
    {
        insere_estado(list, atoi(sch));
    }while((sch = strtok(NULL, " ")) != NULL);

    return;
}

/* Coleta as transicoes do arquivo */
void coleta_transicao(ltrans_t **list, FILE *stream)
{
    char ch[SBUFF], *sei, *slei, *sef;

    while(fgets(ch, SBUFF, stream)!= NULL)
    {
        if(strcmp(ch, "\n")==0)
            return;

        sei = strtok(ch, " ");
        slei = strtok(NULL, " ");
        sef = strtok(NULL, " ");

        insere_transicao(list, atoi(sei), slei, atoi(sef));
    }

    return;
}

/* Ler e armazerna a ER(expressao regular) */
void entrada_ER(char *expReg, char *entrada)
{
    FILE *pf = fopen (entrada, "r");

    fgets(expReg, SBUFF, pf);

    return;
}

/* ----------------- Funcoes de Busca ------------------------ */

/* busca por transicoes onde o estado inicial de uma transicao eh igual a de outra, como tambem com os estados finais ei1 == ei2 && ef1 == ef2 */
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2)
{
    ltrans_t *plist= list, *plbusca;

    while(plist!= NULL)
    {
        if((plbusca= busca_transicao_lei(plist->prox, plist->ei, plist->ef)) != NULL)
        {
            *pl= plist;
            *pl2= plbusca;
            return 1;
        }
        plist= plist->prox;
    }
    return 0;
}

/* Busca uma transicao usando apenas o estado inicial como referencia de busca */
ltrans_t *busca_por_ei(ltrans_t *list, int est)
{
    ltrans_t *pl= list;

    while(pl!= NULL)
    {
        if(pl->ei == est)
            return pl;
        pl= pl->prox;
    }
    return NULL;
}

/*  Busca uma transicao usando apenas o estado final como referencia de busca */
ltrans_t *busca_por_ef(ltrans_t *list, int est)
{
    ltrans_t *pl= list;

    while(pl!= NULL)
    {
        if(pl->ef == est)
            return pl;
        pl= pl->prox;
    }

    return NULL;
}

/* Busca uma transicao com o estado inicial e a lei como referencia */

ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei)
{
    ltrans_t *pl= list;

    while(pl!= NULL)
    {
        if(pl->ei == ei && strcmp(pl->lei, lei)== 0)
            return pl;
        pl= pl->prox;
    }

    return NULL;
}

/* imprime uma lista de Transicoes */

void imprime_transicao(ltrans_t *list, FILE *stream)
{
    ltrans_t *pl= list;

    while(pl!= NULL)
    {
        fprintf(stream, "%d %s %d\n", pl->ei, pl->lei, pl->ef);
        pl= pl->prox;
    }
    return;
}

void imprime_conjunto(lconj_t *list, FILE *stream)
{
    lconj_t *pl= list;

    while(pl!= NULL)
    {
        fprintf(stream, "%d: ", pl->id);
        imprime_estados(pl->estados, stream);
        pl= pl->prox;
    }

    fprintf(stream, "\n");
    return;
}


/* imprime uma lista de estados */
void imprime_estados(lest_t *list, FILE *stream)
{
    lest_t *pl= list;

    if(pl!= NULL)
    {
        fprintf(stream, "%d", pl->estado);
        pl= pl->prox;
    }

    while(pl!= NULL)
    {
        fprintf(stream, " %d", pl->estado);
        pl= pl->prox;
    }
    fprintf(stream, "\n");
    return;
}

/* imprime os arvores em preordem */
void imprime_arvore(t_arvore *raiz, FILE *stream)
{
    t_arvore *pl= raiz;

    if(!pl)
        return;

    imprime_arvore(pl->esq, stream);
    imprime_arvore(pl->dir, stream);

    printf("\n");
    if(pl->tipo_op == 2)
        fprintf(stream, "(%s)%s(%s)\n", pl->esq->expReg, pl->expReg, pl->dir->expReg);
    else if(pl->tipo_op == 1)
        fprintf(stream, "(%s)%s\n", pl->esq->expReg, pl->expReg);
    else
        fprintf(stream, "%s\n", pl->expReg);

    salva_quintupla(pl->Q, NULL);
    getchar();
    printf("\n");

    return;
}
/* ----------------------------- insere ----------------------- */

void insere_conjunto(lconj_t **list, int id)
{
    lconj_t *pl= *list, *plant= NULL;

    while(pl!= NULL)
    {
        plant= pl;
        pl= pl->prox;
    }
    pl= malloc(sizeof(lconj_t));
    pl->id= id;
    pl->estados= NULL;
    pl->prox= NULL;

    if(!plant)
        *list= pl;
    else
        plant->prox= pl;
    return;
}
void insere_conjuntoFULL(lconj_t **conjunto, lest_t *list, int id)
{
    lconj_t *pltrans;
    insere_conjunto(conjunto, id);
    pltrans= busca_conjunto(*conjunto, id);

    while(list!= NULL)
    {
        insere_estado(&pltrans->estados, list->estado);
        list= list->prox;
    }
    return;
}
/* cria uma lista e atribui novos elementos a lista de estados */

void insere_estado(lest_t **list, int est)
{
    lest_t *pl= *list, *plant= NULL;

     while(pl!= NULL)
     {
         if(pl->estado > est)
             break;
         else if(pl->estado == est)
             return;

         plant= pl;
         pl= pl->prox;
     }
     pl= malloc(sizeof(lest_t));
     pl->estado= est;
     pl->prox= NULL;

     if(!plant)
     {
         pl->prox= *list;
         *list= pl;
     }
     else
     {
         pl->prox= plant->prox;
         plant->prox= pl;
     }
     return;
}
/* cria uma lista e atribui novos elementos a lista de transicoesn */

void insere_transicao(ltrans_t **list, int ei, char *lei, int ef)
{
    ltrans_t *pl= *list, *plant= NULL;

    while(pl!= NULL)
    {
        plant= pl;
        pl= pl->prox;
    }

    pl= malloc(sizeof(ltrans_t));
    pl->ei= ei;
    pl->lei= (char *) malloc(strlen(lei) * sizeof(char));
    strcpy(pl->lei, lei);
    pl->ef= ef;
    pl->prox= NULL;

   if(!plant)
       *list= pl;
   else
       plant->prox= pl;
   return;
}
/* salva e organiza informacoes no formato de arvore binaria, insere em preordem */

void insere_arvore(t_arvore **raiz, t_arvore *ant, char *info)
{
    t_arvore *pl= *raiz;

    if(!pl)
    {
        pl= malloc(sizeof(t_arvore));
        pl->expReg= malloc(strlen(info) * sizeof(char));
        strcpy(pl->expReg, info);
        pl->tipo_op= tipo_operador(pl->expReg[0]);
        pl->esq= NULL;
        pl->dir= NULL;
        pl->pai= ant;
        *raiz= pl;
        return;
    }
    if(pl->tipo_op == 0 || pl->dir == ant || (pl->tipo_op == 1 && pl->esq == ant))
    insere_arvore(&pl->pai, pl, info);
    else if (pl->esq == ant)
        insere_arvore(&pl->dir, pl, info);
    else
        insere_arvore(&pl->esq, pl, info);
    return;
}

/* remove um elemento da lista de estados */

void remove_estado(lest_t **list, lest_t *r)
{
    lest_t *pl= *list, *plant= NULL;

    while(pl!= NULL)
    {
        if(pl == r)
            break;
        plant= pl;
        pl= pl->prox;
    }

    if(!pl)
        return;

    if(!plant)
        *list= pl->prox;
    else
        plant->prox= pl->prox;

    free(pl);
    return;
}

/* remove um elemento da lista das transicoes */

void remove_transicao(ltrans_t **list, ltrans_t *r)
{
    ltrans_t *pl= *list, *plant= NULL;

    while(pl!= NULL)
    {
        if(pl == r)
            break;
        plant= pl;
        pl= pl->prox;
    }

    if(!pl)
        return;

    if(!plant)
        *list= pl->prox;
    else
        plant->prox= pl->prox;

    free(pl);
    return;
}

/* apaga toda um lista de estados */

void apaga_estados(lest_t **list)
{
    lest_t *pl= *list;

    while(pl!= NULL)
    {
        remove_estado(list, pl);
        pl= *list;
    }
    return;
}

/* apaga toda uma lista de transicoes */

void apaga_transicao(ltrans_t **list)
{
    ltrans_t *pl= *list;

    while(pl!= NULL)
    {
        remove_transicao(list, pl);
        pl= *list;
    }
}

void remove_conjunto(lconj_t **list, lconj_t *r)
{
    lconj_t *pl= *list, *plant= NULL;

    while(pl!= NULL)
    {
        if(pl == r)
            break;
        plant= pl;
        pl= pl->prox;
    }

    if(!pl)
        return;

    if(!plant)
        *list= pl->prox;
    else
        plant->prox= pl->prox;

    free(pl);
    return;
}

void apaga_conjunto(lconj_t **list)
{
    lconj_t *pl= *list;

    while(pl!= NULL)
    {
        apaga_estados(&pl->estados);
        remove_conjunto(list, pl);
        pl= *list;
    }

    return;
}

void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "automax", "Converte AFD, AFND e ER");
    printf("\nUsage: %s [-h|-v]\n", "automax");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\t-n, --nfa\n\t\tInput data is a NFA (Nondeterministic Finite Automata) 5-tuple to be converted to a DFA (Deterministic Finite Automata) 5-tuple.\n");
    printf("\t-e, --re\n\t\tInput data is a RE (Regular Expression) string to be converted to a NFA (Nondeterministic Finite Automata) 5-tuple.\n");
    printf("\t-d, --dfa\n\t\tInput data is an DFA (Deterministic Finite Automata) 5-tuple to be converted to RE (Regular Expression) string.\n");
    /*
    * -n : a entrada de dados é uma quíntupla de um AFND que será convertido para AFD.
    * -d : a entrada de dados é uma quíntupla de um AFD que será convertido para uma ER.
    * -e : a entrada de dados é uma _string_ de uma ER que será convertida em um AFND.
    */
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
    printf("%s - Version %s\n", "automax", VERSION);
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
void automax_init(void)
{
    IFDEBUG("automax_init()");
    /* initialization */
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

