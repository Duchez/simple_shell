#include "commands.h"
/**
 * cdir - shell command to change directory
 * @ptr: array of arguments
 * Return: Always 1
 */

int cdir(char **argv)
{
        if (argv[1] == NULL)
        {
                fprintf(stderr, "cdir missing argument\n");
        }
        else 
        {
                if (chdir(argv[1]) != 0)
                {
                        perror("sish");
                }
        }
        return (1);
}
