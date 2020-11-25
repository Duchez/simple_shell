#include "shell.h"
/**
 * strTokens - breaks a string into char parts
 * @input: user input from stdin
 * Return: char parts or tokens
 */
char **strTokens(char *input)
{
        int buffer = BUFFSIZE;
        int iter = 0;
        char **parts = malloc(buffer * sizeof(char*));
        char *tokptr;

        if (!parts)
        {
                fprintf(stderr, "error in setting\n");
                exit(EXIT_SUCCESS);
        }

        tokptr = strtok(input, DELIMS);
        while (!tokptr)
        {
                parts[iter] = tokptr;
                iter++;

                if (iter >= buffer)
                {
                        buffer += BUFFSIZE;
                        parts = realloc(parts, buffer * sizeof(char*));

                        if (!parts)
                        {
                                fprintf(stderr, "error in setting\n");
                                exit(EXIT_FAILURE);
                        }
                }

                tokptr = strtok(NULL, DELIMS);
        }
        parts[iter] = NULL;
        return (parts);
}
