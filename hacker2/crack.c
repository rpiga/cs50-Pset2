/*
*
*
andi:HALRCq0IBXEPM
caesar:50zPJlUFIYY0o
eli:50MxVjGD7EfY6
hdan:50z2Htq2DN2qs
jason:50CMVwEqJXRUY
john:50TGdEyijNDNY
levatich:50QykIulIPuKI
rob:50q.zrL5e0Sak
skroob:50Bpa7n/23iug
zamyla:HAYRs6vZAb4wo
*
*/

#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <crypt.h>

#define _XOPEN_SOURCE
/*
#include <stdlib.h>
#include <math.h>
*/

// Prototypes
char *get_salt(char *p);



int main(int argc, string argv[])
{
    // To substitute with argv check
    //char *p = "HALRCq0IBXEPM";
    //char *p = "50Bpa7n/23iug";
    
    if (argc != 2)
    {
        printf("Ouch!\n");
        return 1;
    }    
    
    char *p = argv[1];
    printf("%s\n", p);

    // look for the first two chars (salt)
    char *salt = get_salt(p);
    if (!salt)
    {
        printf("ERROR salt not found.\n");
        return 1;
    }
    
    printf("Salt: %s\n", salt);

    // Begin the brute force attack.
    
    // Open file with word list
    FILE *wlist = fopen("/usr/share/dict/words", "r");
//    FILE* wlist = fopen("dict_lite", "r");
    char buf[100];
    
    if (wlist == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }

//    int progress = 5;
    char *password;
    
    printf("Brute forcing with word list. Please, wait.\n");
    int foundit = 0;
    
	while (fgets(buf,100, wlist) != NULL) 
	{
	    char word[strlen(buf)];
	    strncpy(word, buf, strlen(buf)-1);
        word[strlen(buf)-1] = '\0';
        password = crypt (word, salt);
        
        int rc = strcmp(p, password);
        if (rc == 0)
        {
            printf("Found >>> %s\n", buf);
            foundit = 1;
            break;
        }
	}

    if ( foundit == 0) {
        printf("Brute forcing with numbers. Please, wait.\n");
        
        
        
        //printf("\nDEBUG: %lu\n", sizeof(bfnum));
        char buffer[8];
        
        for (int i = 0; i < 99999999; i++)
        {
            sprintf(buffer, "%d", i);
            password = crypt (buffer, salt);

            int rc = strcmp(p, password);
            if (rc == 0)
            {
                printf("Found >>> %s\n", buffer);
                foundit = 1;
                break;
            }
        }
    }

    // close file
    fclose(wlist);

    // THE END.
    
    // free memory heap occupied with malloc(s)
    free(salt);
    
    printf("\n");
    return 0;
}

char *get_salt(char *p) 
{
    char *salt = malloc( sizeof(char) * 3);
    if (!salt)
        return NULL;    // In case no memory available, returns NULL
        
    int i;
    
    for (i = 0; i < 2; i++)
        salt[i] = p[i];
    salt[i + 1] = '\0';
    
    return salt;
}
