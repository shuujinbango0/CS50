#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int blocks_size = 512;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    FILE *img = NULL;
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    char* filename =  malloc(8 * sizeof(char));
    int i = 0;
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    uint8_t buffer[blocks_size];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        //if it s the start of a new JPEG
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && (buffer[3] & 240) == 224)
        // Create JPEGs from the data
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", i);
            //write the jpg file with the title "filename"
            img = fopen(filename, "w");
            fwrite(buffer,blocks_size, 1, img);
            i++;
        }
        else
        {
            if (img != NULL)
            {
                fwrite(buffer,blocks_size, 1, img);
            }
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    free(filename);
    return 0;
}
