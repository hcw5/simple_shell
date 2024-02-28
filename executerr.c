#include "shell.h"

/**
 * execute_command - Command executer
 * @argv: An array of strings (tokenizeid command line)
 * Return: Nothing
 */
void execute_command(char **argv)
{
	char *fullPath;

	if (access(argv[0], F_OK) == 0 && access(argv[0], X_OK) == 0)
	{
		fork_and_execute(argv);
	}
	else
	{
		fullPath = handle_path("PATH", argv[0]);
		if (fullPath == NULL)
		{
			printError("Failed to get full path");
		}
		else
		{
			if (access(fullPath, F_OK) == 0 && access(fullPath, X_OK) == 0)
			{
				free(argv[0]);
				argv[0] = fullPath;
				fork_and_execute(argv);
			}
			else
			{
				printError("Access denied for full path");
				free(fullPath);
			}
		}
	}
}

/**
 * fork_and_execute - executes a command as achild process
 * @argv: argument vector
 * Return: Nothing
 */
void fork_and_execute(char **argv)
{
	pid_t pid;
	int wstatus;

	pid = fork();

	if (pid == -1)
	{
		printError("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&wstatus);
	}
}
