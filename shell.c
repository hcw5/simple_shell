#include "shell.h"

/**
 * display_prompt - Display cmd prompt
 *
 * Return: Nothing
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_puts("($) ");
		fflush(stdout);
	}
}

/**
 * read_commandline - read cmd  input
 *
 * Return: Nothing
 */
char *read_commandline(void)
{
	char *lineptr = NULL;
	size_t n, len;
	ssize_t ret;

	n = 0;
	ret = getline(&lineptr, &n, stdin);
	if (ret == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	len = _strlen(lineptr);
	if (len > 0 && lineptr[len - 1] == '\n')
	{
		lineptr[strlen(lineptr) - 1] = '\0';
	}

	return (lineptr);
}

/**
 * printError - print error message
 * Return: Nothing
 */
void printError(char *str)
{
	_puts("hsh: ");
	perror(str);
}

/**
 * main - main entry point
 *
 * Return: 0
 */
int main(void)
{
	char *command;
	char *delimiter = " \t\n";
	char **argv;

	while (1)
	{
		display_prompt();

		command = read_commandline();
		if (_strcmp(command, "exit") == 0)
		{
			free(command);
			exit(EXIT_SUCCESS);
		}
		else
		{
			argv = toknize(command, delimiter);
			if (argv == NULL)
			{
				/* Handle toknization failure */
				free(command);
				continue;
			}

			execute_command(argv);

			free(command);
			freeArrayOfStrings(argv);
		}
	}

	exit(EXIT_SUCCESS);
}
