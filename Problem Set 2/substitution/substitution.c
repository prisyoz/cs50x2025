#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

char ALPHA[] = "abcdefghijklmnopqrstuvwxyz";

int is_valid(string key)
{
    int count = 0;
    int dup1 = 0;
    int dup2 = 0;

    // check contains 26 characters
    int key_len = strlen(key);
    if (key_len != 26)
    {
        return (1);
    }

    // check contains only alphabets
    while (key[count] != '\0')
    {
        if (!isalpha(key[count]))
        {
            return (1);
        }
        count++;
    }

    // Check each letter only appears once
    while (key[dup1] != '\0')
    {
        dup2 = dup1 + 1;
        while (key[dup2] != '\0')
        {
            if (tolower(key[dup1]) == tolower(key[dup2]))
            {
                return (1);
            }
            dup2++;
        }
        dup1++;
    }
    return (0);
}

string conversion(string key, string text)
{
    int count = 0;
    int index;
    static char ctext[1000];

    while (text[count] != '\0')
    {
        if (isalpha(text[count]))
        {
            // In alphabet - check which index the plaintext character is in.
            index = tolower(text[count]) - 'a';
            // Match the index against the key[index]
            ctext[count] = key[index];
            // check if the plain text is upper - yes convert to upper
            if (isupper(text[count]))
                ctext[count] = toupper(ctext[count]);
            else
                ctext[count] = tolower(ctext[count]);
        }
        else
            ctext[count] = text[count];
        count++;
    }
    return (ctext);
}

int main(int argc, string argv[])
{
    // Check for input.
    // Less than 2 argument - return (1)
    if (argc < 2)
    {
        printf("No input\n");
        return (1);
    }

    // More than 2 argument - return (1)
    else if (argc > 2)
    {
        printf("Too much input\n");
        return (1);
    }

    // only 1 argument
    // Check that key in valid (contains 26 characters. contains only alphabets, each letter only
    // appears once) - else return 1
    int key = is_valid(argv[1]);
    if (key == 1)
    {
        printf("Invalid key\n");
        return (1);
    }

    // Prompt for plaintext
    string ptext = get_string("plaintext: ");

    // Conversion happens (Preserve cases)
    string ctext = conversion(argv[1], ptext);

    // Output ciphertext - return \n, (0)
    printf("ciphertext: %s\n", ctext);
    return (0);
}
