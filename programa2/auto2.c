/***************************************************************************
 *   auto2.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert AFD into ER                                                   *
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
 * @file auto2.c
 * @ingroup GroupUnique
 * @brief Convert AFD into ER
 * @details This program really do a nice job as a template, and template only!
 * @version 20160520.000202
 * @date 2017-11-28
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
 *   $gcc auto2.c -o auto2.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto2.h */

#include "auto2.h" /* To be created for this template if needed */

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
 *    $./auto2 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-05-20
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    int cont = 0;

    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhcf:")) != EOF)
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
                    auto2_init(argv[2]);
                else
                    auto2_init("saida_AFD.txt");

                break;
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);
    auto2_init_entrada_padrao();
    return EXIT_SUCCESS;
}


/* _ENTRADA_ */
void auto2_entrada(quintupla_t *Q, const char *entrada)
{
    FILE *pf = fopen(entrada, "r");
    char ch[SBUFF];

    fgets(ch, SBUFF, pf); /* #K*/
    fgets(ch, SBUFF, pf); /* #K*/
    Q->K = atoi(ch);

    fgets(ch, SBUFF, pf); /* #A*/
    fgets(ch, SBUFF, pf); /* #A*/
    Q->A = *ch;

    fgets(ch, SBUFF, pf); /* #S*/
    fgets(ch, SBUFF, pf); /* #S*/
    Q->S = atoi(ch);

    fgets(ch, SBUFF, pf); /* #F*/
    Q->F = NULL;
    coleta_final(&Q->F, pf);

    fgets(ch, SBUFF, pf); /* #D*/
    Q->D = NULL;
    coleta_transicao(&Q->D, pf);

    fclose(pf);

    return;
}

void auto2_entrada_padrao(quintupla_t *Q)
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
    imprime_estados(Q.F, pf);
    fprintf(pf, "#D\n");
    imprime_transicao(Q.D, pf);

    if(arquivo)
        fclose(pf);

    return;
}
/* ---------------------------------------------------------------------- */

/* operacoes de conversao */

/* Função para adicionar transições finais em um AFND. */
void transicoes_finais(ltrans_t **dest, lest_t *list, int novoFinal)
{
    lest_t *pl = list; /* Inicializa um ponteiro para percorrer a lista de estados finais */

    /* Percorre todos os estados na lista de estados finais */
    while(pl != NULL)
    {
        insere_transicao(dest, pl->estado, "E", novoFinal);/* Insere uma transição epsilon ('E') do estado atual para o novo estado final */
        pl = pl->prox;
    }

    return;
}

/* Função para definir estados limite em um AFND. */
void estados_limite(quintupla_t *Q)
{
    lest_t *pl = Q->F; /* Inicializa um ponteiro para percorrer a lista de estados finais */
    insere_transicao(&Q->D, Q->K, "E", Q->S);

    while(pl != NULL)
    {
        insere_transicao(&Q->D, pl->estado, "E", Q->K + 1); /* Insere uma transição epsilon do estado final para um novo estado final */
        pl = pl->prox;
    }
    return;
}

/* Função para verificar se uma lista de transições tem apenas um elemento. */
int lista_unitaria(ltrans_t *list)
{
    if(!list) /* Verifica se a lista é nula */
        return 0;
    return list->prox == NULL ? 1 : 0;
}

void uniao(ltrans_t **list)
{
    ltrans_t *pl, *pl2, res/* variavel que vai unificar as transicoes semelhantes*/;

    while(busca_semelhantes(*list, &pl, &pl2)) /* procurando por transicoes semelhantes, retorna 0 se nada for encontrado, e 1 se encontrado*/
    {
        res.ei = pl->ei;
        res.ef = pl->ef;
        res.lei = malloc(def_tamanho(pl->lei, pl2->lei) * sizeof(char)); /* definindo o tamanho da string que vai unir as leis*/

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

int eliminar_estado(quintupla_t Q)
{
    int vetor[Q.K], i, menor /* indice do vetor com menor valor*/;
    ltrans_t *pl = Q.D;

    for(i = 0; i < Q.K; i++) vetor[i] = 0;

    while(pl != NULL)
    {
        if(pl->ei < Q.K)
            vetor[pl->ei] += 1;
        if(pl->ef < Q.K)
            vetor[pl->ef] += 1;

        pl = pl->prox;
    }
    menor = 0; /* indice do vetor inicial*/
    for(i = 1; i < Q.K; i++)
    {
        if(vetor[menor] == 0)
            menor = i;
        else
            if(vetor[menor] > vetor[i] && vetor[i] != 0)
                menor = i;
    }
    return menor;
}

/* Concatena transições em um autômato, considerando um estado específico */
void concatenacao(ltrans_t **list, int est)
{
    ltrans_t *pl = *list, *pl2, *plr, *pl2r, res;
    char *chstar, *aux;

    chstar = estrela(list, est); /* verifica se o estado selecionado possui a estrela*/

    while((pl = busca_por_ef(pl, est)) != NULL) /* procurando por transicoes que terminam com o estado de referencia (est)*/
    {
        pl2 = *list;
        while((pl2 = busca_por_ei(pl2, est)) != NULL) /* procurando por transições que inicia com o 'est'*/
        {
            /* Processo de concatenação*/
            res.ei = pl->ei;

            if(chstar != NULL)
            {
                concatenacao_aux(&aux, pl->lei, chstar); /* Concatena a lei da transição com a estrela */
                concatenacao_aux(&res.lei, aux, pl2->lei);/* Concatena o resultado anterior com a próxima lei */
            }
            else
                concatenacao_aux(&res.lei, pl->lei, pl2->lei); /* Concatena diretamente as leis das transições */
            res.ef = pl2->ef;
            res.ef = pl2->ef;

            insere_transicao(list, res.ei, res.lei, res.ef); /* Insere a nova transição concatenada na lista */
            /* ---------------------------------- */

            /* Libera a transição intermediária */
            pl2r = pl2;
            pl2 = pl2->prox;
            remove_transicao(list, pl2r);
        }
        /* Libera a transição inicial */
        plr = pl;
        pl = pl->prox;
        remove_transicao(list, plr);
    }
    return;
}

/* Concatena duas cadeias de caracteres considerando regras específicas */
/* E no codigo se refere a epslon ou a uma cadeia vazia sendo este o termo utilizado no codigo */
void concatenacao_aux(char **dest, char *ch, char *ch2)
{
    *dest = malloc(def_tamanho(ch, ch2) * sizeof(char)); /* Aloca memória para a nova string concatenada */

    if(strcmp(ch, "E") != 0) /* Verifica se a primeira cadeia não é uma cadeia vazia */
    {
        if(strlen(ch) > 1 && strcmp(ch2, "E") != 0)
        {
            strcpy(*dest, "(");
            strcat(*dest, ch); /* Adiciona a primeira cadeia */
            strcat(*dest, ")");
        }
        else
            strcpy(*dest, ch); /* Copia a cadeia diretamente */
    }

    if(strcmp(ch2, "E") != 0) /* Verifica se a segunda cadeia não é a cadeia vazia */
    {
        if(strcmp(ch, "E") != 0) /* Se a primeira cadeia também não é a cadeia vazia */
        {
            strcat(*dest, ".");
            if(strlen(ch2) > 1) /* Se a segunda cadeia tem mais de um caractere */
            {
                strcat(*dest, "(");
                strcat(*dest, ch2); /* Adiciona a segunda cadeia */
                strcat(*dest, ")");
            }
            else
                strcat(*dest, ch2); /* Concatena a segunda cadeia diretamente */
        }
        else
            strcpy(*dest, ch2); /* Copia a segunda cadeia diretamente */
    }

    if(strcmp(ch, "E") == 0 && strcmp(ch2, "E") == 0) /* Se ambas forem vazia */
        strcpy(*dest, "E"); /* Define o resultado como uma cadeia vazia */

    return;
}

/* Aplica estrela de Kleene a uma transição específica, retornando a string resultante ou NULL se não encontrada. */
char *estrela(ltrans_t **list, int ei_ef)
{
    int tamanho = 0;
    char *chstar;
    ltrans_t *plstar;

    if((plstar = busca_transicao_lei(*list, ei_ef, ei_ef)) == NULL)
        return NULL;

    if((tamanho = strlen(plstar->lei)) > 1)
        tamanho += 2;

    chstar = malloc((tamanho + 1) * sizeof(char));

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

int def_tamanho(char *ch, char *ch2)
{
    int tamanho = 0;

    if(strcmp(ch, "E") != 0)
    {
        tamanho += strlen(ch) + 1; /*para o ponto ou \0 */
        if(strlen(ch) > 1)
            tamanho += 2; /*2 para os parenteses*/
    }

    if(strcmp(ch2, "E") != 0)
    {
        tamanho += strlen(ch) + 1; /* para o \0*/
        if(strlen(ch) > 1)
            tamanho += 2; /*2 para os parenteses*/
    }

    return tamanho > 0 ? tamanho : 2;
}
/* ---------------------------------------------------------------------- */

/* funcoes de busca */

/* Busca por transições semelhantes em uma lista de transições */
int busca_semelhantes(ltrans_t *list, ltrans_t **pl, ltrans_t **pl2)
{
    ltrans_t *plist = list, *plbusca; /* Inicializa ponteiros para percorrer a lista e para a busca */

    while(plist != NULL)
    {
        /* Busca por uma transição com os mesmos estados inicial e final */
        if((plbusca = busca_transicao_lei(plist->prox, plist->ei, plist->ef)) != NULL)
        {
            *pl = plist; /* Define a primeira transição semelhante */
            *pl2 = plbusca; /* Define a segunda transição semelhante */
            return 1;
        }
        plist = plist->prox; /* Move para a próxima transição na lista */
    }
    return 0;
}

/* Busca uma transição específica em uma lista de transições */
ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef)
{
    ltrans_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        if(pl->ei == ei && pl->ef == ef) /* Verifica se os estados inicial e final coincidem */
            return pl;
        pl = pl->prox; /* Move para a próxima transição na lista */
    }

    return NULL;
}

/* Busca uma transição com um estado específico e símbolo "E" */
ltrans_t *busca_simultaneo(ltrans_t *list, int ref)
{
    return busca_transicao(list, ref, "E"); /* Chama busca_transicao para encontrar a transição com estado ref e símbolo "E" */
}

/* Busca um conjunto específico em uma lista de conjuntos */
lconj_t *busca_conjunto(lconj_t *list, int id)
{
    lconj_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        if(pl->id == id) /* Inicializa um ponteiro para percorrer a lista */
            return pl;
        pl = pl->prox; /* Inicializa um ponteiro para percorrer a lista */
    }

    return NULL; /* Retorna NULL se não encontrar o conjunto */
}

/* Busca uma transição específica em uma lista de transições */
ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei)
{
    ltrans_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        /* Verifica se o estado inicial e o símbolo lido coincidem com os parâmetros fornecidos */
        if(pl->ei == ei && strcmp(pl->lei, lei) == 0)
            return pl;
        pl = pl->prox; /* Move para a próxima transição na lista */
    }

    return NULL;
}

/* Busca uma transição específica pelo estado inicial em uma lista de transições */
ltrans_t *busca_por_ei(ltrans_t *list, int est)
{
    ltrans_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        if(pl->ei == est) /* Verifica se o estado inicial coincide com o parâmetro fornecido */
            return pl;
        pl = pl->prox; /* Move para a próxima transição na lista */
    }
    return NULL;
}

/* Busca uma transição específica pelo estado final em uma lista de transições */
ltrans_t *busca_por_ef(ltrans_t *list, int est)
{
    ltrans_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        if(pl->ef == est) /* Verifica se o estado final coincide com o parâmetro fornecido */
            return pl;
        pl = pl->prox; /* Move para a próxima transição na lista */
    }

    return NULL;
}

/* ---------------------------------------------------------------------- */

/* funcoes de impressao */

/* Imprime os estados de uma lista encadeada de estados em um arquivo */
void imprime_estados(lest_t *list, FILE *stream)
{
    lest_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    if(pl != NULL)
    {
        fprintf(stream, "%d", pl->estado); /* Imprime o primeiro estado na lista */
        pl = pl->prox; /* Move para o próximo estado */
    }

    while(pl != NULL)
    {
        fprintf(stream, " %d", pl->estado); /* Imprime os estados subsequentes separados por espaço */
        pl = pl->prox; /* Move para o próximo estado */
    }
    fprintf(stream, "\n");
    return;
}

/* Imprime uma árvore de expressões em formato prefixo em um arquivo */
void imprime_arvore(t_arvore *raiz, FILE *stream)
{
    t_arvore *pl = raiz; /* Inicializa um ponteiro para percorrer a árvore */

    if(!pl)
        return;

    imprime_arvore(pl->esq, stream); /* Imprime a subárvore esquerda recursivamente */
    imprime_arvore(pl->dir, stream); /* Imprime a subárvore direita recursivamente */

    printf("\n");

    /* Imprime a expressão da raiz da subárvore atual no arquivo de saída */
    if(pl->tipo_op == 2)
        fprintf(stream, "(%s)%s(%s)\n", pl->esq->expReg, pl->expReg, pl->dir->expReg);
    else
        if(pl->tipo_op == 1)
            fprintf(stream, "(%s)%s\n", pl->esq->expReg, pl->expReg);
        else
            fprintf(stream, "%s\n", pl->expReg);

    salva_quintupla(pl->Q, NULL); /* Salva a quintupla associada à raiz da subárvore */
    getchar();
    printf("\n");

    return;
}

/* Imprime as transições de uma lista encadeada de transições em um arquivo */
void imprime_transicao(ltrans_t *list, FILE *stream)
{
    ltrans_t *pl = list; /* Inicializa um ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        fprintf(stream, "%d %s %d\n", pl->ei, pl->lei, pl->ef); /* Imprime a transição atual no formato "ei lei ef" */
        pl = pl->prox; /* Move para o próximo elemento da lista */
    }
    return;
}



/* ---------------------------------------------------------------------- */

/* funcoes de inserssao */

/* Insere um novo estado ordenadamente em uma lista encadeada de estados */
void insere_estado(lest_t **list, int est)
{
    lest_t *pl = *list, *plant = NULL; /* Inicializa ponteiros para percorrer a lista e para o elemento anterior */

    while(pl != NULL)
    {
        if(pl->estado > est) /* Verifica se encontrou a posição correta para inserir o estado */
            break;
        else
            if(pl->estado == est) /* Se o estado já existe na lista, retorna sem inserir novamente */
                return;

        plant = pl; /* Atualiza o ponteiro para o elemento anterior */
        pl = pl->prox;
    }
    pl = malloc(sizeof(lest_t)); /* Aloca memória para o novo estado */
    pl->estado = est;
    pl->prox = NULL; /* Inicializa o próximo como NULL */

    if(!plant) /* Se a lista está vazia ou o novo estado deve ser o primeiro */
    {
        pl->prox = *list;
        *list = pl;
    }
    else
    {
        pl->prox = plant->prox; /* Liga o novo estado ao próximo do anterior */
        plant->prox = pl; /* Liga o anterior ao novo estado */
    }
    return;
}

/* Insere uma nova transição no final de uma lista encadeada de transições */
void insere_transicao(ltrans_t **list, int ei, char *lei, int ef)
{
    ltrans_t *pl = *list, *plant = NULL; /* Inicializa ponteiros para percorrer a lista e para o elemento anterior */

    while(pl != NULL)
    {
        plant = pl; /* Atualiza o ponteiro para o elemento anterior */
        pl = pl->prox; /* Move para o próximo elemento da lista */
    }

    pl = malloc(sizeof(ltrans_t)); /* Aloca memória para a nova transição */
    pl->ei = ei;
    pl->lei = (char *) malloc(strlen(lei) * sizeof(char)); /* Aloca memória para o símbolo lido e copia o valor */
    strcpy(pl->lei, lei);
    pl->ef = ef; /* Define o estado final da transição */
    pl->prox = NULL;

    if(!plant)
        *list = pl; /* Define o novo elemento como o primeiro da lista */
    else
        plant->prox = pl; /* Liga o novo elemento ao final da lista */
    return;
}

/* ---------------------------------------------------------------------- */

/* funcoes de limpeza */

/* Remove um estado específico de uma lista encadeada de estados */
void remove_estado(lest_t **list, lest_t *r)
{
    lest_t *pl = *list, *plant = NULL; /* Inicializa ponteiros para percorrer a lista e para o elemento anterior */

    while(pl != NULL)
    {
        if(pl == r)
            break;
        plant = pl; /* Atualiza o ponteiro para o elemento anterior */
        pl = pl->prox;
    }

    if(!pl) /* Se o estado não for encontrado, retorna */
        return;

    if(!plant)
        *list = pl->prox; /* Se o estado a ser removido é o primeiro, atualiza a cabeça da lista */
    else
        plant->prox = pl->prox; /* Se o estado a ser removido não é o primeiro, ajusta o ponteiro do elemento anterior */

    free(pl);
    return;
}

/* Remove uma transição específica de uma lista encadeada de transições */
void remove_transicao(ltrans_t **list, ltrans_t *r)
{
    ltrans_t *pl = *list, *plant = NULL; /* Inicializa ponteiros para percorrer a lista e para o elemento anterior */

    while(pl != NULL)
    {
        if(pl == r)
            break;
        plant = pl; /* Atualiza o ponteiro para o elemento anterior */
        pl = pl->prox;
    }

    if(!pl) /* Se a transição não for encontrada, retorna */
        return;

    if(!plant)
        *list = pl->prox; /* Se a transição a ser removida é a primeira, atualiza a cabeça da lista */
    else
        plant->prox = pl->prox; /* Se a transição a ser removida não é a primeira, ajusta o ponteiro do elemento anterior */

    free(pl); /* Libera a memória da transição removida */
    return;
}

/* Remove todos os estados de uma lista encadeada de estados */
void apaga_estados(lest_t **list)
{
    lest_t *pl = *list; /* Inicializa o ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        remove_estado(list, pl); /* Remove o estado atual da lista */
        pl = *list; /* Atualiza o ponteiro para o próximo elemento da lista */
    }
    return;
}

/* Remove todas as transições de uma lista encadeada de transições */
void apaga_transicao(ltrans_t **list)
{
    ltrans_t *pl = *list; /* Inicializa o ponteiro para percorrer a lista */

    while(pl != NULL)
    {
        remove_transicao(list, pl); /* Remove a transição atual da lista */
        pl = *list; /* Atualiza o ponteiro para o próximo elemento da lista */
    }
}

/* Remove um elemento específico de uma lista encadeada de conjuntos */
void remove_conjunto(lconj_t **list, lconj_t *r)
{
    lconj_t *pl = *list, *plant = NULL; /* Inicializa ponteiros para percorrer a lista e para o elemento anterior */

    while(pl != NULL)
    {
        if(pl == r) /* Encontra o elemento a ser removido */
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl) /* Se o elemento não for encontrado, retorna */
        return;

    if(!plant)
        *list = pl->prox; /* Se o elemento a ser removido é o primeiro, atualiza a cabeça da lista */
    else
        plant->prox = pl->prox; /* Se o elemento a ser removido não é o primeiro, ajusta o ponteiro do elemento anterior */

    free(pl); /* Libera a memória do elemento removido */
    return;
}

/* Função para apagar um conjunto de estados */
void apaga_conjunto(lconj_t **list)
{
    lconj_t *pl = *list; /* Inicializa um ponteiro para o nó atual na lista */

    while(pl != NULL) /* Loop até o fim da lista */
    {
        apaga_estados(&pl->estados); /* Apaga os estados no nó atual */
        remove_conjunto(list, pl);
        pl = *list; /* Atualiza o ponteiro para o próximo nó */
    }

    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void help(void)
{
    IFDEBUG("help()");
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "auto2", VERSION, "Convert AFD into ER");
    printf("\nUsage: %s [-h|-v|-c]\n", "auto2");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-d): input data is an DFA (Deterministic Finite Automata) 5-tuple to be converted to RE (Regular Expression) string.\n");
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
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto2", VERSION);
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
void auto2_init(const char *arquivo)
{
    /* initialization */

    int estado;
    quintupla_t Q;
    FILE *pf = fopen("saida_ER.txt", "w");

    auto2_entrada(&Q, arquivo);

    estados_limite(&Q);

    while(!lista_unitaria(Q.D))
    {
        uniao(&Q.D);

        estado = eliminar_estado(Q);

        concatenacao(&Q.D, estado);
    }
    fprintf(stdout, "%s\n", Q.D->lei);
    fprintf(pf, "%s\n", Q.D->lei);
    fclose(pf);

    return;
}

void auto2_init_entrada_padrao(void)
{
    /* initialization */

    int estado;
    quintupla_t Q;
    FILE *pf = fopen("saida_ER.txt", "w");

    auto2_entrada_padrao(&Q);

    estados_limite(&Q);

    while(!lista_unitaria(Q.D))
    {
        uniao(&Q.D);

        estado = eliminar_estado(Q);

        concatenacao(&Q.D, estado);
    }
    fprintf(stdout, "%s\n", Q.D->lei);
    fprintf(pf, "%s\n", Q.D->lei);
    fclose(pf);

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
 * @copyright Only if not the same as the whole file
 *
 */
int funcexample(int i, int *o, int *z)
{
    IFDEBUG("funcexample()");
    i += *z;
    *o = (*z)++;
    return i - 4;
}


/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

