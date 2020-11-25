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
<<<<<<< HEAD
char *inargv(FILE *filestr, size_t s);

#endif
=======
int forkPid(char **starts);
void sish(void);

#endif /*SHELL_H*/
>>>>>>> 4a3183c0aed1b23643d6ad46d74137a20a2795be
