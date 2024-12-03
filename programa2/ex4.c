#include "libkaiak.c"

int main (void)
{
    const char *str = "prefixo";
    const char *prefixo = "pre";
    const char *sufixo = "ixo";
    const char *sub_palavra = "fix";
    const char *s1 = "Hello, ";
    const char *s2 = "world!";

    // Testando as funções
    if (ePrefixo(str, prefixo))
        printf("\"%s\" é um prefixo de \"%s\".\n", prefixo, str);
    else
        printf("\"%s\" não é um prefixo de \"%s\".\n", prefixo, str);

    if (eSufixo(str, sufixo))
        printf("\"%s\" é um sufixo de \"%s\".\n", sufixo, str);
    else
        printf("\"%s\" não é um sufixo de \"%s\".\n", sufixo, str);

    if (temSubPalavra(str, sub_palavra))
        printf("\"%s\" é uma sub-palavra de \"%s\".\n", sub_palavra, str);
    else
        printf("\"%s\" não é uma sub-palavra de \"%s\".\n", sub_palavra, str);

    char *concatenada = concatenar(s1, s2);
    printf("Strings concatenadas: %s\n", concatenada);
    free(concatenada);

    return 0;
}
