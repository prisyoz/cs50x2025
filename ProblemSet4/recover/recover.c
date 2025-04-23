#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Accept a single argument
    if (argc != 2)
    {
        printf("Invalid input. \n");
        return (1);
    }

    // Open memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create buffer for file
    uint8_t buffer[512];

    // set a destination file
    int file_count = 0;
    FILE *img = NULL;
    char filename[8];

    // writing the file into .jpg file
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
        // Check that buffer starts with 0xff 0xd8 0xff
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 &&
            buffer[3] <= 0xef)
        {
            // close previous file
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new filename and open new image file
            sprintf(filename, "%03i.jpg", file_count++);
            img = fopen(filename, "w");
        }

        // If found a JPEG
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
    return (0);
}
