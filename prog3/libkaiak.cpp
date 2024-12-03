#include "libkaiak.hpp"

/* ==================================== EX3.C =========================================== */

       double normalizacao::normalizar(double x, double minimum1, double maximum1)
        {
            if (maximum1 <= minimum1)
            {
                std::cerr << "Erro: maximum1 deve ser maior que minimum1." << std::endl;
                return std::numeric_limits<double>::quiet_NaN(); // Retorna NaN em caso de erro
            }

            if (x < minimum1 || x > maximum1)
            {
                std::cerr << "Erro: x está fora do intervalo." << std::endl;
                return std::numeric_limits<double>::quiet_NaN();
            }

            return (x - minimum1) / (maximum1 - minimum1);
        }

/* ============================================================================================ */


/* ================================== EX4.C ==================================================== */

SorteioSemRepeticao::SorteioSemRepeticao(int maximo)
{
    for (int i = 1; i <= maximo; ++i)
    {
        numeros.push_back(i);
    }
}

int SorteioSemRepeticao::sortear()
{
    if (numeros.empty())
    {
        return -1; // Ou lançar uma exceção
    }
    int indice = rand() % numeros.size();
    int numeroSorteado = numeros[indice];
    numeros.erase(numeros.begin() + indice);
    return numeroSorteado;
}


