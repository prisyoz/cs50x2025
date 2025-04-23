#include <cs50.h>
#include <stdio.h>

void print_row(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // Print spaces
        for (int j = 1; j <= height - i; j++)
        {
            printf(" ");
        }
        // Print bricks (hashes)
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}

int main()
{
    int height;
    int get_height;

    while (1)
    {
        printf("Enter height: ");
        get_height = scanf("%d", &height);

        if (get_height == 1 && height > 0)
        {
            break;
        }
        else
        {
            while (getchar() != '\n');

            if (get_height == 0)
            {
                printf("No input detected. Please enter a positive integer for the height.\n");
            }
            else
            {
                printf("Invalid input. Please enter a positive integer for the height.\n");
            }
        }
    }

    // Print the pyramid
    print_row(height);
    return 0;
}
