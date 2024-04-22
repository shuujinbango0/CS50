#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((image[i][j].rgbtBlue * 0.189) + (image[i][j].rgbtGreen * 0.769) +
                                 (image[i][j].rgbtRed * 0.393));
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            int sepiaGreen = round((image[i][j].rgbtBlue * 0.168) +
                                   (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtRed * 0.349));
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            int sepiaBlue = round((image[i][j].rgbtBlue * 0.131) + (image[i][j].rgbtGreen * 0.534) +
                                  (image[i][j].rgbtRed * 0.272));
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Sumred = 0, Sumgreen = 0, Sumblue = 0, pixelcounter = 0.0;
            for (int i_checksum = i - 1; i_checksum < i + 2; i_checksum++)
            {
                for (int j_checksum = j - 1; j_checksum < j + 2; j_checksum++)
                {
                    if (i_checksum >= 0 && j_checksum >= 0 && i_checksum < height &&
                        j_checksum < width)
                    {
                        Sumred += image[i_checksum][j_checksum].rgbtRed;
                        Sumgreen += image[i_checksum][j_checksum].rgbtGreen;
                        Sumblue += image[i_checksum][j_checksum].rgbtBlue;
                        ++pixelcounter;
                    }
                }
            }
            copy[i][j].rgbtRed = round(Sumred / pixelcounter);
            copy[i][j].rgbtGreen = round(Sumgreen / pixelcounter);
            copy[i][j].rgbtBlue = round(Sumblue / pixelcounter);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
