// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        int Sumred = 0;
        int Sumgreen = 0;
        int Sumblue = 0;
        if
        }
    }
    return;
    // Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
            //top left corner
            if (i == 0 && j == 0)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                        copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                       4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                         copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                        4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                       copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                                      4.0);
            }
            //top right corner
            if (i == 0 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                        copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                       4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                         copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                        4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
                                       copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                                      4.0);
            }
            //top middle row
            if (i == 0 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                        copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue +
                                        copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                       6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                         copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                         copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                        6.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed +
                                       copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed +
                                       copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                                      6.0);
            }
            if (i > 0 && i < height - 1 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtBlue =
                    round((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue + copy[i][j - 1].rgbtBlue +
                     copy[i + 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue +
                     copy[i + 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                     copy[i][j + 1].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                    9.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                         copy[i][j - 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                         copy[i - 1][j].rgbtGreen + copy[i + 1][j].rgbtGreen +
                                         copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                         copy[i + 1][j + 1].rgbtGreen) /
                                        9.0);
                image[i][j].rgbtRed =
                    round((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i][j - 1].rgbtRed +
                     copy[i + 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i + 1][j].rgbtRed +
                     copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed +
                     copy[i + 1][j + 1].rgbtRed) /
                    9.0);
            }
            if (i == height - 1 && j == 0)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue +
                                        copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue) /
                                       4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen +
                                         copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                                        4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed +
                                       copy[i - 1][j + 1].rgbtRed + copy[i][j + 1].rgbtRed) /
                                      4.0);
            }
            if (i == height - 1 && j > 0 && j < width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                        copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                                        copy[i][j - 1].rgbtBlue + copy[i][j + 1].rgbtBlue) /
                                       6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                         copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                         copy[i][j - 1].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                                        6.0);
                image[i][j].rgbtRed =
                    round((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed +
                     copy[i - 1][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j + 1].rgbtRed) /
                    6.0);
            }
            if (i == height - 1 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                        copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue) /
                                       4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                         copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen) /
                                        4.0);
                image[i][j].rgbtRed = round((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                       copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed) /
                                      4.0);
            }
            if (i > 0 && i < height - 1 && j == 0)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j].rgbtBlue +
                                        copy[i - 1][j + 1].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                        copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                       6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j].rgbtGreen +
                                         copy[i - 1][j + 1].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                         copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                        6.0);
                image[i][j].rgbtRed =
                    round((copy[i][j].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                     copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                    6.0);
            }
            if (i > 0 && i < height - 1 && j == width - 1)
            {
                image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                        copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                        copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                       6.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                         copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                         copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                        6.0);
                image[i][j].rgbtRed =
                    round((copy[i][j].rgbtRed + copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed +
                     copy[i][j - 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                    6.0);
            }
        }
    }
    return;
}
}
