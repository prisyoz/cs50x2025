#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // Check for usage
    if (argc != 2)
    {
        printf("Please provide only one filename\n");
        return (1);
    }

    // Open file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return (1);
    }

    // Create buffer for file
    uint8_t buffer[4];

    // Create an array of signature bytes
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    // Ready first 4 bytes from file
    fread(buffer, sizeof(uint8_t), 4, input);

    // check the first 4 bytes again signature bytes
    for (int i = 0; i < 4; i++)
    {
        if (signature[i] != buffer[i])
        {
            printf("This is not a PDF!\n");
            return (0);
        }
    }

    // Success!
    printf("This is a PDF!\n");

    // Close file
    fclose(input);

    return (0);
}
