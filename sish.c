#include "shell.h"
/**
 * sish - launches a shell and asks the user for input
 * Return: void
 */

void sish(void)
{
        int current;
        char **parts;
        char *input;

        do {
                printf("$ ");
                input = userInput();
                parts = strTokens(input);
                //current = 
        } while (current);
}
