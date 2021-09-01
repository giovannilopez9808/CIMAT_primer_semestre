void merge(int numbers1[], int size1, int numbers2[], int size2, int result[])
{
    /* 
    Realiza la union de los dos numeros 
     */
    // Contador para numbers1
    int i = 0;
    // Contador para numbers2
    int j = 0;
    // Contador para result
    int k = 0;
    // Se repetira el ciclo hasta que los dos numeros hayan llegado a su tope
    while (i < size1 || j < size2)
    {
        // Si numbers1 es menor a numbers2 este se posicionara primero en result
        if (numbers1[i] < numbers2[j])
        {
            // Si numbers1 no ha llegado a su tope entonces se posiciona en result
            if (i < size1)
            {
                result[k] = numbers1[i];
                i++;
            }
            // Si llego a tu tope entonces numbers2 se posiciona
            else
            {
                result[k] = numbers2[j];
                j++;
            }
        }
        else
        {
            // Si numbers2 no ha llegado a su tope entonces se posiciona en result
            if (j < size2)
            {

                result[k] = numbers2[j];
                j++;
            }
            // Si llego a tu tope entonces numbers1 se posiciona
            else
            {
                result[k] = numbers1[i];
                i++;
            }
        }
        k++;
    }
}