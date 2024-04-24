#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
// Q::Q Iterate over every row and column of the image and make it grayscale,
// here the 2D array 'image' of type RGBTRIPLE doesn t need to be declared anywhere since it is declared
// in the function definition just like a regular variable Q::Q
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
// Q::Q column for i, j for row Q::Q
    for(int i = 0; i < height; i ++)
    {
        for(int j = 0; j < width; j ++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
// Q::Q column for i, j for row Q::Q
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
// Q::Q first step: iterate over every pixel and save the original values in a new array
// second step : make the average of the surrounding pixel excluding pixel values outside the image
// if current pic is [n][m] i need to go from n&m - 3 to + 3
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float pixelsum = 0.0;
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            for (int n = i - 1; n <= i + 1; n++)
            {
               for (int m = j - 1; m <= j + 1; m++)
               {
                    if (n >= 0 && m >= 0 && n < height && m < width)
                    {
                        pixelsum ++;
                        sumBlue += original[n][m].rgbtBlue;
                        sumGreen += original[n][m].rgbtGreen;
                        sumRed += original[n][m].rgbtRed;
                    }
                }
            }
            image[i][j].rgbtBlue = round(sumBlue/pixelsum);
            image[i][j].rgbtGreen = round(sumGreen/pixelsum);
            image[i][j].rgbtRed = round(sumRed/pixelsum);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    int GxKernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GyKernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float XsumBlue = 0;
            float XsumGreen = 0;
            float XsumRed = 0;
            float YsumBlue = 0;
            float YsumGreen = 0;
            float YsumRed = 0;
            for (int n = - 1; n <= 1; n++)
            {
               for (int m = - 1; m <= 1 ; m++)
               {
                    int ni = i + n;
                    int mj = j + m;
// Q::Q IMPORTANT MISTAKE : BLURRY EYED COPY PASTE I had n and m set to >= 0 !!( n >= 0 && m >= 0 etc...)!!
// I had my biggest issues on this problem because of copy pasting the same limits from one for loop to the other.
// Always double check when copy pasting from one loop to the next Q::Q
                    if ( ni >= 0 && mj >= 0 && ni < height && mj < width)
                    {
                        XsumBlue += original[ni][mj].rgbtBlue * GxKernel[n + 1][m + 1];
                        XsumGreen += original[ni][mj].rgbtGreen * GxKernel[n + 1][m + 1];
                        XsumRed += original[ni][mj].rgbtRed * GxKernel[n + 1][m + 1];

                        YsumBlue += original[ni][mj].rgbtBlue * GyKernel[n + 1][m + 1];
                        YsumGreen += original[ni][mj].rgbtGreen * GyKernel[n + 1][m + 1];
                        YsumRed += original[ni][mj].rgbtRed * GyKernel[n + 1][m + 1];
                    }
                }
            }
            int BlueXY = round(sqrt(pow(XsumBlue, 2)+pow(YsumBlue, 2)));
            int GreenXY = round(sqrt(pow(XsumGreen, 2)+pow(YsumGreen, 2)));
            int RedXY = round(sqrt(pow(XsumRed, 2)+pow(YsumRed, 2)));
// Q::Q here new syntax: ternary conditional operator co
// " condition ? value_if_true : value_if_false "
// Here condition : BlueXY > 255 ? 255 : BlueXY
// alternative is:" if (condition) {value_if_true} else {value_if_false} "
// example alternative: if (BlueXY > 255) {rgbt.. = 255} else {rgbt.. = BlueXY}"
// Q::Q
            image[i][j].rgbtBlue = BlueXY > 255 ? 255 : BlueXY;
            image[i][j].rgbtGreen = GreenXY > 255 ? 255 : GreenXY;
            image[i][j].rgbtRed = RedXY > 255 ? 255 : RedXY;
        }
    }
    return;
}
