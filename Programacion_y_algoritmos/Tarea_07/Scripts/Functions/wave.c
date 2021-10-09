#include "wave.h"
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
void read_wav(FILE *file, Wav *wav)
{
    short int data;
    fread(wav, 1, sizeof(*wav), file);
    fread(&data, 1, sizeof(data), file);
    fread(&data, 1, sizeof(data), file);
    printf("%d\n", data);
}
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
void write_header(FILE *output, Wav wav)
{
    RIFF_t riff = wav.riff;
    FMT_t fmt = wav.fmt;
    Data_t data = wav.data;
    unsigned long int value;
    short int s;
    double t;
    char c;
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
    fwrite(data.Subchunk2ID, 4, 1, output);
    fwrite(&data.Subchunk2Size, 4, 1, output);
    for (int i = 0; i < 90000; i++)
    {
        t = 1.0 / 9000.0 * i;
        s = (short int)(sin(2.0 * 3.141592 * 400.0 * t) * 32767.0);
        value =s;
        unsigned char *info=(unsigned char*)&value;
        (void)info;
        for(int i=(sizeof(unsigned long int)*8-1); i>=0; i--)
        {
            c=(value&(1LL<<i))? '1': '0';
            putchar(c);
        }
        printf("\n");
        for(int i=7; i>=0; i--)
        {
            printf("\t");
            for(int j=(sizeof(unsigned char)*8-1); j>=0; j--)
            {
                c=(info[i]&(1LL<<j))? '1': '0';
                putchar(c);
            }
            printf("\n");
        }
        printf("\n");
        fwrite(&s, 2, 1, output);
    }
}
