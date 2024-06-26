// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    (fread(header, HEADER_SIZE, 1, input));
    (fwrite(header, HEADER_SIZE, 1, output));
    // TODO: Read samples from input file and write updated data to output file
    // defines a sample's size and uses it as a buffer (a sample is 2 bytes)
    int16_t sample_buffer;
    //(make it read samples while there are still samples to be read in the file)
    while (fread(&sample_buffer, sizeof(int16_t), 1, input))
    {
        // multiplies each individual sample by the factor in argv[3] command line and writes it in
        // output
        sample_buffer *= factor;
        fwrite(&sample_buffer, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
