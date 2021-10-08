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
    strcat(path_file,
           argv[1]);
    strcat(path_output,
           argv[1]);
    read_wav(path_file,
             &wav);
    print_data(wav);
    FILE *output = fopen(path_output, "wb");
    write_header(output,
                 wav);
}
