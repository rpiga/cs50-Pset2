/**
 * RickRoll'd 
 * by Roberto Piga
 * 
 * with a small help from Zamyla
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, string argv[])
{
    // check one single arg is provided
    if (argc != 2 || argv[1] < 0)
    {
        printf("Ouch!\n");
        return 1;
    }
    
    // now check number is a positive int
    int k = atoi(argv[1]);
    
    if (k < 1)
    {
        printf("Please, enter a positive integer.\n");
        return 1;
    }
    else
    {
        // Normalize if > 26
        k %= 26;
    }
    
    // Get an input string
    string message = GetString();
    
    char c, start;
    
    // Print encrypted message
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        c = message[i];
        //printf("--%c\n", c);
        
        if (isalpha(c))
        {
            start = isupper (c) ? 'A' : 'a';
            printf("%c", start + (c - start + k)%26);
        }
        else
            printf("%c", c);
    }
    
    
    printf("\n");
    return 0;
}