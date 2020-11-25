#ifndef SHELL_H
#define SHELL_H

#define BUFFSIZE 64
#define DELIMS "\a\t\r\n\\"

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

char *userInput(void);
char **strTokens(char *input);
int forkPid(char **starts);
void sish(void);

#endif /*SHELL_H*/
