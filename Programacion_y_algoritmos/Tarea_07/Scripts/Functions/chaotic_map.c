#include "chaotic_map.h"
void apply_map(short int *data)
{
    *data = *data + (*data >> m);
}