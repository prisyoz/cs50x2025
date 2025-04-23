#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score(string word)
{
    int count = 0;
    int index = 0;
    int score = 0;

    // Compute and return score for word
    while (word[count] != '\0')
    {
        // If uppercase
        if (isupper(word[count]))
        {
            index = word[count] - 'A';
            score += POINTS[index];
        }
        else if (islower(word[count]))
        {
            index = word[count] - 'a';
            score += POINTS[index];
        }
        count++;
    }
    return (score);
}

int main(void)
{

    // Prompt player 1 for input
    string word1 = get_string("Player 1: ");
    // Prompt player 2 for input
    string word2 = get_string("Player 2: ");

    // Calculate and compare the words
    int wdcount1 = score(word1);
    int wdcount2 = score(word2);

    // If player 1 > player 2, player 1 wins
    if (wdcount1 > wdcount2)
        printf("Player 1 wins!\n");

    // If player 1 < player 2, player 2 wins
    else if (wdcount1 < wdcount2)
        printf("Player 2 wins!\n");
    // Else tie
    else
        printf("Tie!\n");
}
