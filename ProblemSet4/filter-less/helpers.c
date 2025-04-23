#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green and blue
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float grayscale = (red + green + blue) / 3.0;

            // Update pixel value
            image[i][j].rgbtRed = round(grayscale);
            image[i][j].rgbtGreen = round(grayscale);
            image[i][j].rgbtBlue = round(grayscale);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take the RGB for the image
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // Check that the values are not above 255
            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;
            if (sepiaGreen > 255)
                sepiaGreen = 255;

            // Update pixel value
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of the original image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loop through each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_total = 0;
            int green_total = 0;
            int blue_total = 0;
            int count = 0;

            // Loop through grid around the pixel
            for (int pre_row = -1; pre_row <= 1; pre_row++)
            {
                for (int pre_col = -1; pre_col <= 1; pre_col++)
                {
                    int next_row = i + pre_row;
                    int next_col = j + pre_col;

                    // Check if surrounding pixel is within image bounds
                    if (next_row >= 0 && next_row < height && next_col >= 0 && next_col < width)
                    {
                        red_total += copy[next_row][next_col].rgbtRed;
                        green_total += copy[next_row][next_col].rgbtGreen;
                        blue_total += copy[next_row][next_col].rgbtBlue;
                        count++;
                    }
                }
            }

            // Set the blurred pixel value to the average
            image[i][j].rgbtRed = round((float)red_total / count);
            image[i][j].rgbtGreen = round((float)green_total / count);
            image[i][j].rgbtBlue = round((float)blue_total / count);
        }
    }

    return;
}
