#include "shell.h"

/**
 * execute - Forks a child process and executes a new process
 * @args: user input array arguments
 * Return:  0 or 1 according file program execution
 */
int execute(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid < 0)
		exit(1);
	else if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			exit(127);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && status != 0)
			exit(WEXITSTATUS(status));
	}
	return (0);
}

/**
 * _getenv - Search in environment variable to find a specific variable name
 * @name: environment variable
 * Return: pointer to the corresponding value string
 */
char *_getenv(char *name)

{
	int index = 0;

	while (environ[index])
	{
		if (_strncmp(environ[index], name, _strlen(name)) == 0)
			return (environ[index] + (_strlen(name) + 1));

		++index;
	}
	return (NULL);
}


/**
 * init_fileprogram - Execute local programs, redirect simple commands.
 * @args: user input array arguments
 * Return: 0 on success, 1 on failure
 */

int init_fileprogram(char **args)
{
	struct stat sb;

	if (stat(args[0], &sb) == 0 && access(args[0], X_OK) == 0)
	{
		execute(args);
		return (0);

	}
	getpathfile(args);

	if (stat(args[0], &sb) == -1)
		return (-1);

	return (execute(args));
}

/**
  * searchdir - Searches in the PATH directory and append the file program to
  * the path according status return
  * @directories: pointer array to all the directories in the PATH
  * @args: user input array arguments
  * Return: 0 on success, -1 on failure
  */

int searchdir(char **directories, char **args)
{
	char *cwd;
	int i;
	struct stat sb;

	cwd = getcwd(NULL, 0);

	for (i = 0; directories[i] != NULL; i++)
	{
		chdir(directories[i]);
		if (stat(args[0], &sb) == 0)
		{
			args[0] = path_append(directories[i], args[0]);
			if (args[0] == NULL)
			{
				free_function(1, cwd);
				free_function(2, directories);
				return (-1);
			}
			break;
		}
	}
	chdir(cwd);
	free_function(1, cwd);
	if (directories[i] == NULL)
	{
		free_function(2, directories);
		return (-1);
	}
	free_function(2, directories);
	return (0);
}
