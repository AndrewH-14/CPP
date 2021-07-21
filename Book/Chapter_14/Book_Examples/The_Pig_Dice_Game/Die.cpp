#include <cstdlib>
#include <ctime>
#include "Die.h"

Die::Die() 
{
    srand(time(NULL));    // seed the rand() function
    value = 1;
}

void Die::roll() 
{
    value = rand() % 6;   // value is >= 0 and <= 5
    ++value;              // value is >= 1 and <= 6
}

int Die::getValue() 
{
    return value;
}