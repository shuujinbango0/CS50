#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("error please input only one command argument");
        return 1;
    }
    // Open the memory card
    FILE* cardptr = fopen(argv[1], "r");
    if (cardptr == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    unsigned char buffer[512];
    char filename[8];
    int file_number = 0;
// Q::Q IMPORTANT: POINTER DECLARATION : always declare a pointer as NULL if it s not initialized
// AND declared (with FILE* fopen for instance) to avoid nasty hackers exploiting segmentation faults or the compiler grief.
// IMPORTANT : FWRITE() : the fwrite function in your code will append to the existing file pointed to by recoverptr.
// Each time you call fwrite, it writes the data to the current position of the file pointer,
// then moves the file pointer forward by the amount of data written.
// So, subsequent calls to fwrite will append to the file, unless you manually move the file pointer
// using a function like fseek.
// IMPORTANT POINT : SPRINTF(): will store a string for use in a buffer space, it s useful to format
// an integer to a string, great here to automatically create files with numbered file names. Q::Q
    FILE *recoverptr = NULL;

     while (fread(buffer, 1, 512, cardptr) == 512)
     {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
        &&  buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            if (recoverptr != NULL)
            {
                fclose(recoverptr);
            }
            sprintf(filename, "%03d.jpg", file_number);
            recoverptr = fopen(filename, "w");
            if (recoverptr == NULL)
            {
                return 1;
            }
            file_number ++;
            fwrite(buffer, 1 , sizeof(buffer), recoverptr);
        }
        else if (recoverptr != NULL)
        {
            fwrite(buffer, 1 , sizeof(buffer), recoverptr);
        }
    }
    // Close any open file pointers
    if (recoverptr != NULL)
    {
        fclose(recoverptr);
    }
    fclose(cardptr);
}
