/* INCLUDES */
#include <time.h>
#include "libpext.h"

/* DEFINES */

#define t = 0.5;

/* FUNÇOES */

Bola *criar_bola(int numero)
{
    Bola *nova_bola = (Bola *)malloc(sizeof(Bola));
    if(nova_bola == NULL)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    nova_bola->numero = numero;
    nova_bola->prox = NULL;

    return nova_bola;
}

Bola *criar_saco_bingo(void)
{
    Bola *saco = NULL;
    for(int i = 1; i <= 99; i++)
    {
        Bola *nova_bola = criar_bola(i);
        nova_bola->prox = saco;
        saco = nova_bola;
    }
    return saco;
}

Bola *sortear_bola(Bola **saco)
{
    int num_bolas = 0;
    Bola *bola = *saco;
    while(bola != NULL)
    {
        num_bolas++;
        bola = bola->prox;
    }

    int bola_sorteada = rand() % num_bolas;

    Bola *bola_anterior = NULL;
    bola = *saco;
    for(int i = 0; i < bola_sorteada; i++)
    {
        bola_anterior = bola;
        bola = bola->prox;
    }

    if(bola_anterior != NULL)
        bola_anterior->prox = bola->prox;
    else
        *saco = bola->prox;

    bola->prox = NULL;
    return bola;
}

void generate_card(int card[SIZE][SIZE])
{
    int used[100] = {0}; // Considerando números de 1 a 99
    int num;

    for(int row = 0; row < SIZE; row++)
    {
        for(int col = 0; col < SIZE; col++)
        {
            do
            {
                num = rand() % 99 + 1;
            }
            while(used[num]);
            used[num] = 1;
            card[row][col] = num;
        }
    }

    // Espaço livre no centro da cartela
    card[SIZE / 2][SIZE / 2] = 0;
}

void print_card(int card[SIZE][SIZE])
{
    double time = 0.999;
    printf("\t    B       I       N       G       O\n");
    printf("\t+-------+-------+-------+-------+-------+\n");
    for(int i = 0; i < SIZE; i++)
    {
        sleep(time);
        for(int j = 0; j < SIZE; j++)
        {
            if(card[i][j] == -1 || card[i][j] == 0)
                printf("\t|   *  ");
            else
                printf("\t|  %2d ", card[i][j]);
        }
        printf("\t|\n");
        printf("\t+-------+-------+-------+-------+-------+\n");
    }
}

int checa_vitoria(int card[SIZE][SIZE])
{
    /* Verifica linhas */
    for(int i = 0; i < SIZE; i++)
    {
        int vitoria = 1;
        for(int j = 0; j < SIZE; j++)
        {
            if(card[i][j] != -1)
            {
                vitoria = 0;
                break;
            }
        }
        if(vitoria) return 1;
    }

    /* Verifica colunas */
    for(int i = 0; i < SIZE; i++)
    {
        int vitoria = 1;
        for(int j = 0; j < SIZE; j++)
        {
            if(card[j][i] != -1)
            {
                vitoria = 0;
                break;
            }
        }
        if(vitoria) return 1;
    }

    /* Verifica diagonais */
    int vitoria = 1;
    for(int i = 0; i < SIZE; i++)
    {
        if(card[i][i] != -1)
        {
            vitoria = 0;
            break;
        }
    }
    if(vitoria) return 1;

    vitoria = 1;
    for(int i = 0; i < SIZE; i++)
    {
        if(card[i][SIZE - i - 1] != -1)
        {
            vitoria = 0;
            break;
        }
    }
    if(vitoria) return 1;

    return 0;
}


void mark_number(int card[SIZE][SIZE], int number)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(card[i][j] == number)
            {
                card[i][j] = -1; // Marca o número sorteado na cartela
                return;
            }
        }
    }
}


int prosseguir(void) {
    char resposta;
    printf("\t~Deseja continuar jogando? (s/n):\n\t");
    scanf(" %c", &resposta);

    if (resposta == 's' || resposta == 'S') {
        return 1;
    } else if (resposta == 'n' || resposta == 'N') {
        printf("\t            .__________________________________.\n");
        printf("\t            |Obrigado por jogar! Até a próxima.|\n");
        printf("\t            °¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨°\n\n");
        return 0;
    } else {
        printf("\t~Desculpe, não entendi a resposta.\n    (Por favor, responda com (s) para sim ou (n) para não.)\n");
        return prosseguir();
    }
}
