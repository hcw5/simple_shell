#include "shell.h"

/**
 * copyArrayOfStrings - makes a copy of the null terminated array of strings
 * @argv: A null-terminated array of strings
 * Return: A pointer to the the copied array
 */
char **copyArrayOfStrings(char **argv)
{
	int i, j;

	char **copyOfArgv;

	copyOfArgv = malloc((lenOfArray(argv) + 1) * sizeof(char *));
	if (copyOfArgv == NULL)
	{
		_puts("copyArrayOfStrings(): malloc failed.");
		return (NULL);
	}

	for (i = 0; argv[i] != NULL; i++)
	{
		copyOfArgv[i] = _strdup(argv[i]);
		if (copyOfArgv[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(copyOfArgv[j]);
			}
			free(copyOfArgv);
			_puts("copyArrayOfStrings(): malloc failed\n");
			return (NULL);
		}
	}
	copyOfArgv[i] = NULL;

	return (copyOfArgv);
}
