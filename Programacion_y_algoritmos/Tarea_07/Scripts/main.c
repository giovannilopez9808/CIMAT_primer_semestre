#include "Functions/wave.h"
#include <string.h>
int main(int argc, char *argv[])
{
    Wav wav;
    char path_file[50] = "Data/";
    char path_output[50] = "Output/";
    if (argc == 1)
    {
        printf("No se introdujo nombre del archivo\n");
        exit(1);
    }
    strcat(path_file, argv[1]);
    strcat(path_output, argv[1]);
    FILE *file_input = open_wav(path_file, "rb");
    FILE *file_output = open_wav(path_output, "wb");
    read_wav(file_input, &wav);
    print_data(wav);
    //read_data(file_input);
    fclose(file_input);
    fclose(file_output);
}
