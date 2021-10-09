#include "Functions/wave.h"
#include "Functions/chaotic_map.h"
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
    // write_header(file_output, wav);
    short *data_original = read_data(file_input, wav);
    short *data = read_data(file_input, wav);
    int num_samples = obtain_num_samples_per_channel(wav);
    // char c;
    for (int i = 0; i < num_samples; i++)
    {
        print_bits(data_original[i]);
        apply_map(&data[i]);
        print_bits(data[i]);
        unsigned char *info = (unsigned char *)&data[i];
        info[0] = info[0] << 2;
        printf("\n");
        // for (int j = 1; j >= 0; j--)
        // {
        // printf("\t");
        // for (int k = (sizeof(unsigned char) * 8 - 1); k >= 0; k--)
        // {
        // c = (info[j] & (1LL << k)) ? '1' : '0';
        // putchar(c);
        // }
        // printf("\n");
        // }
        // print_bits(data[i]);
    }
    (void)data;
    fclose(file_input);
    fclose(file_output);
}
