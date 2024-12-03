/***************************************************************************
 *   auto3.c                               Version 20210512.104607         *
 *                                                                         *
 *   Convert ER into AFND                                                  *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
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
 * @file auto3.c
 * @ingroup GroupUnique
 * @brief Converte ER para AFND
 * @details diga algo detalhado
 * @version 20160609.110101
 * @date 2016-06-09
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
 *   $gcc auto3.c -o auto3.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1
 * ou preferencialmente use o:
 *   $make
 */

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in auto3.h */

#include "auto3.h" /* To be created for this template if needed */

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
 *    $./auto3 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20210512.104607
 * @date 2016-06-09
 *
 */
int main(int argc, char *argv[])
{
    int opt, cont; /* return from getopt() */
    char sfile[SBUFF];


    /* getopt() configured options:
     *        -h  help
     *        -c  copyright and version
     *        -v  verbose
     *        -f  given file name
     */
    opterr = 0;
    cont = 0;
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
                strcpy(sfile, optarg);
                if(!cont)
                    auto3_init(argv[2]);
                else
                    auto3_init("saida_ER.txt");
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    auto3_init_entrada_padrao();


    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ...and we are done */
    /* Write your code here... */

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
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s v.%s - %s\n", "auto3", VERSION, "Convert ER into AFND");
    printf("\nUsage: %s [-h|-v|-c]\n", "auto3");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\n\nNote (-e): input data is a RE (Regular Expression) string to be converted to a NFA (Nondeterministic Finite Automata) 5-tuple.\n");
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
 * @version 20160609.110101
 * @date 2016-06-09
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "auto3", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
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
/* Inicializacao automato  */
/**
 * @ingroup GroupUnique
 * @brief Funcao que inicializa o programa
 * @details A ser escrito
 * @return Void
 * @todo Necessario criacao das funcoes a serem chamadas
 * @author Ruben Carlo Benante
 * @version 20240628.211428
 * */
void auto3_init(char *insert)
{
    char expReg[SBUFF];
    t_tree *raiz = NULL;

    IFDEBUG("auto3_init()");
    /* initialization */

    insert_ER(expReg, insert);
    quebraExpressao(expReg, &raiz);

    transformacao(raiz);

    printf("\n\nExpressao Regular: %s\nQuintupla: \n\n", expReg);

    salva_quintupla(raiz->Q, NULL);
    salva_quintupla(raiz->Q, "saida_AFND.txt");
    return;
}


/* Entrada padrao*/

void auto3_init_entrada_padrao(void)
{
    char expReg[SBUFF];
    t_tree *raiz = NULL;

    insert_ER_padrao(expReg);
    quebraExpressao(expReg, &raiz);
    transformacao(raiz);

    printf("\n\nExpressao Regular: %s\nQuintupla: \n\n", expReg);
    salva_quintupla(raiz->Q, NULL);
    salva_quintupla(raiz->Q, "saida_AFND.txt");
}

/* ------------------------------------------------------------------ */
/* Iniciando as estruturas iniciais do automato 3 */

/* estrutura para o conjunto 'estados finais' dos automatos */
/* struct final */
/* { */
/* unsigned short int value; /1* inteiro representando o numero de estado(s) final(is) *1/ */
/* struct final *prox; /1* ponteiro guia da lista *1/ */
/* }; */

/* estrutura para o conjunto 'delta' dos automatos */
/* struct delta */
/* { */
/* unsigned short int Ei; /1* inteiro representando o estado inicial da funçao *1/ */
/* char Le; /1* char representando uma letra do alfabeto, argumento da funçao *1/ */
/* unsigned short int Ef; /1* inteiro representando o estado final da funçao *1/ */
/* struct delta *prox; /1* ponteiro guia da lista *1/ */
/* }; */

/* estrutura padrao para automatos (quintupla) */
/* struct automato */
/* { */
/* unsigned short int K; /1* conjunto de estados *1/ */
/* char A; /1* conjunto alfabeto *1/ */
/* unsigned short int S; /1* estado inicial *1/ */
/* struct final *F; /1* conjunto de estados finais *1/ */
/* struct delta *D;  conjunto de funçoes *1/ */
/* }; */

/* int counter = 0; */


/* ------------------------------------------------------------------ */
/* Leitura da expressao regular */

void entrada_padrao(char *expReg)
{
    /* Digite a expressao regular: */
    scanf("%s", expReg);
}

/* funcao a ser chamada para impressao de erro na leitura */
void entrada_nao_reconhecida(void)
{
    printf("Erro ao ler o arquivo especificado\n");
    printf("Verificar se os dados para entrada estao corretos\n");
    exit(-1);
}

/* ------------------------------------------------------------------ */
/* Coleta */

/* Coleta e insere estados finais na lista */
void coleta_final(lest_t **list, FILE *stream)
{
    char ch[SBUFF], *sch;

    fgets(ch, SBUFF, stream); /* Lê uma linha do arquivo de entrada */
    sch = strtok(ch, " "); /* Separa a linha em tokens */

    /* Separa a linha em tokens e insere cada estado na lista */
    do
    {
        insert_estado(list, atoi(sch)); /* Insere cada estado na lista */
    }
    while((sch = strtok(NULL, " ")) != NULL); /* Continua separando a linha em tokens */

    return;
}

/* Coleta e insere transições na lista */
void coleta_transicao(ltrans_t **list, FILE *stream)
{
    char ch[SBUFF], *sei, *slei, *sef;

    while(fgets(ch, SBUFF, stream) != NULL) /* Lê linhas do arquivo de entrada */
    {
        if(strcmp(ch, "\n") == 0) /* Se encontrar uma linha vazia, retorna */
            return;

        /* Separa a linha em tokens para obter os estados de entrada (sei), o símbolo lido (slei) e o estado de destino (sef) */
        sei = strtok(ch, " ");
        slei = strtok(NULL, " ");
        sef = strtok(NULL, " ");

        insert_transicao(list, atoi(sei), slei, atoi(sef)); /* Insere a transição na lista */
    }

    return;
}

/* ------------------------------------------------------------------ */
/* Inserção */

/* Ler e armazerna a ER(expressao regular)*/

void insert_ER(char *expReg, char *insert)
{
    FILE *pf = fopen(insert, "r");  /* Abre o arquivo para leitura */

    fgets(expReg, SBUFF, pf); /* Lê a expressão regular do arquivo e a armazena em expReg */

    return;
}

void insert_ER_padrao(char *expReg)
{
    fgets(expReg, SBUFF, stdin);
    return;
}

/* Insere um estado na lista de estados em ordem crescente, se não estiver presente */
void insert_estado(lest_t **list, int est)
{
    lest_t *pl = *list, *plant = NULL; /* Inicializa os ponteiros para percorrer a lista */

    while(pl != NULL)
    {
        if(pl->estado > est) /* Encontra a posição onde o novo estado deve ser inserido */
            break;
        else
            if(pl->estado == est) /* Se o estado já estiver na lista, não faz nada */
                return;

        plant = pl; /* Avança para o próximo estado */
        pl = pl->prox;
    }
    pl = malloc(sizeof(lest_t)); /* Aloca memória para o novo estado */
    pl->estado = est;
    pl->prox = NULL; /* Inicializa o próximo estado como NULL */

    if(!plant) /* Se a lista estiver vazia ou o novo estado deve ser inserido no início */
    {
        pl->prox = *list; /* O próximo do novo estado será o antigo primeiro estado */
        *list = pl;
    }
    else
    {
        pl->prox = plant->prox; /* O próximo do novo estado será o próximo do estado anterior */
        plant->prox = pl;
    }
    return;
}

/* Insere uma transição na lista de transições */
void insert_transicao(ltrans_t **list, int ei, char *lei, int ef)
{
    ltrans_t *pl = *list, *plant = NULL; /* Inicializa os ponteiros para percorrer a lista */

    while(pl != NULL) /* Percorre a lista de transições até o final */
    {
        plant = pl;
        pl = pl->prox;
    }
    pl = malloc(sizeof(ltrans_t)); /* Aloca memória para a nova transição */
    pl->ei = ei;
    pl->lei = (char *) malloc(strlen(lei) * sizeof(char)); /* Aloca memória para o símbolo lido */
    strcpy(pl->lei, lei);
    pl->ef = ef;
    pl->prox = NULL; /* Inicializa o próximo transição como NULL */

    if(!plant)
        *list = pl; /* Estando vazio a nova transição se torna a primeira da lista */
    else
        plant->prox = pl; /* A nova transição é adicionada ao final da lista */
    return;
}

/* Insere um nó na árvore de expressão regular */
void insert_tree(t_tree **raiz, t_tree *ant, char *info)
{
    t_tree *pl = *raiz; /* Inicializa o ponteiro para percorrer a árvore */

    if(!pl)
    {
        pl = malloc(sizeof(t_tree));
        pl->expReg = malloc(strlen(info) * sizeof(char)); /* Aloca memória para a expressão regular */
        strcpy(pl->expReg, info);
        pl->type_op = type_operador(pl->expReg[0]); /* Define o tipo de operador do nó */
        pl->left = NULL;
        pl->right = NULL;
        pl->pai = ant;
        *raiz = pl; /* Define o novo nó como a raiz da árvore */
        return;
    }
    if(pl->type_op == 0 || pl->right == ant || (pl->type_op == 1 && pl->left == ant))
        insert_tree(&pl->pai, pl, info); /* Insere o novo nó como pai do nó atual */
    else
        if(pl->left == ant)
            insert_tree(&pl->right, pl, info); /* Insere o novo nó como filho direito */
        else
            insert_tree(&pl->left, pl, info); /* Insere o novo nó como filho esquerdo */
    return;
}

void insert_Automato(quintupla_t *Q, const char *insert)
{
    FILE *pf = fopen(insert, "r");
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

void quebraExpressao(char *expReg, t_tree **raiz)
{
    const int nOp = 3; /*numero de operadores*/
    char operadores[3] = { '|', '.', '*'} /*operadores em ordem crescente de prioridade*/,
                         *op = malloc(2 * sizeof(char)) /*operador*/,
                          *partleft, *partright; /*Quebra da expressoes partes left e right*/
    int i, parentese = 0 /*parentese aberto*/;
    size_t j;

    if(!expReg)
        return;
    /*Procurando pelo operador de menor prioridade, sera o ponto de bisseccao da expressao*/
    for(i = 0; i < nOp; i++)
    {
        for(j = 0; j < strlen(expReg); j++) /*expressao escolhida, de baixa prioridade para alta*/
        {
            if(expReg[j] == '(') /* para caso esteja entrando no parentese onde torna a expressao prioritaria*/
                parentese++;
            else
                if(expReg[j] == ')') /* saindo do parentese */
                    parentese--;
                else
                    if(expReg[j] == operadores[i] && parentese == 0)  /* verificando se entrou o operador, caso nao esteja dentro do parentese */
                    {
                        separator(expReg, &partleft, &partright, op, j);

                        insert_tree(raiz, *raiz, op);

                        /* caso foi alcancado uma expressao minima */
                        if(strlen(partleft) == 1)
                            insert_tree(raiz, *raiz, partleft);
                        else
                            quebraExpressao(partleft, raiz);

                        /* caso foi alcancado uma expressao minima */
                        if(strlen(partright) == 1)
                            insert_tree(raiz, *raiz, partright);
                        else
                            quebraExpressao(partright, raiz);

                        return;
                    }
        }
    }
    return;

}

/* ------------------------------------------------------------------ */
/* Conversao */

/* Separa uma expressão regular em duas partes, uma esquerda e outra direita, com base em um operador */
void separator(char *expReg, char **partleft, char **partright, char *op, int size)
{
    char *left, *right; /* Ponteiros para armazenar as partes esquerda e direita */

    left = malloc((size + 1) * sizeof(char));
    right = malloc((strlen(expReg) - size) * sizeof(char));

    strncpy(left, expReg, size); /* Copia os primeiros 'size' caracteres para 'left' */
    left[size] = '\0'; /* Adiciona o caractere nulo ao final de 'left' para formar uma string válida */
    strcpy(right, expReg + size + 1); /* Copia os caracteres após o operador para 'right' */

    *partleft = left;
    *partright = right;

    op[0] = expReg[size]; /* Armazena o operador em 'op' */
    op[1] = '\0'; /* Adiciona o caractere nulo ao final de 'op' para formar uma string válida */

    /* Remove parênteses externos de 'left', se existirem */
    if(*left == '(' && *(left + strlen(left) - 1) == ')')
    {
        left = left + 1;
        left[strlen(left) - 1] = '\0';
    }

    /* Remove parênteses externos de 'right', se existirem */
    if(*right == '(' && right[strlen(right) - 1] == ')')
    {
        right = right + 1; /* Avança para o próximo caractere após o primeiro parêntese de 'right' */
        right[strlen(right) - 1] = '\0'; /* Remove o último parêntese de 'right' */
    }

    return;
}

/* Determina o tipo de operador dado um caractere */
int type_operador(char info)
{
    if(info == '.' || info == '|')
        return 2; /* Retorna 2 para operadores de concatenação ou disjunção */
    if(info == '*')
        return 1; /* Retorna 1 para o operador de estrela de Kleene */
    return 0; /* Retorna 0 se o caractere não for um operador reconhecido */
}

void transformacao(t_tree *raiz)
{
    t_tree *pl = raiz;

    /* parada da recursividade */
    if(!pl)
        return;

    transformacao(pl -> left);
    /* caso o operador seja unario, o operador apenas opera com o ramo leftuerdo (predefinindo a escolha)*/
    if(pl -> type_op == 1)
    {
        operacao_geral(&pl->Q, pl->left->Q, pl->left->Q, pl->expReg[0]);
        return;
    }
    else
        transformacao(pl->right);

    /*operador binario*/
    if(pl->type_op == 2)
    {
        operacao_geral(&pl->Q, pl->left->Q, pl->right->Q, pl->expReg[0]);
        return;
    }

    /*não operador(ER minima)*/
    mini_quintupla(&pl->Q, pl->expReg);
    return;
}

/* Realiza uma operação geral entre duas quintuplas com base em um operador */
void operacao_geral(quintupla_t *res, quintupla_t q1, quintupla_t q2, char op)
{
    switch(op)
    {
        case '.':
            operacao_e(res, q1, q2); /* Chama a função para operação de concatenação */
            break;
        case '|':
            operacao_ou(res, q1, q2); /* Chama a função para operação de disjunção */
            break;
        case '*':
            operacao_estrela(res, q1); /* Chama a função para operação de estrela de Kleene */
            break;
        default:
            printf("\n\nErro!!!, operador nao existe %c\n\n", op);
    }
    return; /* Retorna após realizar a operação desejada */
}

void operacao_e(quintupla_t *res, quintupla_t q1, quintupla_t q2)
{
    res->K = q1.K + q2.K;
    res->A = q1.A > q2.A ? q1.A : q2.A; /* a lei maior prevalece, sendo, a < b < c < d ...  */
    res->S = q1.S; /* estado inicial de q1 prevalece */

    res->F = NULL;
    copia_lestado(&res->F, q2.F); /*os estados finais de q2 prevalece*/

    /*ambas as transitions de q1 e q2 sao mantidas e eh adicionado transitions*/
    res->D = NULL;
    copia_ltrans(&res->D, q1.D);
    copia_ltrans(&res->D, q2.D);

    /*transitions adicionadas sao as que vao unir os finais de q1 com o inicial de q2*/
    transitions_finais(&res->D, q1.F, q2.S);

    return;
}

void operacao_ou(quintupla_t *res, quintupla_t q1, quintupla_t q2)
{
    /*eh adicionado mais dois estados alem dos que ja exitem nas quintuplas q1 e q2*/
    res->K = q1.K + q2.K + 2;
    res->A = q1.A > q2.A ? q1.A : q2.A; /* prevalece o maior alfabeto*/
    res->S = id_state; /*o estado inicial eh um dos novos estados adicionados*/
    char lei[] = "E";

    res->F = NULL;
    insert_estado(&res->F, id_state + 1); /*o estado final eh um dos novos estados adicionados*/

    res->D = NULL;
    /*As transitions de q1 e q2 sao mantidas*/
    copia_ltrans(&res->D, q1.D);
    copia_ltrans(&res->D, q2.D);

    /*o novo estado inicial eh conectado aos antigos estados inicial de q1 e q2*/
    insert_transicao(&res->D, res->S, lei, q1.S);
    insert_transicao(&res->D, res->S, lei, q2.S);

    /*O novo estado final eh conectado com os antigos estados finais de q1 e q2*/
    transitions_finais(&res->D, q1.F, res->F->estado);
    transitions_finais(&res->D, q2.F, res->F->estado);

    /*atualizando os estados totais*/
    id_state += 2;

    return;
}

void operacao_estrela(quintupla_t *res, quintupla_t q)
{
    /* Estados, Alfabeto e Estado Inicial sao mantidos*/

    res->K = q.K;
    res->A = q.A;
    res->S = q.S;

    res->F = NULL;
    /* Estados Finais sao mantidos e o estado inicial passa ser final tambem */
    copia_lestado(&res->F, q.F);
    insert_estado(&res->F, q.S);

    res->D = NULL;
    /* transitions sao mantidas */
    copia_ltrans(&res->D, q.D);
    /* Os finais que se ligam com os iniciais formando a estrela */
    transitions_finais(&res->D, q.F, q.S);
}

/* Cria transições para um novo estado final a partir de uma lista de estados */
void transitions_finais(ltrans_t **dest, lest_t *list, int novoFinal)
{
    lest_t *pl = list; /* Inicializa um ponteiro para percorrer a lista de estados */


    while(pl != NULL)
    {
        insert_transicao(dest, pl->estado, "E", novoFinal); /* Insere uma transição usando cada estado da lista para o novo estado final */
        pl = pl->prox;
    }
    return; /* Retorna após criar todas as transições */
}

/* Copia uma lista de estados para outra lista */
void copia_lestado(lest_t **dest, lest_t *list)
{
    while(list != NULL) /* Percorre a lista original de estados */
    {
        insert_estado(dest, list->estado); /* Insere cada estado na lista de destino */
        list = list->prox; /* Avança para o próximo estado na lista original */
    }
    return;
}

/* Copia uma lista de transições para outra lista */
void copia_ltrans(ltrans_t **dest, ltrans_t *list)
{
    while(list != NULL) /* Percorre a lista original de transições */
    {
        insert_transicao(dest, list->ei, list->lei, list->ef); /* Insere cada transição na lista de destino */
        list = list->prox; /* Avança para a próxima transição na lista original */
    }

    return; /* Retorna após copiar todas as transições */
}

/* Inicializa uma quíntupla com uma transição simples baseada no símbolo lido (lei) */
void mini_quintupla(quintupla_t *q, char *lei)
{
    q->K = 2;
    q->A = lei[0]; /* Define o alfabeto como o primeiro caractere de lei */
    q->S = id_state;
    q->F = NULL;
    insert_estado(&q->F, id_state + 1); /* Insere o estado final na lista de estados finais */
    q->D = NULL;
    insert_transicao(&q->D, id_state, lei, id_state + 1);
    id_state += 2; /* Incrementa o id_state em 2 para os próximos estados */
    return;
}

/* ------------------------------------------------------------------ */
/* busca e localização */

/* buscas específicas em listas de elementos relacionados */

lconj_t *busca_conjunto(lconj_t *list, int id)
{
    lconj_t *pl = list;

    while(pl != NULL)
    {
        if(pl->id == id) /* Se o conjunto tem o id igual ao parâmetro, retorna o conjunto */
            return pl;
        pl = pl->prox;
    }

    return NULL;
}

/* busca uma transição na lista por estado inicial e símbolo de entrada */

ltrans_t *busca_transicao(ltrans_t *list, int ei, char *lei)
{
    ltrans_t *pl = list;

    while(pl != NULL) /* Percorre a lista de transições */
    {
        if(pl->ei == ei && strcmp(pl->lei, lei) == 0) /* Se transição tem estado inicial e símbolo igual aos parâmetros, return a transição */
            return pl;
        pl = pl->prox;
    }

    return NULL; /* Se não encontrar nenhuma transição com o estado inicial e símbolo lido especificados, retorna NULL */
}

/* estado inicial (ei) e estado final (ef). */

ltrans_t *busca_transicao_lei(ltrans_t *list, int ei, int ef)
{
    ltrans_t *pl = list;

    while(pl != NULL)
    {
        if(pl->ei == ei && pl->ef == ef) /* Se a transição tem o estado inicial e final igual aos parâmetros, retorna a transição */
            return pl;
        pl = pl->prox;
    }

    return NULL; /* Se não encontrar nenhuma transição com o estado inicial e final especificados, retorna NULL */
}

ltrans_t *busca_simultaneo(ltrans_t *list, int ref)
{
    /* Chama a função busca_transicao para procurar uma transição com o estado inicial igual a ref e símbolo de entrada "E" */
    return busca_transicao(list, ref, "E");
}

/* Procura a primeira transição na lista que tenha o estado inicial igual a est */
ltrans_t *busca_por_ei(ltrans_t *list, int est)
{
    ltrans_t *pl = list;

    while(pl != NULL) /* Percorre a lista de transições */
    {
        if(pl->ei == est) /* Se a transição tem o estado inicial igual a est, retorna a transição */
            return pl;
        pl = pl->prox;
    }
    return NULL;
}

/* Procura a primeira transição na lista que tenha o estado final igual a est */
ltrans_t *busca_por_ef(ltrans_t *list, int est)
{
    ltrans_t *pl = list;

    while(pl != NULL) /* Percorre a lista de transições */
    {
        if(pl->ef == est) /* Se a transição tem o estado final igual a est, retorna a transição */
            return pl;
        pl = pl->prox;
    }

    return NULL; /* Se não encontrar nenhuma transição com o estado final igual a est, retorna NULL */
}
/* ------------------------------------------------------------------ */
/* Impressao */


/* ------------------------------------------------------------------ */
/* Limpeza de dados */
void remove_estado(lest_t **list, lest_t *r)
{
    /* Inicializa o ponteiro para percorrer a lista e um ponteiro anterior */
    lest_t *pl = *list, *plant = NULL;

    while(pl != NULL)
    {
        if(pl == r) /* Encontra o elemento a ser removido e sai do loop */
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl) /* Se não encontrar o elemento, retorna */
        return;

    if(!plant) /* Se o elemento a ser removido é o primeiro da lista */
        *list = pl->prox;
    else
        plant->prox = pl->prox;

    free(pl); /* Libera a memória do elemento removido */
    return;
}

void remove_transicao(ltrans_t **list, ltrans_t *r)
{
    /* Inicializa os ponteiros para percorrer a lista */
    ltrans_t *pl = *list, *plant = NULL;

    /* Percorre a lista até encontrar o elemento a ser removido ou atingir o final da lista */
    while(pl != NULL)
    {
        if(pl == r) /* Se o elemento atual for o que queremos remover, saímos do loop */
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl) /* Se não encontrar o elemento, simplesmente retorna */
        return;

    if(!plant) /* Se o elemento a ser removido é o primeiro da lista */
        *list = pl->prox;
    else
        plant->prox = pl->prox;

    free(pl); /* Libera a memória do elemento removido */
    return;
}

void remove_conjunto(lconj_t **list, lconj_t *r)
{
    /* Inicializa os ponteiros para percorrer a lista */
    lconj_t *pl = *list, *plant = NULL;

    while(pl != NULL) /* Percorre a lista até encontrar o elemento a ser removido ou atingir o final da lista */
    {
        if(pl == r) /* Se o elemento atual for o que queremos remover, saímos do loop */
            break;
        plant = pl;
        pl = pl->prox;
    }

    if(!pl) /* Se não encontramos o elemento, simplesmente retornamos */
        return;

    if(!plant) /* Se o elemento a ser removido é o primeiro da lista */
        *list = pl->prox;
    else
        plant->prox = pl->prox;

    free(pl); /* Libera a memória do elemento removido */
    return;
}

/* apaga toda um lista de estados */
void apaga_estados(lest_t **list)
{
    lest_t *pl = *list;

    while(pl != NULL)
    {
        remove_estado(list, pl); /* Remove o estado da lista. */
        pl = *list;
    }
    return;
}

/* apaga toda uma lista de transitions */
void apaga_transicao(ltrans_t **list)
{
    ltrans_t *pl = *list;

    while(pl != NULL)
    {
        remove_transicao(list, pl); /* Remove a transição da lista. */
        pl = *list;
    }
}

/* Funcao que apaga conjuntos não utilizados */
void apaga_conjunto(lconj_t **list)
{
    lconj_t *pl = *list;

    while(pl != NULL)
    {
        apaga_estados(&pl->estados); /* Apaga os estados do conjunto. */
        remove_conjunto(list, pl); /* Remove o conjunto da lista. */
        pl = *list;
    }

    return;
}

/* ------------------------------------------------------------------ */
/* Operadores */


/* ------------------------------------------------------------------ */
/* Saida */

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

/* imprime uma lista de transições */

void imprime_transicao(ltrans_t *list, FILE *stream)
{
    ltrans_t *pl = list;

    while(pl != NULL) /* Percorre a lista de transições */
    {
        /* Imprime o estado inicial, o símbolo lido e o estado final */
        fprintf(stream, "%d %s %d\n", pl->ei, pl->lei, pl->ef);
        pl = pl->prox; /* Avança para a próxima transição */
    }
    return;
}

/* imprime uma lista de estados */
void imprime_estados(lest_t *list, FILE *stream)
{
    lest_t *pl = list;

    if(pl != NULL) /* Se a lista não está vazia, imprime o primeiro estado */
    {
        fprintf(stream, "%d", pl->estado);
        pl = pl->prox; /* Avança para o próximo estado */
    }

    while(pl != NULL) /* Percorre a lista imprimindo os estados restantes */
    {
        fprintf(stream, " %d", pl->estado);
        pl = pl->prox;
    }
    fprintf(stream, "\n"); /* Imprime uma nova linha após a lista de estados */
    return;
}

/* imprime os trees em preordem */
void imprime_tree(t_tree *raiz, FILE *stream)
{
    t_tree *pl = raiz;

    if(!pl) /* Se a árvore está vazia, retorna */
        return;

    imprime_tree(pl->left, stream); /* Imprime a sub-arvore esquerda */
    imprime_tree(pl->right, stream); /* Imprime a sub-arvore direita */

    printf("\n");
    if(pl->type_op == 2) /* Se o nó é um operador binário, imprime com os operadores esquerdo e direito */
        fprintf(stream, "(%s)%s(%s)\n", pl->left->expReg, pl->expReg, pl->right->expReg);
    else
        if(pl->type_op == 1) /* Se o nó é um operador unário, imprime com o operador esquerdo */
            fprintf(stream, "(%s)%s\n", pl->left->expReg, pl->expReg);
        else /* Se o nó é um operando, imprime o valor do nó */
            fprintf(stream, "%s\n", pl->expReg);

    salva_quintupla(pl->Q, NULL);
    getchar(); /* Pausa para interação */
    printf("\n");

    return;
}


int funcexample(int i, int *o, int *z)
{
    /* Incrementa o valor de i pelo conteúdo apontado por z. */
    IFDEBUG("funcexample()");
    i += *z;
    *o = (*z)++;
    /* Retorna o resultado da operação (i - 4). */
    return i - 4;
}


/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

