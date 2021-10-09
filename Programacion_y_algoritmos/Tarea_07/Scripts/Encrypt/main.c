#include "../Functions/chaotic_map.h"
#include <string.h>
int main(int argc, char *argv[])
{
    Wav wav;
    char path_file[50] = "../Data/Original/";
    char path_output[50] = "../Data/Encrypt/";
    if (argc == 1)
    {
        printf("No se introdujo nombre del archivo\n");
        exit(1);
    }
    strcat(path_file, argv[1]);
    strcat(path_output, argv[1]);
    printf("%s\n", path_output);
    FILE *file_input = open_wav(path_file, "rb");
    FILE *file_output = open_wav(path_output, "wb");
    read_wav(file_input, &wav);
    print_data(wav);
    short *data_original = read_data(file_input, wav);
    short *data = read_data(file_input, wav);
    apply_map(&data, wav);
    write_file(file_output, wav, data);
    free(data);
    free(data_original);
    fclose(file_input);
    fclose(file_output);
}
