/* INCLUDES */

#include "libkaiak.h"

/* FUNÇOES */

/* ================================= EX2.C ===============================================================
*
* implementação da função norma, que vai normalizar 2 dados aleatorios numa faixa que vai de 0 a 100 */

float conversao(float x, float minimum1, float maximum1, float minimum2 , float maximum2)
{
    return (x - minimum1) * (maximum2 - minimum2) / (maximum1 - minimum1) + minimum2;
}



/* função da faixa 1 e que retorna os valores depois de postos na formula de conversão*/

float norma (float x, float minimum1, float maximum1)
{
    return conversao(x,  minimum1, maximum1, 0.0, 1.0);
}

/* =============================== FIM DAS FUNÇÕES USADAS NA EX2 ======================================== */



/* =============================== EX3.C ================================================================
 *
 * função para sorteio sem repetição*/
void sortear_sem_repeticao(int numeros_sorteados[NUMERO_DE_SORTEIOS])
{
    int numeros[RANGE_DE_NUMEROS];
    int i, sorteio;

    // inicializar o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    // Preencher o array com números de 1 a 6
    for (i = 0; i < RANGE_DE_NUMEROS; i++)
    {
        numeros[i] = i + 1;
    }

    // fazer os sorteios
    for (i = 0; i < NUMERO_DE_SORTEIOS; i++)
    {
        // escolher um número aleatório não sorteado
        sorteio = rand() % (RANGE_DE_NUMEROS - i);

        // Guardar o número sorteado
        numeros_sorteados[i] = numeros[sorteio];

        // "Remover" o número sorteado da lista
        numeros[sorteio] = numeros[RANGE_DE_NUMEROS - i - 1];
    }
}

/* =========================== FIM DA FUNÇÃO USADA NA EX3 =============================================== */


/* ======================================== EX4.C ======================================================= */

char *concatenar(const char *string1, const char *string2)
{
    // Calcula o comprimento total da nova string
    size_t comprimento_s1 = strlen(string1);
    size_t comprimento_s2 = strlen(string2);
    size_t total_comprimento = comprimento_s1 + comprimento_s2 + 1; // +1 para o caractere nulo

    // Aloca memória para a nova string
    char *concatenada = (char *)malloc(total_comprimento * sizeof(char));
    if (concatenada == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    // Copia s1 para a nova string
    strcpy(concatenada, string1);

    // Concatena s2 à nova string
    strcat(concatenada, string2);

    return concatenada;
}

// Função para verificar se uma string é um prefixo de outra
int ePrefixo(const char *str, const char *prefixo)
{
    int prefixo_comprimento = strlen(prefixo);
    return strncmp(str, prefixo, prefixo_comprimento) == 0;
}

// Função para verificar se uma string é um sufixo de outra
int eSufixo(const char *str, const char *sufixo)
{
    int str_comprimento = strlen(str);
    int sufixo_comprimento = strlen(sufixo);
    return str_comprimento >= sufixo_comprimento && strcmp(str + (str_comprimento - sufixo_comprimento), sufixo) == 0;
}

// Função para verificar se uma string contém uma sub-palavra
int temSubPalavra(const char *str, const char *sub_palavra)
{
    return strstr(str, sub_palavra) != NULL;
}


/* ========================== FIM DAS FUNÇÕES DA EX4.C ===================================== */











