#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

// index = 0.0588 * L - 0.296 * S - 15.8

int letters_count(string text)
{
    int count = 0;
    int letter_count = 0;

    while (text[count] != '\0')
    {
        if ((text[count] >= 'A' && text[count] <= 'Z') ||
            (text[count] >= 'a' && text[count] <= 'z'))
            letter_count++;
        count++;
    }
    return (letter_count);
}

int word_count(string text)
{
    int count = 0;
    int word_count = 0;

    while (text[count] != '\0')
    {
        if (isspace(text[count]))
            word_count++;
        count++;
    }
    word_count += 1;
    return (word_count);
}

int sentence_count(string text)
{
    int count = 0;
    int stop_count = 0;

    while (text[count] != '\0')
    {
        if (text[count] == '.' || text[count] == '!' || text[count] == '?')
            stop_count++;
        count++;
    }
    return (stop_count);
}

int main(void)
{
    // Get input of text
    string input = get_string("Text input: ");
    // Count the number of letters in total. Divide by 100 to get L
    int letter = letters_count(input);

    // Count the number of words
    int word = word_count(input);

    // Count the number of sentences (.) Divide by 100 to get S
    int sentence = sentence_count(input);

    // Calculate the index
    float L = (float) letter / word * 100;
    float S = (float) sentence / word * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print output
    /*     printf("letter: %i\n", letter);
        printf("word: %i\n", word);
        printf("sentence: %i\n", sentence);
        printf("index: %i\n", index); */
    if (index >= 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n", (int) round(index));
}
