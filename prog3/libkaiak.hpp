// libkaiak.hpp


/* =============== defines =================== */
#ifndef libkaiak_h
#define libkaiak_h
/* ============== fim dos defines ============ */

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

/* ======================== fim das includes =========================== */


/* ================================= Prototipos de função ========================================= */

class normalizacao
{
public:
    static double normalizar(double x, double minimum1, double maximum1);
}; /* função para normalização de numeros */


class SorteioSemRepeticao
{
public:
    SorteioSemRepeticao(int maximo);
    int sortear();
private:
    std::vector <int> numeros;
}; /*funções para o sorteio sem repetição*/


#endif
