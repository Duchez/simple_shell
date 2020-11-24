#include "shell.h"
/**
 * userInput - reads user input from stdin
 * Return: line
 */

char *userInput(void)
{
        char *input = NULL;
        size_t len = 0;

        if (getline(&input, &len, stdin) == -1)
        {
                if (feof(stdin))
                        exit(EXIT_SUCCESS);
                else
                {
                        perror("reading input");
                        exit(EXIT_FAILURE);
                }
        }

        return (input);
}
