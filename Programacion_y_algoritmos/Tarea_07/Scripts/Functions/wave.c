#include "wave.h"
/* 
Apertura del archivo wav y validacion de su apertura
 */
FILE *open_wav(char *filename, char *mode)
{
       FILE *file = fopen(filename, mode);
       if (!file)
       {
              printf("can't open audio file\n");
              exit(1);
       }
       return file;
}
/* 
Lectura del header del wav
 */
void read_wav(FILE *file, Wav *wav)
{
       fread(wav, 1, sizeof(*wav), file);
}
/* 
Impresion del header del archivo wav
 */
void print_data(Wav wav)
{
       RIFF_t riff = wav.riff;
       FMT_t fmt = wav.fmt;
       Data_t data = wav.data;
       printf("ChunkID \t%c%c%c%c\n",
              riff.ChunkID[0],
              riff.ChunkID[1],
              riff.ChunkID[2],
              riff.ChunkID[3]);
       printf("ChunkSize \t%d\n",
              riff.ChunkSize);
       printf("Format \t\t%c%c%c%c\n\n",
              riff.Format[0],
              riff.Format[1],
              riff.Format[2],
              riff.Format[3]);
       printf("Subchunk1ID \t%c%c%c%c\n",
              fmt.Subchunk1ID[0],
              fmt.Subchunk1ID[1],
              fmt.Subchunk1ID[2],
              fmt.Subchunk1ID[3]);
       printf("Subchunk1Size \t%d\n",
              fmt.Subchunk1Size);
       printf("AudioFormat \t%d\n",
              fmt.AudioFormat);
       printf("NumChannels \t%d\n",
              fmt.NumChannels);
       printf("SampleRate \t%d\n",
              fmt.SampleRate);
       printf("ByteRate \t%d\n",
              fmt.ByteRate);
       printf("BlockAlign \t%d\n",
              fmt.BlockAlign);
       printf("BitsPerSample \t%d\n\n",
              fmt.BitsPerSample);
       printf("blockID \t%c%c%c%c\n",
              data.Subchunk2ID[0],
              data.Subchunk2ID[1],
              data.Subchunk2ID[2],
              data.Subchunk2ID[3]);
       printf("blockSize \t%d\n\n",
              data.Subchunk2Size);
       printf("duration \t%d\n",
              data.Subchunk2Size / fmt.ByteRate);
}
/* 
Escritura de los datos del wav en un archivo
 */
void write_data(short *data, Wav wav, FILE *file)
{
       int num_samples = obtain_num_samples_per_channel(wav);
       fwrite(data,
              sizeof(short),
              num_samples * wav.fmt.NumChannels,
              file);
}
/* 
Escritura del header y datos del archivo wav
 */
void write_file(FILE *output, Wav wav, short *data)
{
       RIFF_t riff = wav.riff;
       FMT_t fmt = wav.fmt;
       Data_t data_wav = wav.data;
       fwrite(riff.ChunkID, 4, 1, output);
       fwrite(&riff.ChunkSize, 4, 1, output);
       fwrite(riff.Format, 4, 1, output);
       fwrite(fmt.Subchunk1ID, 4, 1, output);
       fwrite(&fmt.Subchunk1Size, 4, 1, output);
       fwrite(&fmt.AudioFormat, 2, 1, output);
       fwrite(&fmt.NumChannels, 2, 1, output);
       fwrite(&fmt.SampleRate, 4, 1, output);
       fwrite(&fmt.ByteRate, 4, 1, output);
       fwrite(&fmt.BlockAlign, 2, 1, output);
       fwrite(&fmt.BitsPerSample, 2, 1, output);
       fwrite(data_wav.Subchunk2ID, 4, 1, output);
       fwrite(&data_wav.Subchunk2Size, 4, 1, output);
       write_data(data, wav, output);
}
/* 
Calcula el numero de particiones del archivo wav
 */
int obtain_num_samples_per_channel(Wav wav)
{
       // Numero de canales
       int num_channels = wav.fmt.NumChannels;
       // Numeros de bytes pos cada particion
       int bytes_per_sample = (int)wav.fmt.BitsPerSample / 8;
       // Obtiene el tamaño del archivo
       int data_size = wav.data.Subchunk2Size;
       int num_samples_per_channel = data_size / bytes_per_sample /
                                     num_channels;
       return num_samples_per_channel;
}
/* 
Lectura de los datos del archivo wav en un arreglo de short int
 */
short *read_data(FILE *file, Wav wav)
{
       // Numero de particiones del archivo wav
       int num_samples_per_channel = obtain_num_samples_per_channel(wav);
       // Bytes por particion
       int bytes_per_sample = (int)wav.fmt.BitsPerSample / 8;
       // Numero de canales
       int num_channels = wav.fmt.NumChannels;
       // Inicializacion del arreglo
       short *data = (short *)malloc(num_samples_per_channel * num_channels * sizeof(short));
       short *dp = data;
       for (int i = 0; i < num_samples_per_channel; i++)
       {
              for (int j = 0; j < num_channels; j++)
              {
                     //  Lectura de los datos
                     if (fread(dp, bytes_per_sample, 1, file) != 1)
                     {
                            fprintf(stderr, "Error: No se pudieron leer todas las particiones\n");
                            exit(6);
                     }
                     dp++;
              }
       }
       return data;
}
