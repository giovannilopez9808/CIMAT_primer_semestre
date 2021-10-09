#include "chaotic_map.h"
#define CHAOTIC_MAP_H
#define epsilon 414523
#define m 3
#define b 3134
short int keys[2] = {5221, 3622};
/* 
Aplica la red de mapas caoticos a los datos del wav
 */
void apply_map(short int **data, Wav wav)
{
    // Obtiene el numero total de bytes
    int num_samples = obtain_num_samples_per_channel(wav);
    // Inicializacion del key
    short int values[2] = {keys[0], keys[1]};
    short int H;
    // Corrido de todos los valores del wav
    for (int i = 0; i < num_samples; i++)
    {
        // Separación de los bytes
        unsigned char *info = (unsigned char *)(*data + i);
        // Calculo de la funcion H
        H = epsilon & (values[0] ^ values[1]);
        for (int j = 0; j < 2; j++)
        {
            // Aplicacion del mapa a los datos
            info[j] = info[j] ^ values[j];
            // Nuevo key
            values[j] = b * values[j] + (values[j] >> m) + H;
        }
    }
}
