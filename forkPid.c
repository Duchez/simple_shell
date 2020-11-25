#include "shell.h"
/**
 * forkPid - starts the shell processes by fork and exec
 * @starts: string of processes
 * Return: Always 1 on success
 */
int forkPid(char **starts)
{
        int swch;
        pid_t pid, waitPID;

        pid = fork();

        if (pid == 0)
        {
                if (execvp(starts[0], starts) == -1)
                        perror("sish");
                exit(EXIT_FAILURE);
        }else if (pid < 0)
        {
                perror("sish");
        }else
        {
                do
                {
                        waitPID = waitpid(pid, &swch, WUNTRACED);
                }while (!WIFEXITED(swch) && !WIFSIGNALED(swch));
        }
        return (1);
}
