#include "funcoes.h"
#include <cmath>

int random_num(int start, int end)
{
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

bool operator <(const Mochila &m1, const Mochila &m2)
{
    return m1.fitness < m2.fitness;
}
