#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    //printf("Your name: ");
    string name = GetString();
    //string name = "   robert   thomas bowden ";
    bool check = false; 
    
    for (int i = 0, s = strlen(name); i < s; i++)
    {        
            
        if (! isspace(name[i]) && ! check) {
            printf("%c", (char) toupper(name[i]));
            check = true;
        }
        
        if (isspace(name[i]))
            check = false;


    }
    
    printf("\n");
    
    return 0;
}
