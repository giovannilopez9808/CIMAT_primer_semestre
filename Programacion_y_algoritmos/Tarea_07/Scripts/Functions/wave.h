#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct WAV_RIFF
{
    /* chunk "riff" */
    //  "RIFF"
    char ChunkID[4];
    // sub-chunk-size
    //  36 + Subchunk2Size
    uint32_t ChunkSize;
    /* sub-chunk-data */
    // "WAVE"
    char Format[4];
} RIFF_t;
typedef struct WAV_FMT
{
    /* sub-chunk "fmt" */
    char Subchunk1ID[4]; /* "fmt " */
    /* sub-chunk-size */
    //  16 for PCM
    uint32_t Subchunk1Size;
    /* sub-chunk-data */
    //  PCM = 1
    uint16_t AudioFormat;
    // Mono = 1, Stereo = 2, etc.
    uint16_t NumChannels;
    // 8000, 44100, etc.
    uint32_t SampleRate;
    // = SampleRate * NumChannels * BitsPerSample/8
    uint32_t ByteRate;
    // NumChannels * BitsPerSample/8
    uint16_t BlockAlign;
    // 8bits, 16bits, etc.
    uint16_t BitsPerSample;
} FMT_t;
typedef struct WAV_data
{
    /* sub-chunk "data" */
    char Subchunk2ID[4]; /* "data" */
    /* sub-chunk-size */
    uint32_t Subchunk2Size; /* data size */
    /* sub-chunk-data */
    //    Data_block_t block;
} Data_t;

typedef struct WAV_fotmat
{
    RIFF_t riff;
    FMT_t fmt;
    Data_t data;
} Wav;
FILE *open_wav(char *filename, char *mode);
void read_wav(FILE *file, Wav *wav);
void print_data(Wav wav);
void write_header(FILE *output, Wav wav);