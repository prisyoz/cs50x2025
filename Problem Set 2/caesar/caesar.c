#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(string k)
{
    int count = 0;

    while (k[count] != '\0')
    {
        if (k[count] < '0' || k[count] > '9')
            return (1);
        count++;
    }
    return (0);
}

string conversion(string key, string ptext)
{
    int count = 0;
    char c;
    static char ctext[1000];
    int k;

    // convert string to int
    k = atol(key);
    // Make sure that key is less than 26
    k = k % 26;

    while (ptext[count] != '\0')
    {
        c = ptext[count];
        if (isupper(c))
        {
            c = (c - 'A' + k) % 26 + 'A';
        }
        if (islower(c))
        {
            c = (c - 'a' + k) % 26 + 'a';
        }
        ctext[count] = c;
        count++;
    }
    ctext[count] = '\0';
    return (ctext);
}

int main(int argc, string argv[])
{
    // User needs to input key (unsigned long)
    // If no key, print no key. return 1
    if (argc < 2)
    {
        printf("No Key\n");
        return (1);
    }

    // If more than 1 key, print too many keys. return 1
    else if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }

    // If got key, check if its numbers
    int k = only_digits(argv[1]);
    if (k == 1)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    // input plain text with 2 spaces
    string ptext = get_string("Plain text:  ");

    // start conversion
    string ctext = conversion(argv[1], ptext);

    // Output cipher text with 2 spaces
    printf("ciphertext: %s\n", ctext);

    return (0);
}
