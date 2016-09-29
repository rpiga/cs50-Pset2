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
    
    string k = argv[1];
    
    // check input string is only made of alphabetical chars
    int c = 0, lk = strlen(k);
    
    do
    {
        if (! isalpha(k[c]))
        {
            printf("Insert only aplhabetic chars as keyword (a-z).\n");
            return 1;
        }
        
        c++;
    }
    while(c < lk);
    
    
    // Get an input string
    string p = GetString();
    
    // Print encrypted message
    int lp = strlen(p), ck = 0;
    c = 0;
    char m, start, ki;
    
    // Encrypt the input
    do
    {
        // set the c-th char from p to m
        m = p[c];
        
        // if it is an alphabetic char, then encrpt
        if (isalpha(m))
        {
            ki = toupper(k[ck]) - 'A';

            start = isupper (m) ? 'A' : 'a';
            printf("%c", start + (m - start + (int) ki)%26);
            
            ck = (ck + 1) % lk;
        }
        else
            printf("%c", m);
        
        c++;   
    }
    while (c < lp);
    
    printf("\n");
    return 0;
}